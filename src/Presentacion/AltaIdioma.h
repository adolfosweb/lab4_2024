#ifndef ALTAUSUARIO_H_
#define ALTAUSUARIO_H_
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



#endif /* ALTAUSUARIO_H_ */