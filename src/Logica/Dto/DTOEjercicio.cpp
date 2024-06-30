#include "DTOEjercicio.h"

DTOEjercicio::DTOEjercicio(string descripcion, string frase,ENUMTipo tipo, string solucion){
    this->descripcion = descripcion;
    this->frase = frase;
    this->solucion = solucion;
    this->tipo=tipo;
}

DTOEjercicio::~DTOEjercicio(){

}

string DTOEjercicio::getDescripcion()const{
    return this->descripcion;
}

string DTOEjercicio::getFrase()const{
    return this->frase;
}

string DTOEjercicio::getSolucion()const{
    return this->solucion;
}

ENUMTipo DTOEjercicio::getTipo() const{
    return this->tipo;
}

bool DTOEjercicio :: operator<(const DTOEjercicio& c) const{
	return true;
}

string DTOEjercicio::tipoToString(ENUMTipo tipo) const{
    switch (tipo) {
        case COMPLETAR:
            return "COMPLETAR";
        case TRADUCCION:
            return "TRADUCCION";
        default:
            return "DESCONOCIDO"; // Manejo de caso por defecto
    }
}