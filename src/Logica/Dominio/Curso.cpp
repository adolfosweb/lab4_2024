#include "Curso.h"
#include "../Dto/DTOIdioma.h"
#include <string>
#include <set>

Curso::Curso()
{
}
Curso::Curso(string nombre, string descripcion, Idioma *idioma, ENUMDificultad dificultad, bool habilitado)
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
bool Curso ::estaHabilitado()
{
    return habilitado;
}
string Curso ::getDescripcion()
{
    return descripcion;
}

DTOIdioma Curso ::getIdioma()
{

    return DTOIdioma(idioma->getIdioma());
}
ENUMDificultad Curso ::getDificultad()
{
    return dificultad;
}
void Curso ::setLeccion(DTOLeccion leccion)
{

    Leccion *L = new Leccion(0, leccion.getTema(), leccion.getObjetivoAprendizaje());

    lecciones.insert(L); // Se ingresa un puntero a Lección.
}
void Curso::habilitate()
{
    this->habilitado = true;
}

void Curso ::setAllPrevias(set<Curso *> previa)
{
    for (auto ct = previa.begin(); ct != previa.end(); ct++)
    {
        this->previa.insert((*ct));
    }
}

float Curso ::obtenerPromedio()
{
    int contadorAp = 0;
    int contadorNa = 0;
    int total = 0;

    set<Ejercicio *> ejercicios;

    for (auto ct = lecciones.begin(); ct != lecciones.end(); ct++) // De cada lección...
    {
        ejercicios = (*ct)->ObtenerEjercicios();
        for (auto tt = ejercicios.begin(); tt != ejercicios.end(); tt++) // Se obtiene total de ejercicios aprobados y no aprobados
        {
            if ((*tt)->getAprobado())
            {
                contadorAp++;
            }
            else
            {
                contadorNa++;
            }
        }
    }

    total = contadorAp + contadorNa;

    if (total != 0)
    {
        return contadorAp / total;
    }

    return 0;
}
bool Curso ::cumplePrevia(set<Curso *> cursoAprob)
{
    int cont = 0;
    for (auto prev = previa.begin(); prev != previa.end(); prev++)
    {
        for (auto curso = cursoAprob.begin(); curso != cursoAprob.end(); curso++)
        {
            if ((*prev)->getNombre() == (*curso)->getNombre() && nombre != (*curso)->getNombre())
            {
                cont++;
            }
        }
    }
    if (previa.size() == cont)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void Curso ::mostrarCurso()
{
    cout << "-" << nombre << endl;
}

set<DTOLeccion> Curso::listarLecciones(){
    set<DTOLeccion> listaLecciones;
  	set<Leccion*>::iterator it;
    for (it = this->lecciones.begin(); it != this->lecciones.end(); it++) {
		DTOLeccion leccion((*it)->getNumero(),(*it)->getTema(),(*it)->getObjetivoAprendizaje());
        leccion.setEjercicio((*it)->ObtenerDTOEjercicios());
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

//CU9
void Curso::borrarLecciones(){
    for (auto it = this->lecciones.begin(); it != this->lecciones.end(); it++){
        (*it)->borrarEjercicios();
        delete *it;
    }
    this->lecciones.clear();
}
//FIN CU9

set<string> Curso::getPrevia(){
    set<string> listaNombrePrevia;
  	set<Curso*>::iterator it;
    for (it = this->previa.begin(); it != this->previa.end(); it++) {
		listaNombrePrevia.insert((*it)->getNombre());
	}
    return listaNombrePrevia;
}