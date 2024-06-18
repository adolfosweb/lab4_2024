#ifndef LOGICA_IDIOMA_H_
#define LOGICA_IDIOMA_H_

#include <iostream>

using namespace std;

class Idioma{
private:
    string idioma;
public:
    Idioma();
     Idioma(string idioma);
    ~Idioma();

    string getIdioma();
};



#endif /*LOGICA_IDIOMA_H_*/