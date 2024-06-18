#include "AltaIdioma.h"
#include "../Logica/Controller/Controller.h"
#include <iostream>

AltaIdioma::AltaIdioma(){
    this->iusuario = new Controller();
}
AltaIdioma::~AltaIdioma() {
	//El controlador solo dura lo que dura el caso de uso
	delete this->iusuario;
}
void AltaIdioma::altaIidoma(){
    string idioma;
	cout << "Ingrese Idioma:"<< endl;
	cin >> idioma;

    this->iusuario->altaIdioma(idioma);

}