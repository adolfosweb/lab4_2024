#ifndef LOGICA_CONTROLLER_INTERFACE_H_
#define LOGICA_CONTROLLER_INTERFACE_H_
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

// Esta es una iterface del Sistema.

class Interface {
public:

	virtual bool verificarNick(string nick)=0;
	virtual void agregarUsuario(DTOUsuario* usuario)=0;
    virtual set<string> listIdiomas()=0;
	//CU 2 Consulta de usuario
	virtual set<string> listadoUsuarios()=0;
	virtual bool esEstudiante(string nick)=0;
	virtual DTOEstudiante infoEstudiante(string nick)=0;
	virtual DTOProfesor infoProfesor(string nick)=0;
	//Fin CU2

	//Caso de uso Alta idioma
	virtual void altaIdioma(string idioma)=0;

	//CU 4 Concultar Idioma
	virtual set<string> consultarIdioma()=0;
	//CU 5 Alta Curso
	virtual void altaCurso(string nombre,string descripcion, string idioma,string nombreProf, ENUMDificultad dificultad, bool habilitado,set<string> previa)=0;
	virtual set<string> listoProfesor()=0;
	virtual set<string> listaCursos()=0;
	virtual set<string> idiomasProfesor(string nick)=0;

	//CU 6 Agregar Leccion
	virtual map<int,DTOCurso> ConsultaCursosNoHabilitados() = 0;
	virtual bool IngresoLeccion(DTOCurso curso,DTOLeccion leccion) = 0;

	//CU 7 Agregar Ejercicio
	virtual set<DTOLeccion> listarLecciones(string nombreCurso)=0;
	virtual bool ingresarEjercicioPalabra(DTOCurso c, DTOLeccion l, DTOEjercicio e)=0;
	virtual bool ingresarEjercicioTraduccion(DTOCurso c, DTOLeccion l, DTOEjercicio e)=0;

	//CU 8 Habilitar Curso
	virtual void habilitarCurso(string nombreCurso)=0;
	//CU 11 Inscribirse a curso
	virtual bool Inscribir(string nombreCurs,string nombreEst)=0;
	virtual void listoCursosPendientes(string nombreEst)=0;
	//CU 13 Consultar Estadísticas
	virtual int listarUsuarios(int sel) = 0;
	virtual void consultarStatsEstudiante(string nick) = 0;
	virtual void consultarStatsProfesor(string nick) = 0;
	virtual map<int,DTOCurso> ConsultaCursosHabilitados() = 0;
	virtual float obtenerPromedioCurso(DTOCurso curso) = 0;

};

#endif /* LOGICA_CONTROLLER_INTERFACE_H_ */