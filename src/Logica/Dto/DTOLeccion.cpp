#include "DTOLeccion.h"

DTOLeccion::DTOLeccion(){
}

DTOLeccion::DTOLeccion(int numero, string tema, string objetivoAprendizaje){
    this->numero=numero;
    this->tema=tema;
    this->objetivoAprendizaje=objetivoAprendizaje;
}

DTOLeccion::~DTOLeccion(){
}

int DTOLeccion::getNumero() const{
    return this->numero;
}

string DTOLeccion::getTema() const{
    return this->tema;
}

string DTOLeccion::getObjetivoAprendizaje() const{
    return this->objetivoAprendizaje;
}

//Evitar error no match for operator<
bool DTOLeccion :: operator<(const DTOLeccion& l) const{
	return true;
}