#ifndef NEGOCIO_CONTROLLER_IUSUARIOCONTROLLER_H_
#define NEGOCIO_CONTROLLER_IUSUARIOCONTROLLER_H_
#include <iostream>
#include <set>
#include <map>
#include "../Dto/DTOUsuario.h"
#include "../Dto/DTOEstudiante.h"
#include "../Dto/DTOProfesor.h"
#include "../Dto/DTOIdioma.h"
#include "../Dto/DTOCurso.h"
#include "../Dto/DTOLeccion.h"
#include "Interface.h"
#include "Sistema.h"

using namespace std;

class Controller:public Interface {
private:
	Sistema* sistema; //cada controlador de la aplicación tiene una instancia de la clase sistema
	//solo existe una instancia de la clase sistema en toda la aplicacion

public:
	Controller();

	bool verificarNick(string nick);
	set<string> listIdiomas();
	void agregarUsuario(DTOUsuario* usuario);

	//CU2 - Consulta de Usuario
	set<string> listadoUsuarios();
	bool esEstudiante(string nick);
	DTOEstudiante infoEstudiante(string nick);
	DTOProfesor infoProfesor(string nick);

	//Caso de uso Alta idioma
	 void altaIdioma(string idioma);

	//CU 4 Consultar Curso
	 set<string> consultarIdioma();
	//CU 5 Alta Curso
	void altaCurso(string nombre,string descripcion, DTOIdioma *idioma, ENUMDificultad dificultad, bool habilitado,string nombreProf,set<string> previa,DTOLeccion nuevaLeccion);
	void listoProfesor();
	set<string> listaCursos();

	//CU 6 Agregar Leccion
	map<int,DTOCurso> ConsultaCursosNoHabilitados();
	bool IngresoLeccion(DTOCurso curso,DTOLeccion leccion);

	//CU 8 Habilitar Curso
	void habilitarCurso(string nombreCurso);
};

#endif /* NEGOCIO_CONTROLLER_IUSUARIOCONTROLLER_H_ */