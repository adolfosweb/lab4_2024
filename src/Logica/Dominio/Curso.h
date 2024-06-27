#ifndef LOGICA_CURSO_H_
#define LOGICA_CURSO_H_
#include <iostream>
#include "../Dto/DTOIdioma.h"
#include "../Dto/DTOLeccion.h"
#include "Leccion.h"
#include <set>
using namespace std;

enum ENUMDificultad
{
    FACIL,MEDIO,DIFICIL
};


class Curso
{
private:
    string nombre;
    string descripcion;
    DTOIdioma *idioma;
    ENUMDificultad dificultad;
    bool habilitado;
    set<Leccion*> lecciones;
    set<string> previa;

public:
    Curso(/* args */);
    Curso(string nombre,string descripcion, DTOIdioma *idioma, ENUMDificultad dificultad, bool habilitado);
    ~Curso();
    string getNombre();
    string getDescripcion();
    DTOIdioma* getIdioma();
    ENUMDificultad getDificultad();
    bool estaHabilitado();
    void setLeccion(DTOLeccion leccion);
    void setAllPrevias(set<string> previa);
};



#endif /*LOGICA_CURSO_H_*/