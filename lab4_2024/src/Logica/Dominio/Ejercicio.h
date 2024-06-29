#ifndef LOGICA_EJERCICIO_H_
#define LOGICA_EJERCICIO_H_

#include <iostream>

using namespace std;

class Ejercicio
{
private:
    string descripcion;
    bool aprobado;
public:
    Ejercicio();
    Ejercicio(string descripcion,bool aprobado);
    ~Ejercicio();
    string getDescripcion();
    bool getAprobado();
};



#endif /*LOGICA_EJERCICIO_H_*/