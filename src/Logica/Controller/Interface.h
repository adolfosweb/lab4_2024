#ifndef LOGICA_CONTROLLER_INTERFACE_H_
#define LOGICA_CONTROLLER_INTERFACE_H_
#include <iostream>
#include <set>
#include "../Dto/DTOUsuario.h"
#include "../Dto/DTOEstudiante.h"
#include "../Dto/DTOIdioma.h"

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
	//Fin CU2

	//Caso de uso Alta idioma
	virtual void altaIdioma(string idioma)=0;

	//CU 4 Concultar Idioma
	virtual set<string> consultarIdioma()=0;
	

};

#endif /* LOGICA_CONTROLLER_INTERFACE_H_ */