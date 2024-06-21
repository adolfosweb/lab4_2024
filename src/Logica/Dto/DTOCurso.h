#ifndef LOGICA_DTO_DTOCURSO_H_
#define LOGICA_DTO_DTOCURSO_H_

#include "DTOIdioma.h"
#include <iostream>

using namespace std;

class DTOCurso
{
private:
    string nombreCurso;
	string Descripcion;
    DTOIdioma *IdiomaAsignado;
    //ENUM dificultad; -Pendiente ENUM-
	bool habilitado;

public:
	
	DTOCurso();
	DTOCurso(string nombreCurso,string Descripcion, DTOIdioma *IdiomaAsignado, bool habilitado);
	virtual ~DTOCurso();
	string getNombreCurso();
	bool estaHabilitado();
};

#endif /* LOGICA_DTO_DTOCURSO_H_ */