#include "Ejercicio.h"

Ejercicio::Ejercicio(string descripcion, string frase, string solucion, ENUMTipo tipo){
    this->descripcion = descripcion;
    this->frase = frase;
    this->solucion = solucion;
    this->tipo = tipo;
}

Ejercicio::~Ejercicio(){

}

string Ejercicio::getDescripcion(){
    return this->descripcion;
}

string Ejercicio::getFrase(){
    return this->frase;
}

string Ejercicio::getSolucion(){
    return this->solucion;
}

ENUMTipo Ejercicio::getTipo(){
    return this->tipo;
}