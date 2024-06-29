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
#include "../Dto/DTOEjercicio.h"
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
	void altaCurso(string nombre,string descripcion, string idioma,string nombreProf, ENUMDificultad dificultad, bool habilitado,set<string> previa);
	set<string> listoProfesor();
	set<string> listaCursos();
	set<string> idiomasProfesor(string nick);

	//CU 6 Agregar Leccion
	map<int,DTOCurso> ConsultaCursosNoHabilitados();
	bool IngresoLeccion(DTOCurso curso, DTOLeccion leccion);

	//CU 7 Agregar Ejercicio
	map<DTOCurso,int> listarCursosNoHab();
	set<DTOLeccion> listarLecciones(DTOCurso);
	bool ingresarEjercicioPalabra(DTOCurso c, DTOLeccion l, DTOEjercicio e);
	bool ingresarEjercicioTraduccion(DTOCurso c, DTOLeccion l, DTOEjercicio e);

	//CU 8 Habilitar Curso
	void habilitarCurso(string nombreCurso);

	//CU 13 Consultar estadísticas
	void listarEstudiantes();
	void consultarStatsEstudiante(string nick);
	void consultarStatsProfesor(string nick);
	map<int,DTOCurso> ConsultaCursosHabilitados();
	float obtenerPromedioCurso(DTOCurso curso);

};

#endif /* NEGOCIO_CONTROLLER_IUSUARIOCONTROLLER_H_ */
