#ifndef LOGICA_CURSO_H_
#define LOGICA_CURSO_H_
#include <iostream>
#include "../Dto/DTOIdioma.h"
using namespace std;
//test
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
public:
    Curso(/* args */);
    Curso(string nombre,string descripcion, DTOIdioma *idioma, ENUMDificultad dificultad, bool habilitado);
    ~Curso();
    string getNombre();
    string getDescripcion();
    DTOIdioma* getIdioma();
    ENUMDificultad getDificultad();
    bool estaHabilitado();
};



#endif /*LOGICA_CURSO_H_*/