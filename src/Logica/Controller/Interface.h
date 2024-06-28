#ifndef LOGICA_CONTROLLER_INTERFACE_H_
#define LOGICA_CONTROLLER_INTERFACE_H_
#include <iostream>
#include <set>
#include <map>
#include "../Dto/DTOUsuario.h"
#include "../Dto/DTOIdioma.h"
#include "../Dto/DTOCurso.h"
#include "../Dto/DTOLeccion.h"

// Esta es una iterface del Sistema.

class Interface {
public:

	virtual bool verificarNick(string nick)=0;
	virtual void agregarUsuario(DTOUsuario* usuario)=0;
    virtual set<string> listIdiomas()=0;
	//CU 2 Consulta de usuario
	virtual set<string> listadoUsuarios()=0;


	//Caso de uso Alta idioma
	virtual void altaIdioma(string idioma)=0;

	//CU 4 Concultar Idioma
	virtual set<string> consultarIdioma()=0;
	//CU 5 Alta Curso
	virtual void altaCurso(string nombre,string descripcion, DTOIdioma *idioma, ENUMDificultad dificultad, bool habilitado,string nombreProf,set<string> previa,DTOLeccion nuevaLeccion)=0;
	virtual void listoProfesor()=0;
	
	virtual set<string> listaCursos()=0;

	//CU 6 Agregar Leccion
	virtual map<int,DTOCurso> ConsultaCursosNoHabilitados() = 0;
	virtual bool IngresoLeccion(DTOCurso curso,DTOLeccion leccion) = 0;
};

#endif /* LOGICA_CONTROLLER_INTERFACE_H_ */