#ifndef LOGICA_DTO_DTOLECCION_H_
#define LOGICA_DTO_DTOLECCION_H_

#include <iostream>
#include "../Dominio/Ejercicio.h"
#include "../Dto/DTOEjercicio.h"
#include <set>
using namespace std;

class DTOLeccion{
private:
    int numero;
    string tema;
    string objetivoAprendizaje;
    set<DTOEjercicio> ejercicios;
public:
     DTOLeccion();
     DTOLeccion(int numero, string tema, string objetivoAprendizaje);
     int getNumero() const;
     string getTema() const;
     string getObjetivoAprendizaje() const;
     void setEjercicio(set<DTOEjercicio> ejercicio);
     set<DTOEjercicio> getEjercicio();
     void setNumero(int num);
    ~DTOLeccion();
     
    void mostrarEjercicios() const;
   
    //Evitar error no match for operator<
    bool operator<(const DTOLeccion& l) const;
};


#endif /*LOGICA_DTO_DTOLECCION_H_*/