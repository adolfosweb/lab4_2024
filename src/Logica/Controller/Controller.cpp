#include "Controller.h"
#include "../dto/DTOEstudiante.h"
#include "../dto/DTOUsuario.h"
#include "../dto/DTOProfesor.h"
#include "../dominio/Estudiante.h"
#include "../dominio/Profesor.h"
#include "../dominio/Usuario.h"
#include <set>

Controller::Controller() {
	//obtendo la unica instancia del Sistema
	this->sistema = Sistema::getInstance();
}

bool Controller::verificarNick(string nick) {
	//recorro los usuarios del sistema
	bool result = false;

	set<Usuario*>::iterator it;

	for (it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) {
		if (nick == (*it)->getNick()) {
			result = true;
			break;
		}
	}
	return result;
}

set<string> Controller::listIdiomas() {
	//recorro los idiomas del sistema y retorno una set de string
	set<string> result;

	set<Idioma*>::iterator it;
	for (it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
		result.insert((*it)->getIdioma());
	}
	return result;
}

void Controller::agregarUsuario(DTOUsuario* usuario) {
	Usuario *nuevoUsuario;
	DTOEstudiante* dtoEst = dynamic_cast<DTOEstudiante*>(usuario);
	//hago un casting para determinar el tipo de instancia
	if (dtoEst != nullptr) {
		//es un estudiante
		nuevoUsuario = new Estudiante(dtoEst->getNick(), dtoEst->getPass(),dtoEst->getNom(), dtoEst->getDescripcion(), dtoEst->getPaisResidencia(),dtoEst->getFecha());
	} else {
		DTOProfesor* dtoProf = dynamic_cast<DTOProfesor*>(usuario);

		//si no es un estudiante asumo que es un profesor
		nuevoUsuario = new Profesor(dtoProf->getNick(), dtoProf->getPass(), dtoProf->getNom(), dtoProf->getDescripcion(), dtoProf->getInstituto());

		//recorro la lista de idiomas del DTO enviado
		set<string>::iterator it;
		set<string> ListaIdiomaDTO= dtoProf->getIdiomas();
		for (it = ListaIdiomaDTO.begin(); it != ListaIdiomaDTO.end(); it++) {
			Idioma* idioma = this->sistema->buscarIdioma((*it));

			(dynamic_cast<Profesor*>(nuevoUsuario))->agregarIdioma((idioma));

		}
	}

	this->sistema->usuarios.insert(nuevoUsuario);
}

