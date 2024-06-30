#ifndef LOGICA_DTO_DTOCURSO_H_
#define LOGICA_DTO_DTOCURSO_H_
#include <set>
#include "DTOIdioma.h"
#include "../Dominio/Curso.h"
#include <iostream>


using namespace std;

class DTOCurso{
private:
    string nombre;
    string descripcion;
    DTOIdioma idioma;
    ENUMDificultad dificultad;
    bool habilitado;
    set<DTOLeccion> lecciones;
    set<string> previas;
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
    void setLecciones(set<DTOLeccion> leccion);
    set<DTOLeccion> getLecciones();

    void setPrevias(set<string> previa);
    set<string> getPrevias();

    //Evitar error no match for operator<
    bool operator<(const DTOCurso& c) const;
};
#endif /* LOGICA_DTO_DTOCURSO_H_ */