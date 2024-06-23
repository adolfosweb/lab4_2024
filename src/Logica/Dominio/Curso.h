#ifndef LOGICA_CURSO_H_
#define LOGICA_CURSO_H_
#include <iostream>
using namespace std;

class Curso
{
private:
    string nombre;
    string descripcion;
    //dtidioma idioma;
    //Edificultad dificultad;
public:
    Curso(/* args */);
    Curso(string nombre,string descripcion);
    ~Curso();
    string getNombre();
};



#endif /*LOGICA_CURSO_H_*/