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
        set<Curso*> cursor;
public:

    Profesor();
    Profesor(string nick, string pass, string nom,	string descrip, string instituto);

    string getInstituto();
    set<string> getIdiomas();
	virtual ~Profesor();
	void agregarIdioma(Idioma* idioma);
    bool esProfesor();
    void setCurso(Curso* curso);
    set<string> listoIdiomaProfesor();
    string seleccionarIdioma(string idiomaProf);
    map<int,Inscripcion*> obtenerCursosInscriptos();
    set<Curso*> ObtenerCursos();
    set<Curso*> listarCursoAprobado();
	bool inscribir(Curso* curso);
};
#endif /*LOGICA_PROFESOR_H_*/