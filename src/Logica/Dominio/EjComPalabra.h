#ifndef LOGICA_EJCOMPALABRA_H_
#define LOGICA_EJCOMPALABRA_H_
#include "Ejercicio.h"
#include <iostream>
using namespace std;

class EjComPalabra{
private:
    string frase;
    string respuesta;
public:
    EjComPalabra();
    EjComPalabra(string descripcion, string frase, string respuesta);
    ~EjComPalabra();
    string getFrase();
    string getRespuesta();
};



#endif /*LOGICA_EJCOMPALABRA_H_*/