#include "DTOEjercicio.h"

DTOEjercicio::DTOEjercicio(string descripcion, string frase,ENUMTipo tipo, string solucion){
    this->descripcion = descripcion;
    this->frase = frase;
    this->solucion = solucion;
    this->tipo=tipo;
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