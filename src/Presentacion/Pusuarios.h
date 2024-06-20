#ifndef PUSUARIOS_H_
#define PUSUARIOS_H_
#include "../src/Logica/Controller/Interface.h"
#include "../src/Logica/Dto/DTOProfesor.h"
#include "../src/Logica/Dto/DTOEstudiante.h"
#include "../src/Logica/Dto/DTOIdioma.h"

class Pusuarios{
private:
   	Interface* iPusuario;
public:
    Pusuarios();

    ~Pusuarios();

    void altaUsuario();

	DTOEstudiante* ingresarEstudiante(string nick);

	DTOProfesor* ingresarProfesor(string nick);
    
	set<string> seleccionarIdiomas();

    //void listadoUsuarios();

    //CU2 - Consulta de Usuario
	void infoUsuario();

};



#endif /* PUSUARIOS_H_ */