#ifndef NEGOCIO_ESTUDIANTES_H_
#define NEGOCIO_ESTUDIANTES_H_
#include "Usuario.h"
#include "../Dto/DTOFecha.h"
using namespace std;
class Estudiante : public Usuario{
private:
     string paisResidencia;
     DTOFecha fechaNacimiento;
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
};



#endif /*NEGOCIO_ESTUDIANTES_H_*/