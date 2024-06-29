#ifndef PRESENTACION_PCURSO_H_
#define PRESENTACION_PCURSO_H_
#include "../src/Logica/Controller/Interface.h"
#include "../src/Logica/Dto/DTOCurso.h"
#include <map>
class PCurso
{
private:

   Interface *SystemInstance;

public:
   
    PCurso();
    ~PCurso(); 
    //CU5 Alta Curso
    void altaCurso();
    set<string> seleccionarCursos();
    //CU6 Agregar leccion
    void AgregarLeccion();
    //CU7 Agregar Ejercicio
        
    //CU8 HabilitarCurso
    void habilitarCurso();

    //CU10 ConsultarCurso
    void consultarCurso();

    //CU 13 Consultar estadísticas
    void consultaEstaditicaDeCurso();
    
};


    

#endif /* PCURSO_H_*/