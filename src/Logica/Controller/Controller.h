/*
 * Controller.h
 */

#ifndef CONTROLLER_SISTEMA_CPP_
#define CONTROLLER_SISTEMA_CPP_
#include <set>
#include "../Dominio/Usuario.h"
#include "../Dominio/Estudiante.h"
#include "../Dominio/Profesor.h"
#include "../Dominio/Idioma.h"

using namespace std;

//Esto es un singleton (ver patron de diseño)

class Controller {
private:
	Controller(); //declaro el constructor como privado
	static Controller* miController;	//puntero a la unica intancia de Controller
	void inicializarDatos();
public:
	//Esta es una clase utilitaria por lo que no tiene sentido encapsular su estado
	//(no utilizo getters y setters)

	set<Usuario*> usuarios;
	set<Idioma*> idiomas;

	static Controller* getInstance(); //metodo de clase que devuele siempre la misma instancia
	virtual ~Controller();
};

#endif /* CONTROLLER_SISTEMA_CPP_ */
