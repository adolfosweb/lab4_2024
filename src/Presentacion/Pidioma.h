#ifndef PIDIOMA_H_
#define PIDIOMA_H_
#include "../Logica/Controller/Interface.h"
#include "../Logica/Dto/DTOIdioma.h"

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