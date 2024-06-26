#include "Controller.h"
#include "../Dto/DTOEstudiante.h"
#include "../Dto/DTOUsuario.h"
#include "../Dto/DTOProfesor.h"
#include "../Dominio/Estudiante.h"
#include "../Dominio/Profesor.h"
#include "../Dominio/Usuario.h"
#include "../Dominio/Idioma.h"
#include "../Dominio/Curso.h"
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


//CU2 Consulta de Usuario
//>ListarUsuarios
set<string>  Controller::listadoUsuarios() {
	//recorro los usuarios del sistema y los cargo en un SET.
	//bool result = false;

	set<string> listaUsuarios;

	set<Usuario*>::iterator it;
	int num = 0;
	for (it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) {
		num = num + 1;
		string nickUsuario;
		nickUsuario += to_string(num);
		nickUsuario += " - ";
		nickUsuario += (*it)->getNick();
		//cout << nickUsuario << endl;
		listaUsuarios.insert(nickUsuario);
		
	}
	return listaUsuarios;
}
//Find listar usuario

// bool esEstudiante(nickUsuario)

// dtoEstudiante consultaDatos(nickName)

// dtoProfesor consultarDatos(nickName)


//CU2 FIN



void Controller::altaIdioma(string idioma){

	bool result = true;
	set<Idioma*>::iterator it;
	for (it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
		
		if (idioma == (*it)->getIdioma()) {
			result = false;
			
			break;
		}
	}
 
	if(result){
		Idioma *I = new Idioma(idioma);

		this->sistema->idiomas.insert(I);
		cout<<"Se a Agregado el Idioma"<<endl;
	}else{
		cout<<"El Idioma ya existia en sistema"<<endl;
	}

}


set<string> Controller::consultarIdioma(){

	set<string> result; // strings que devuelvo a la capa de presentacion

	set<Idioma*>::iterator it;

	for (it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
		string aux=(*it)->getIdioma();
		result.insert(aux);
		}
	return result;

	
}
void Controller::altaCurso(string nombre,string descripcion){

	bool result = true;
	set<Curso*>::iterator it;
	for (it = this->sistema->cursos.begin(); it != this->sistema->cursos.end(); it++) {
		
		if (nombre == (*it)->getNombre()) {
			result = false;
			
			break;
		}
	}
 
	if(result){
		//Curso *C1 = new Curso(nombre,descripcion);
		//this->sistema->cursos.insert(C1);

		cout<<"Se creo el Curso"<<endl;
	}else{
		cout<<"El Curso ya existia en sistema"<<endl;
	}

}
map<int,DTOCurso> Controller :: ConsultaCursosNoHabilitados()
{

	map<int,DTOCurso> CursosNoHab;	//Se crea map vacío.

	int cont = 1;

	for(auto ct = sistema->cursos.begin(); ct != sistema->cursos.end(); ct++ )
	{

		if( ! (*ct)->estaHabilitado()) //Si no está habilitado...
		{
			//Se crea ese DataType con los valores indicados...
			DTOCurso Temp((*ct)->getNombre(),(*ct)->getDescripcion(), (*ct)->getIdioma(), (*ct)->getDificultad(),(*ct)->estaHabilitado());
			//Ingreso al map...
			CursosNoHab.insert({cont,Temp});
			cont ++;
		}

	}

	return CursosNoHab;

}

bool Controller :: IngresoLeccion(DTOCurso curso, DTOLeccion leccion)
{

	for(auto ct = sistema->cursos.begin(); ct != sistema->cursos.end(); ct++ )
	{

		if((*ct)->getNombre() == curso.getNombreCurso() && (*ct)->getDescripcion() == curso.getDescripcion()) //Busca curso...
		{
			(*ct)->setLeccion(leccion);
			return true;
		}
	}
	return false;
}