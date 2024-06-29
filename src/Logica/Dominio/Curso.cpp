#include "Curso.h"
#include "../Dto/DTOIdioma.h"
#include <string>
#include <set>

Curso::Curso()
{
}
Curso::Curso(string nombre,string descripcion,Idioma *idioma, ENUMDificultad dificultad, bool habilitado)
{
    this->nombre = nombre;
    this->descripcion = descripcion;
    this->idioma = idioma;
    this->dificultad = dificultad;
    this->habilitado = habilitado;
}
Curso::~Curso()
{
}
string Curso::getNombre()
{
    return this->nombre;
}
bool Curso :: estaHabilitado()
{
    return habilitado;
}
string Curso :: getDescripcion()
{
    return descripcion;
}

DTOIdioma Curso :: getIdioma()
{
 
    return DTOIdioma(idioma->getIdioma());

}
ENUMDificultad Curso :: getDificultad()
{
    return dificultad;
}
void Curso :: setLeccion(DTOLeccion leccion)
{

    Leccion *L = new Leccion (0,leccion.getTema(),leccion.getObjetivoAprendizaje());
    
    lecciones.insert(L);   //Se ingresa un puntero a Lección.


}
void Curso::habilitate(){
    this->habilitado=true;
}

void Curso :: setAllPrevias(set<Curso*> previa)
{
    for (auto ct = previa.begin();ct!=previa.end();ct++)
    {
       this->previa.insert((*ct));
    } 
}

set<DTOLeccion> Curso::listarLecciones(){
    set<DTOLeccion> listaLecciones;
  	set<Leccion*>::iterator it;
    for (it = this->lecciones.begin(); it != this->lecciones.end(); it++) {
		DTOLeccion leccion((*it)->getNumero(),(*it)->getTema(),(*it)->getObjetivoAprendizaje());
		listaLecciones.insert(leccion);
	}
    return listaLecciones;
}

bool Curso::ingresarEjercicioPalabra(DTOLeccion l, DTOEjercicio e){
    set<Leccion*>::iterator it;
    for (it = this->lecciones.begin(); it != this->lecciones.end(); it++){
        if(l.getNumero() == (*it)->getNumero() && l.getTema() == (*it)->getTema() && l.getObjetivoAprendizaje() == (*it)->getObjetivoAprendizaje()){
            return (*it)->ingresarEjercicioPalabra(e);
            break;
        }
	}
    return false;
}

bool Curso::ingresarEjercicioTraduccion(DTOLeccion l, DTOEjercicio e){
    set<Leccion*>::iterator it;
    for (it = this->lecciones.begin(); it != this->lecciones.end(); it++){
        if(l.getNumero() == (*it)->getNumero() && l.getTema() == (*it)->getTema() && l.getObjetivoAprendizaje() == (*it)->getObjetivoAprendizaje()){
            return (*it)->ingresarEjercicioTraduccion(e);
            break;
        }
	}
    return false;
}

//FIN CU7