#ifndef ALTAUSUARIO_H_
#define ALTAUSUARIO_H_
#include "../src/Logica/controller/Interface.h"
#include "../src/Logica/dto/DTOProfesor.h"
#include "../src/Logica/dto/DTOEstudiante.h"


class AltaUsuario {
private:
	Interface* iusuario;

public:
	AltaUsuario();
	virtual ~AltaUsuario();
	void altaUsuario();
	DTOEstudiante* ingresarEstudiante(string nick);
	DTOProfesor* ingresarProfesor(string nick);
	set<string> seleccionarIdiomas();
};

#endif /* ALTAUSUARIO_H_ */