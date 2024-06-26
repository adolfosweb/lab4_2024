#include "Sistema.h"


Sistema* Sistema::miSistema=nullptr;

Sistema::~Sistema() {
	// TODO Auto-generated destructor stub
}

Sistema* Sistema::getInstance() {
	if (Sistema::miSistema==nullptr){
		Sistema::miSistema = new Sistema();
		Sistema::miSistema->inicializarDatos();
	}
	return Sistema::miSistema;

}

Sistema::Sistema() {

}

void Sistema::inicializarDatos() {
	//inicializo los idiomas del sistema


	cout << "Comienza inicializacion Sistema " << endl;

	Idioma *idioma1 = new Idioma("Ingles");
	Idioma *idioma2 = new Idioma("Aleman");
	Idioma *idioma3 = new Idioma("Portugues");

	this->idiomas.insert(idioma1);
	this->idiomas.insert(idioma2);
	this->idiomas.insert(idioma3);


	Usuario *usr1 = new Profesor("pp","pass1","nombre1","desc1","Instituto1");
	dynamic_cast<Profesor*>(usr1)->agregarIdioma(idioma1);
	dynamic_cast<Profesor*>(usr1)->agregarIdioma(idioma3);
	this->usuarios.insert(usr1);

	cout << "Fin inicializacion Sistema " << endl;
}

Idioma* Sistema::buscarIdioma(string nomIdioma) {
	Idioma* idioma = nullptr;
	set<Idioma*>::iterator it;
	for (it = this->idiomas.begin(); it != this->idiomas.end(); it++) {
		if ((*it)->getIdioma() == nomIdioma) {
			idioma = (*it);
			break;
		}
	}
	return idioma;
}