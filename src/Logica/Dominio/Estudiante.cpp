#include "Estudiante.h"
#include <ctime>
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
map<int,Inscripcion*> Estudiante :: obtenerCursosInscriptos()
{
    return cursosInscriptos;
}
set<Curso*> Estudiante :: ObtenerCursos()
{//Esto es para evitar problemas con clase hija profesor

    return set<Curso*>();   //Set vacío.
}
bool Estudiante :: inscribir(Curso* curso)
{
    bool FALSO=false;
    time_t ahora = time(0);
    tm* tiempoLocal = localtime(&ahora);
    int dia = tiempoLocal->tm_mday;
    int mes = tiempoLocal->tm_mon + 1;  
   int ano = 2024; 
   //tiempoLocal->tm_year + 1900;
    int c = cursosInscriptos.rbegin()->first;
    Inscripcion *I1 = new Inscripcion(dia,mes,ano,FALSO,curso);
    this->cursosInscriptos.insert({c+1,I1});
    return true;
}
set<Curso*> Estudiante::listarCursoAprobado()
{
    std::set<Curso*> CursoAprobado; // Cambiamos a set
    for (const auto& inscripcion : cursosInscriptos) // Iteramos con un rango basado en el bucle
    {
        if (inscripcion.second->getAprobado())
        {
            CursoAprobado.insert(inscripcion.second->getCurso());
        }
    }
    return CursoAprobado;
}