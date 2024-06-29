/*
 * DTOProfesor.cpp
 *
 *  Created on: 10 jun 2024
 *      Author: gabriel
 */

#include "DTOProfesor.h"
#include <set>
using namespace std;

DTOProfesor::DTOProfesor() {
	// TODO Auto-generated constructor stub

}
DTOProfesor::DTOProfesor(string nick, string pass,string nom,string descrip, string instituto, set<string> idiomas)
: DTOUsuario(nick, pass, nom, descrip), instituto(instituto) {
	this->idiomas=idiomas;
}



DTOProfesor::~DTOProfesor() {
	// TODO Auto-generated destructor stub
}

string DTOProfesor::getInstituto(){
	return this->instituto;
}
set<string> DTOProfesor::getIdiomas(){
	return this->idiomas;
}

