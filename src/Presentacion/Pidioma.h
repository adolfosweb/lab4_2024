#ifndef PIDIOMA_H_
#define PIDIOMA_H_
#include "../src/Logica/Controller/Interface.h"
#include "../src/Logica/Dto/DTOIdioma.h"

class Pidioma{
private:
   Interface* pidioma;
public:
    Pidioma();
    ~Pidioma();
    
    void altaIidoma();

    //CU 4 CONSULTAR IDIOMA
    void consultarIdioma();
};


    

#endif /* PIDIOMA_H_*/