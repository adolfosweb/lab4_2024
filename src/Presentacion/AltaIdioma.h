#ifndef ALTAIDIOMA_H_
#define ALTAIDIOMA_H_
#include "../src/Logica/Controller/Interface.h"
#include "../src/Logica/Dto/DTOIdioma.h"
//#include "../src/Logica/Dto/DTOEstudiante.h"

using namespace std;

class AltaIdioma {
private:
   Interface* iusuario;
public:
    AltaIdioma();
    void altaIidoma();
    ~AltaIdioma();
};



#endif /* ALTAIDIOMA_H_ */