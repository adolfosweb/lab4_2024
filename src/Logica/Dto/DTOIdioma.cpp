#include "DTOIdioma.h"
DTOIdioma::DTOIdioma(){}
DTOIdioma::DTOIdioma(string idioma):idioma(idioma){}

DTOIdioma::~DTOIdioma()
{
}

string DTOIdioma::getIdioma() {
    return this->idioma;
}