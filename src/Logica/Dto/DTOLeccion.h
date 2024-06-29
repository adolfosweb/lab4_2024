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
     int getNumero() const;
     string getTema() const;
     string getObjetivoAprendizaje() const;
    ~DTOLeccion();

    //Evitar error no match for operator<
    bool operator<(const DTOLeccion& l) const;
};


#endif /*LOGICA_DTO_DTOLECCION_H_*/