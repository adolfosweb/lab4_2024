#ifndef LOGICA_PROFESOR_H_
#define LOGICA_PROFESOR_H_
#include "../Dto/DTOCurso.h"
#include <iostream>
#include "Usuario.h"
#include "Curso.h"
using namespace std;
#include <set>
#include "Idioma.h"

class Profesor :public Usuario{
 private:
        string instituto;
        set<Idioma*> idioma;
        set<string> cursor;
public:

    Profesor();
    Profesor(string nick, string pass, string nom,	string descrip, string instituto);
	virtual ~Profesor();
    void mostrarInfo();
	void agregarIdioma(Idioma* idioma);
    bool esProfesor();
    void setCurso(string curso);
//    void listoIdiomaProfesor(string nombreProf);
};
#endif /*LOGICA_PROFESOR_H_*/