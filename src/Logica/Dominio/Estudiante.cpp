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
map<int,Inscripcion*> Estudiante :: obtenerCursosInscriptos()
{
    return cursosInscriptos;
}