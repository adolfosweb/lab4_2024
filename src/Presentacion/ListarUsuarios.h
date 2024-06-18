#ifndef LISTARUSUARIOS_H_
#define LISTARUSUARIOS_H_
#include "../src/Logica/Controller/Interface.h"
#include "../src/Logica/Dto/DTOProfesor.h"
#include "../src/Logica/Dto/DTOEstudiante.h"


class ListarUsuarios {
private:
	Interface* iusuario;

public:
	ListarUsuarios();
	virtual ~ListarUsuarios();
	void listadoUsuarios();
};

#endif /* LISTARUSUARIOS_H_ */