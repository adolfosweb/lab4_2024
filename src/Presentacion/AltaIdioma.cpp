#include "AltaIdioma.h"
#include "../Logica/Controller/Controller.h"
#include <iostream>
AltaIdioma::AltaIdioma(){
    this->iusuario = new Controller();
}
void AltaIdioma::altaIidoma(){
    string idioma;
	cout << "Ingrese Idioma:"<< endl;
	cin >> idioma;

    this->iusuario->altaIdioma(idioma);

}