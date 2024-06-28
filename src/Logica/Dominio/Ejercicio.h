#ifndef LOGICA_EJERCICIO_H_
#define LOGICA_EJERCICIO_H_

#include <iostream>

using namespace std;

enum ENUMTipo{
    COMPLETAR,TRADUCCION
};

class Ejercicio{
private:
    string descripcion;
    string frase;
    string solucion;
    ENUMTipo tipo;
public:
    Ejercicio(string descripcion, string frase, string solucion, ENUMTipo tipo);
    virtual ~Ejercicio();
    string getDescripcion();
    string getFrase();
    string getSolucion();
    ENUMTipo getTipo();
};



#endif /*LOGICA_EJERCICIO_H_*/