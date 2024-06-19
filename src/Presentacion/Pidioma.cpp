#include "Pidioma.h"
#include "../Logica/Controller/Controller.h"
#include <iostream>

Pidioma::Pidioma(){
    this->pidioma=new Controller();
}

Pidioma::~Pidioma(){
    delete this->pidioma;
}

void Pidioma::altaIidoma(){
    string idioma;
	cout << "Ingrese Idioma:"<< endl;
	cin >> idioma;

    this->pidioma->altaIdioma(idioma);

}

void Pidioma::consultarIdioma(){
    set<string> aux = this->pidioma->consultarIdioma();
    int index=1;
    set<string>::iterator it;
	for (it = aux.begin(); it != aux.end(); it++) {
		cout<< index<<": "<< *it <<endl;
        index++;
	}
}