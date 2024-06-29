#ifndef LOGICA_DTO_DTOLECCION_H_
#define LOGICA_DTO_DTOLECCION_H_

#include <iostream>
using namespace std;

class DTOLeccion{
private:
    int numero;
    string tema;
    string objetivoAprendizaje;
public:
     DTOLeccion();
     DTOLeccion(int numero, string tema, string objetivoAprendizaje);
     int getNumero();
     string getTema();
     string getObjetivoAprendizaje();
    ~DTOLeccion();
};



#endif /*LOGICA_DTO_DTOLECCION_H_*/