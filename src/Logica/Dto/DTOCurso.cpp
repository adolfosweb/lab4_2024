#include "DTOCurso.h"
#include "../src/Logica/Dominio/Curso.h" //PARA EL ENUM!
#include <iostream>
using namespace std;

DTOCurso :: DTOCurso() 
{
	//Constructor por defecto.

}

DTOCurso :: DTOCurso(string nombre,string descripcion, DTOIdioma idioma, ENUMDificultad dificultad, bool habilitado) : nombre(nombre), descripcion(descripcion), idioma(idioma), habilitado(habilitado)
{
    //Constructor por parámetros...
}

DTOCurso :: ~DTOCurso() 
{
	//Destructor por defecto.
}

string DTOCurso :: getNombreCurso()
{
	return nombre;
}

void DTOCurso :: MostrarDatos()
{
	cout << "Nombre: " << nombre << "\nDescripcion: " << descripcion <<  "\nIdioma del curso: " << idioma.getIdioma() << "\nDificultad: " << dificultad << endl;
	cout << "\n________________________________________________" << endl;
}

string DTOCurso :: getDescripcion()
{
	return descripcion;
}
DTOIdioma DTOCurso :: getIdioma()
{
	return idioma;
}
ENUMDificultad DTOCurso :: getDificultad()
{
	return dificultad;
}
bool DTOCurso :: estaHabilitado()
{
	return habilitado;
}

//Evitar error no match for operator<
bool DTOCurso :: operator<(const DTOCurso& c) const{
	return true;
}

