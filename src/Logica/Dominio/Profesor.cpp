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
void Profesor :: setCurso(string curso)
{
    this->cursor.insert(curso);   
}

void Profesor :: listoIdiomaProfesor()
{
    set<Idioma*> :: iterator it;
   	for (it = this->idioma.begin(); it != this->idioma.end(); it++) {
        cout<<": "<< (*it)->getIdioma()<<endl;
	}

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