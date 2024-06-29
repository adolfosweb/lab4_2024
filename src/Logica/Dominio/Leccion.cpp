
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
    return ejercicios;
}

//CU 7 
bool Leccion::ingresarEjercicioPalabra(DTOEjercicio e){
    set<Ejercicio*>::iterator it;
    for (it = this->ejercicios.begin(); it != this->ejercicios.end(); it++){
        if((*it)->getTipo() == COMPLETAR ){
            if(e.getDescripcion() == (*it)->getDescripcion() && e.getFrase() == (*it)->getFrase() && e.getSolucion() == (*it)->getSolucion()){
                return false;
            }
        }
    }
    Ejercicio* ej = new Ejercicio(e.getDescripcion(),e.getFrase(),e.getSolucion(),e.getTipo());
    this->ejercicios.insert(ej);
    return true;
}

bool Leccion::ingresarEjercicioTraduccion(DTOEjercicio e){
    set<Ejercicio*>::iterator it;
    for (it = this->ejercicios.begin(); it != this->ejercicios.end(); it++){
        if((*it)->getTipo() == TRADUCCION ){
            if(e.getDescripcion() == (*it)->getDescripcion() && e.getFrase() == (*it)->getFrase() && e.getSolucion() == (*it)->getSolucion()){
                return false;
            }
        }
    }
    Ejercicio* ej = new Ejercicio(e.getDescripcion(),e.getFrase(),e.getSolucion(),e.getTipo());
    this->ejercicios.insert(ej);
    return true;
}

//CU9
void Leccion::borrarEjercicios(){
    for (auto it = this->ejercicios.begin(); it != this->ejercicios.end(); it++){
        delete *it;
    }
    this->ejercicios.clear();
}