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
    bool habilitado;
public:
    Curso(/* args */);
    ~Curso();
    bool estaHabilitado();

};



#endif /*LOGICA_CURSO_H_*/