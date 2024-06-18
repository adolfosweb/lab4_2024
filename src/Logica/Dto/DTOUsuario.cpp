/*
 * DTOUsuario.cpp
 *
 *  Created on: 10 jun 2024
 *      Author: gabriel
 */

#include "DTOUsuario.h"

DTOUsuario::DTOUsuario() {
	// TODO Auto-generated constructor stub

}

DTOUsuario::DTOUsuario(string nick, string pass, string nom, string descrip) {
	this->nick=nick;
	this->pass=pass;
	this->nom=nom;
	this->descrip=descrip;
}

DTOUsuario::~DTOUsuario() {
	// TODO Auto-generated destructor stub
}

string DTOUsuario::getNick(){
	return this->nick;
}
string DTOUsuario::getPass(){
	return this->pass;
}
string DTOUsuario::getNom(){
	return this->nom;
}
string DTOUsuario::getDescripcion(){
	return this->descrip;
}
