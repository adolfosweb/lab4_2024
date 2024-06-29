#include "Usuario.h"

Usuario::Usuario(){

}
Usuario::Usuario(string nick, string pass, string nom, string descrip){
    this->nick=nick;
     this->pass=pass;
      this->nom=nom;
       this->descrip=descrip;
}
Usuario::~Usuario(){}



string Usuario::getNick(){
    return this->nick;
}

string Usuario::getPass(){
    return this->pass;
}

string Usuario::getNom(){
	return this->nom;
}
string Usuario::getDescrip(){
    return this->descrip;
}