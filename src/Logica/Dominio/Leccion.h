#ifndef LOGICA_LECCION_H_
#define LOGICA_LECCION_H_

#include <iostream>
#include "../Dominio/Ejercicio.h"
#include "../Dto/DTOEjercicio.h"
#include <set>

using namespace std;

class Leccion{
private:
    int numero;
    string tema;
    string objetivoAprendizaje;
    set<Ejercicio*> ejercicios;

public:
     Leccion();
     Leccion(int numero, string tema, string objetivoAprendizaje);
     int getNumero();
     string getTema();
     string getObjetivoAprendizaje();
    ~Leccion(); 
    set<Ejercicio*> ObtenerEjercicios();

     //CU7
    bool ingresarEjercicioPalabra(DTOEjercicio e);
    bool ingresarEjercicioTraduccion(DTOEjercicio e);

    //CU9
    void borrarEjercicios();
};



#endif /*LOGICA_LECCION_H_*/