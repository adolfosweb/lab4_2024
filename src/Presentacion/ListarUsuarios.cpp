#include "ListarUsuarios.h"
#include <iostream>
#include <set>
#include "../Logica/Controller/Controller.h"
#include "../Logica/Dto/DTOEstudiante.h"
#include "../Logica/Dto/DTOProfesor.h"
#include "../Logica/Dto/DTOFecha.h"

using namespace std;



ListarUsuarios::ListarUsuarios() {
	//TODO pendiente de usar una fabrica
	this->iusuario = new Controller();
}

ListarUsuarios::~ListarUsuarios() {
	//El controlador solo dura lo que dura el caso de uso
	delete this->iusuario;
}

void ListarUsuarios::listadoUsuarios() {

	cout << "Listado de Usuarios"<< endl;
	this->iusuario->listadoUsuarios();

}

