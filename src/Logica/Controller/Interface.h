#ifndef LOGICA_CONTROLLER_INTERFACE_H_
#define LOGICA_CONTROLLER_INTERFACE_H_
#include <iostream>
#include <set>
#include "../Dto/DTOUsuario.h"

// Esta es una iterface del Sistema.

class Interface {
public:

	virtual bool verificarNick(string nick)=0;
	virtual void agregarUsuario(DTOUsuario* usuario)=0;
    virtual set<string> listIdiomas()=0;
	virtual void listadoUsuarios()=0;


	//Caso de uso Alta idioma
	
	virtual void altaIdioma(string idioma)=0;
};

#endif /* LOGICA_CONTROLLER_INTERFACE_H_ */