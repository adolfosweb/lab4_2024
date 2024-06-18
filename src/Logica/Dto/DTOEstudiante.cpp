/*
 * DTOEstudiante.cpp
 *
 *  Created on: 10 jun 2024
 *      Author: gabriel
 */

#include "DTOEstudiante.h"
#include "DTOUsuario.h"
#include <iostream>
using namespace std;

DTOEstudiante::DTOEstudiante() {
	// TODO Auto-generated constructor stub

}
DTOEstudiante::DTOEstudiante(string nick, string pass, string nom, string descrip, string pais, DTOFecha fecha) 
: DTOUsuario(nick, pass, nom, descrip) , paisResidencia(pais), fecha(fecha) {


}
DTOEstudiante::~DTOEstudiante() {
	// TODO Auto-generated destructor stub
}


string DTOEstudiante::getPaisResidencia(){
	return this->paisResidencia;
}
DTOFecha DTOEstudiante::getFecha(){
	return this->fecha;
}
