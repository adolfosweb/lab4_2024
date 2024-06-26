#include "DTOCurso.h"
#include "../src/Logica/Dominio/Curso.h" //PARA EL ENUM!
#include <iostream>
using namespace std;

DTOCurso :: DTOCurso() 
{
	//Constructor por defecto.

}

DTOCurso :: DTOCurso(string nombre,string descripcion, DTOIdioma *idioma, ENUMDificultad dificultad, bool habilitado) : nombre(nombre), descripcion(descripcion), idioma(idioma), habilitado(habilitado)
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