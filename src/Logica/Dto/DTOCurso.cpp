#include "DTOCurso.h"
#include "../src/Logica/Dominio/Curso.h" //PARA EL ENUM!
#include <iostream>
using namespace std;

DTOCurso :: DTOCurso() 
{
	//Constructor por defecto.

}

DTOCurso :: DTOCurso(string nombre,string descripcion, DTOIdioma idioma, ENUMDificultad dificultad, bool habilitado) : nombre(nombre), descripcion(descripcion), idioma(idioma),dificultad(dificultad), habilitado(habilitado)
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

	cout << "Nombre: " << nombre << "\nDescripcion: " << descripcion <<  "\nIdioma del curso: " << idioma.getIdioma() << "\nDificultad: " << dificultadToString(dificultad) << endl;
	cout << "\n________________________________________________" << endl;
}

string DTOCurso::dificultadToString(ENUMDificultad dificultad) {
    switch (dificultad) {
        case FACIL:
            return "Fácil";
        case MEDIO:
            return "Medio";
        case DIFICIL:
            return "Difícil";
        default:
            return "Desconocido";
	 }
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