
#include "Leccion.h"

Leccion::Leccion(){
}

Leccion::Leccion(int numero, string tema, string objetivoAprendizaje){
    this->numero=numero;
    this->tema=tema;
    this->objetivoAprendizaje=objetivoAprendizaje;
}

Leccion::~Leccion(){
}

int Leccion::getNumero(){
    return this->numero;
}

string Leccion::getTema(){
    return this->tema;
}

string Leccion::getObjetivoAprendizaje(){
    return this->objetivoAprendizaje;
}
set<Ejercicio*> Leccion:: ObtenerEjercicios()
{
    return Ejercicios;
}