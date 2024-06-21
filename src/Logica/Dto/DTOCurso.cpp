#include "DTOCurso.h"
#include <iostream>
using namespace std;

DTOCurso :: DTOCurso() 
{
	//Constructor por defecto.

}

DTOCurso :: DTOCurso(string nombreCurso,string Descripcion, DTOIdioma *IdiomaAsignado, bool habilitado) : nombreCurso(nombreCurso), Descripcion(Descripcion), IdiomaAsignado(IdiomaAsignado), habilitado(habilitado)
{
    //Constructor por parámetros...
}

DTOCurso :: ~DTOCurso() 
{
	//Destructor por defecto.
}

string DTOCurso :: getNombreCurso()
{
	return nombreCurso;
}

