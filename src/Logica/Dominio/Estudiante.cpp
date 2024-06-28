#include "Estudiante.h"
Estudiante::Estudiante()
{
}

Estudiante::Estudiante(string nick, string pass, string nom,string descrip, string pais, DTOFecha fecha){
    this->nick=nick;
    this->pass=pass;
    this->nom=nom;
    this->descrip=descrip;
    this->paisResidencia=pais;
    this->fechaNacimiento=fecha;
}

Estudiante::~Estudiante(){
}

string Estudiante::getPaisResidencia(){
	return this->paisResidencia;
}
DTOFecha Estudiante:: getFecha(){
    return this->fechaNacimiento;
}
bool Estudiante::esProfesor() {
    return false;
}

void Estudiante :: setCurso(Curso* curso)
{  
}
set<string> Estudiante ::listoIdiomaProfesor()
{
    set<string> resu;
    return resu;
}
string Estudiante :: seleccionarIdioma(string idiomaProf)
{

    return "";
}