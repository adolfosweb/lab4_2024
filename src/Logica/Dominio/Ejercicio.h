#ifndef LOGICA_EJERCICIO_H_
#define LOGICA_EJERCICIO_H_

#include <iostream>

using namespace std;

class Ejercicio
{
private:
    string descripcion;
public:
    Ejercicio();
     Ejercicio(string descripcion);

    ~Ejercicio();

    string getDescripcion();
};



#endif /*LOGICA_EJERCICIO_H_*/