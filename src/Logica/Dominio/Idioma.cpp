#include "Idioma.h"

Idioma::Idioma(/* args */)
{
}
Idioma::Idioma(string idioma){
    this->idioma=idioma;
}
Idioma::~Idioma()
{
}

string Idioma::getIdioma(){
    return this->idioma;
}