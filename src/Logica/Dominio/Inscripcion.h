#ifndef LOGICA_INSCRIPCION_H_
#define LOGICA_INSCRIPCION_H_

#include <iostream>
#include "Curso.h"
#include <map>

using namespace std;

class Inscripcion
{
private:
   int dd; 
   int mm;
   int aaaa;
   bool aprobado;
   Curso *Curso;    //Puntero al curso del estudiante...

public:
    Inscripcion();
    //Inscripcion(dtfecha fecha, bool aprobado);
    ~Inscripcion();

    //d0tfecha getFecha();
    bool getAprobado();
    bool esCurso(string nombreCurso,string descripcion);
    void ObtenerPromedio();
    float ObtenerDatoPromedio();
};



#endif /*LOGICA_INSCRIPCION_H_*/