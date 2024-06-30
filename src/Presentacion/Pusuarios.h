#ifndef PUSUARIOS_H_
#define PUSUARIOS_H_
#include "../Logica/Controller/Interface.h"
#include "../Logica/Dto/DTOProfesor.h"
#include "../Logica/Dto/DTOEstudiante.h"
#include "../Logica/Dto/DTOIdioma.h"

class Pusuarios{
private:
   	Interface* iPusuario;
public:
    Pusuarios();

    ~Pusuarios();

    void altaUsuario();
    void cargarDatos();
	DTOEstudiante* ingresarEstudiante(string nick);

	DTOProfesor* ingresarProfesor(string nick);
    
	set<string> seleccionarIdiomas();

    //CU13 Consultar estadísticas 
    void consultaEstudiante();
    void consultaProfesor();

    //void listadoUsuarios();

    //CU2 - Consulta de Usuario
	void infoUsuario();


    

};



#endif /* PUSUARIOS_H_ */