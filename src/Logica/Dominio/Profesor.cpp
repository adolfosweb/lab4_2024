#include "Profesor.h"
Profesor::Profesor(){}

Profesor::Profesor(string nick, string pass, string nom,string descrip, string instituto) 
: Usuario(nick, pass, nom, descrip), instituto(instituto){}

Profesor::~Profesor(){
    
}
void Profesor::agregarIdioma(Idioma* idioma) {
	this->idioma.insert(idioma);
}