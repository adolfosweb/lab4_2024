#ifndef LOGICA_INSCRIPCION_H_
#define LOGICA_INSCRIPCION_H_

#include <iostream>
#include "Curso.h"
#include <map>

using namespace std;

class Inscripcion
{
private:
   //dtfecha fecha;
   int dd; 
   int mm;
   int aaaa;
   bool aprobado;
   Curso *curso;
   set<Ejercicio*> ejAprobados; 
   
public:
    Inscripcion();
    Inscripcion(int dd,int mm,int aaaa, bool aprobado,Curso* curso);
    ~Inscripcion();

    //d0tfecha getFecha();
    bool getAprobado();

    //CU13
    bool esCurso(string nombreCurso,string descripcion);
    void ObtenerPromedio();
    float ObtenerDatoPromedio();
    Curso* getCurso();

    //CU12
    void setEjAprobado(Ejercicio* ejercicio);
    set<Ejercicio*> getEjAprobados();

};



#endif /*LOGICA_INSCRIPCION_H_*/