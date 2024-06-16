#ifndef LOGICA_PROFESOR_H_
#define LOGICA_PROFESOR_H_

#include <iostream>
#include "Usuario.h"
using namespace std;

class Profesor :public Usuario{
    private:
        string instituto;
       // list<idioma> idioma;
    public:
    Profesor();
    Profesor(string nick, string pass, string nom,	string descrip, string instituto);
	virtual ~Profesor();
	//void agregarIdioma(Idioma* idioma);
};
#endif /*LOGICA_PROFESOR_H_*/