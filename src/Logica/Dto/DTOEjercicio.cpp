#include "DTOEjercicio.h"

DTOEjercicio::DTOEjercicio(string descripcion, string frase, string solucion){
    this->descripcion = descripcion;
    this->frase = frase;
    this->solucion = solucion;
}

DTOEjercicio::~DTOEjercicio(){

}

string DTOEjercicio::getDescripcion(){
    return this->descripcion;
}

string DTOEjercicio::getFrase(){
    return this->frase;
}

string DTOEjercicio::getSolucion(){
    return this->solucion;
}

ENUMTipo DTOEjercicio::getTipo(){
    return this->tipo;
}