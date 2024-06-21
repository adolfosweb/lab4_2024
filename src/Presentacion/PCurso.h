#ifndef PRESENTACION_PCURSO_H_
#define PRESENTACION_PCURSO_H_
#include "../Logica/Controller/Interface.h"
#include "../Logica/Dto/DTOCurso.h"

class PCurso
{
private:

   Interface *SystemInstance;

public:
   
    PCurso();
    ~PCurso(); 
    
    //CU6 Agregar Ejercicio
    void AgregarEjercicio();
};


    

#endif /* PCURSO_H_*/