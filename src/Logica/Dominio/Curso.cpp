#include "Curso.h"
#include "../Dto/DTOIdioma.h"
#include <string>
#include <set>

Curso::Curso()
{
}
Curso::Curso(string nombre,string descripcion, DTOIdioma *idioma, ENUMDificultad dificultad, bool habilitado)
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

DTOIdioma* Curso :: getIdioma()
{

    return idioma;

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
//void Curso :: setPrevia(string curso)
//{
//    this->previa.insert(curso); 
//}
void Curso :: setAllPrevias(set<string> previa)
{
    for (auto ct = previa.begin();ct!=previa.end();ct++)
    {
       this->previa.insert((*ct));
    } 
}
