#ifndef LOGICA_LECCION_H_
#define LOGICA_LECCION_H_

#include <iostream>
using namespace std;

class Leccion{
private:
    int numero;
    string tema;
    string objetivoAprendizaje;
public:
     Leccion();
     Leccion(int numero, string tema, string objetivoAprendizaje);
     int getNumero();
     string getTema();
     string getObjetivoAprendizaje();
    ~Leccion();
};



#endif /*LOGICA_LECCION_H_*/