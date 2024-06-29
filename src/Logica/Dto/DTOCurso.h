#ifndef LOGICA_DTO_DTOCURSO_H_
#define LOGICA_DTO_DTOCURSO_H_
#include "../Dominio/Curso.h"
#include "DTOIdioma.h"
#include <iostream>
#include <set>
using namespace std;

class DTOCurso
{
private:
    string nombre;
    string descripcion;
    DTOIdioma idioma;
    ENUMDificultad dificultad;
    bool habilitado;
    set<DTOLeccion> lecciones;
    set<DTOEjercicio> ejercicio;

public:
	
	DTOCurso();
	DTOCurso(string nombre,string descripcion, DTOIdioma idioma, ENUMDificultad dificultad, bool habilitado);
	virtual ~DTOCurso();
	string getNombreCurso();
    string getDescripcion();
    DTOIdioma getIdioma();
    set<DTOLeccion> getLecciones();
    ENUMDificultad getDificultad();
	bool estaHabilitado();
    void MostrarDatos();

    void setLecciones(set<DTOLeccion> leccion);
    //Evitar error no match for operator<
    bool operator<(const DTOCurso& c) const;


};
#endif /* LOGICA_DTO_DTOCURSO_H_ */