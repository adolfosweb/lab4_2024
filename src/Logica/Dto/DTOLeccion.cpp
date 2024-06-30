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
bool DTOLeccion::operator<(const DTOLeccion& l) const {
    return this->numero < l.numero; // Ordenar basado en el número de la lección
}

void DTOLeccion::setEjercicio(set<DTOEjercicio> ejercicio){
    this->ejercicios=ejercicio;
}
set<DTOEjercicio> DTOLeccion::getEjercicio(){
    return this->ejercicios;
}



void DTOLeccion::mostrarEjercicios() const{
    
    if(!this->ejercicios.empty()){
        cout << "lOS Ejercicios de la leccion son: " <<endl;
        set<DTOEjercicio>::iterator it;
        for( it=this->ejercicios.begin(); it!=this->ejercicios.end();it++){
            cout << "Descripcion: " << it->getDescripcion() <<endl;
            cout << "Tipo: " << it->tipoToString(it->getTipo()) <<endl;
        }
    }   
}

void DTOLeccion::setNumero(int num){
    this->numero=num;
}