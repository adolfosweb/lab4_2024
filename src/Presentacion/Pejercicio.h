#ifndef PRESENTACION_PEJERCICIO_H_
#define PRESENTACION_PEJERCICIO_H_
#include "../Logica/Controller/Interface.h"
#include "../Logica/Dto/DTOEjercicio.h"
#include <map>
class PEjercicio
{
private:

   Interface *SystemInstance;

public:
   
    PEjercicio();
    ~PEjercicio(); 
    //CU12 realizarEjercicio
    void realizarEjercicio();

    
};


    

#endif /* PCURSO_H_*/