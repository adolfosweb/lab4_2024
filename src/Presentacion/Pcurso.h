#ifndef PRESENTACION_PCURSO_H_
#define PRESENTACION_PCURSO_H_
#include "../src/Logica/Controller/Interface.h"
#include "../src/Logica/Dto/DTOCurso.h"
class PCurso
{
private:

   Interface *SystemInstance;

public:
   
    PCurso();
    ~PCurso(); 
    //CU5 Alta Curso
    void altaCurso();
    //CU6 Agregar Ejercicio
    void AgregarEjercicio();

};


    

#endif /* PCURSO_H_*/