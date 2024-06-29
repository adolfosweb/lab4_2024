#ifndef LOGICA_LECCION_H_
#define LOGICA_LECCION_H_

#include <iostream>
#include "Ejercicio.h"
#include <set>

using namespace std;

class Leccion{
private:
    int numero;
    string tema;
    string objetivoAprendizaje;
    set<Ejercicio*> Ejercicios;

public:
     Leccion();
     Leccion(int numero, string tema, string objetivoAprendizaje);
     int getNumero();
     string getTema();
     string getObjetivoAprendizaje();
    ~Leccion(); 
    set<Ejercicio*> ObtenerEjercicios();
};



#endif /*LOGICA_LECCION_H_*/