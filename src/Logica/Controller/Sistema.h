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
#include "../Dominio/Curso.h"

using namespace std;

//Esto es un singleton (ver patron de diseño)

class Sistema {
private:
	Sistema(); //declaro el constructor como privado
	static Sistema* miSistema;	//puntero a la unica intancia de Controller
	void inicializarDatos();
public:
	//Esta es una clase utilitaria por lo que no tiene sentido encapsular su estado
	//(no utilizo getters y setters)

	set<Usuario*> usuarios;
	set<Idioma*> idiomas;
	//set<Curso*> Curso;

	
	Idioma* buscarIdioma(string nomIdioma);
	static Sistema* getInstance(); //metodo de clase que devuele siempre la misma instancia
	virtual ~Sistema();
};

#endif /* CONTROLLER_SISTEMA_CPP_ */
