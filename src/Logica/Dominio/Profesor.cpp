#include "Profesor.h"
#include "Curso.h"
#include "../Dto/DTOCurso.h"
Profesor::Profesor(){}

Profesor::Profesor(string nick, string pass, string nom,string descrip, string instituto) 
: Usuario(nick, pass, nom, descrip), instituto(instituto){}

Profesor::~Profesor(){
    
}
void Profesor::agregarIdioma(Idioma* idioma) {
	this->idioma.insert(idioma);
}

string Profesor::getInstituto(){
	return this->instituto;
}


set<string> Profesor::getIdiomas(){
	set<string> idiomas;
	for (set<Idioma*>::iterator it = this->idioma.begin(); it != idioma.end(); ++it) {
		 idiomas.insert((*it)->getIdioma());
		 
	}
	return idiomas;
};


bool verificarTipoUsuario(Usuario* usuario)
{
    return usuario->esProfesor();
}

bool Profesor::esProfesor(){
    return true;
}
void Profesor :: setCurso(Curso* curso)
{
    this->cursor.insert(curso);   
}

set<string> Profesor :: listoIdiomaProfesor()
{
    set<string> resu;
    set<Idioma*> :: iterator it;
   	for (it = this->idioma.begin(); it != this->idioma.end(); it++) {
        resu.insert((*it)->getIdioma());
	}
    return resu;
}

string Profesor :: seleccionarIdioma(string idiomaProf)
{
    set<Idioma*> :: iterator it;
   	for (it = this->idioma.begin(); it != this->idioma.end(); it++) 
    {
        if ((*it)->getIdioma()==idiomaProf)
        {
            return (*it)->getIdioma();
        }

	}
    return "";
}
set<Curso*> Profesor :: ObtenerCursos()
{
    return cursor;
}

map<int,Inscripcion*> Profesor :: obtenerCursosInscriptos()
{
    return map<int, Inscripcion*>();
}