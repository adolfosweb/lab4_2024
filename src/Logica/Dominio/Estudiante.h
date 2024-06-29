#ifndef NEGOCIO_ESTUDIANTES_H_
#define NEGOCIO_ESTUDIANTES_H_
#include "Usuario.h"
#include "../Dto/DTOFecha.h"
#include "Inscripcion.h"
#include <iostream>
#include <map>
#include <set>
using namespace std;

class Estudiante : public Usuario{
private:
    string paisResidencia;
    DTOFecha fechaNacimiento;
    map<int,Inscripcion*> cursosInscriptos; //Inscripciones que contienen el curso...

public:
    
    
    Estudiante();
    Estudiante(string nick, string pass, string nom,string descrip, string pais, DTOFecha fecha);
    ~Estudiante();
    string getPaisResidencia();
    DTOFecha getFecha();
    bool esProfesor();
    void setCurso(Curso* curso);
    set<string> listoIdiomaProfesor();
    string seleccionarIdioma(string idiomaProf);
    map<int,Inscripcion*> obtenerCursosInscriptos();
    set<Curso*> ObtenerCursos();
    set<Curso*> listarCursoAprobado();
    bool inscribir(Curso* curso);
};



#endif /*NEGOCIO_ESTUDIANTES_H_*/