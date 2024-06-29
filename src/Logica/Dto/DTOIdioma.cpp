#include "DTOIdioma.h"
DTOIdioma::DTOIdioma(){}
DTOIdioma::DTOIdioma(string idioma):idioma(idioma){}

DTOIdioma::~DTOIdioma()
{
}

string DTOIdioma::getIdioma() {
    return this->idioma;
}

/*bool operator==(const DTOIdioma& lhs, const DTOIdioma& rhs) {
        return lhs.idioma == rhs.idioma;
		
}*/