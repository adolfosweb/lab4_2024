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
void Estudiante :: setCurso(string curso)
{  
}
void Estudiante ::listoIdiomaProfesor()
{
}
string Estudiante :: seleccionarIdioma(string idiomaProf)
{

    return "";
}
