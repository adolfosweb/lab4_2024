#ifndef LOGICA_DTO_DTOCURSO_H_
#define LOGICA_DTO_DTOCURSO_H_
#include "../Dominio/Curso.h"
#include "DTOIdioma.h"
#include <iostream>

using namespace std;

class DTOCurso
{
private:
    string nombre;
    string descripcion;
    DTOIdioma idioma;
    ENUMDificultad dificultad;
    bool habilitado;

public:
	
	DTOCurso();
	DTOCurso(string nombre,string descripcion, DTOIdioma idioma, ENUMDificultad dificultad, bool habilitado);
	virtual ~DTOCurso();
	string getNombreCurso();
    string getDescripcion();
    DTOIdioma getIdioma();
    ENUMDificultad getDificultad();
	bool estaHabilitado();
    void MostrarDatos();
};

#endif /* LOGICA_DTO_DTOCURSO_H_ */