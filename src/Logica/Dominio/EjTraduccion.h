#ifndef LOGICA_EJTRADUCCION_H_
#define LOGICA_EJTRADUCCION_H_

#include <iostream>
#include "Ejercicio.h"
using namespace std;

class EjTraduccion:public Ejercicio{
private:
    string frase;
    string tradduccion;
public:
    EjTraduccion();
    EjTraduccion(string descripcion, string frase, string traduccion);
    ~EjTraduccion();
    string getFrase();
    string getTraduccion();
};



#endif /*LOGICA_EJTRADUCCION_H_*/