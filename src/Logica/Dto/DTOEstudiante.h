/*
 * DTOEstudiante.h
 *
 *  Created on: 10 jun 2024
 *      Author: gabriel
 */

#ifndef NEGOCIO_DTO_DTOESTUDIANTE_H_
#define NEGOCIO_DTO_DTOESTUDIANTE_H_

#include "DTOUsuario.h"
#include "../Dto/DTOFecha.h"
#include <iostream>

using namespace std;

class DTOEstudiante:public DTOUsuario {
private:
    string paisResidencia;
	DTOFecha fecha;
public:
	
	DTOEstudiante();
	DTOEstudiante(string nick, string pass,	string nom,	string descrip, string pais, DTOFecha fecha);
	virtual ~DTOEstudiante();
	string getPaisResidencia();
	DTOFecha getFecha();
};

#endif /* NEGOCIO_DTO_DTOESTUDIANTE_H_ */
