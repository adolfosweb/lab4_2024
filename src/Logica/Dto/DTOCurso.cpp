#include "DTOCurso.h"
#include "../Dominio/Curso.h" //PARA EL ENUM!
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
	cout << "\n________________________________________________" << endl;
	cout << "Nombre: " << nombre <<endl;
	cout << "Descripcion: " << descripcion<<endl;
	cout << "Idioma del Curso: " <<idioma.getIdioma()<<endl;
	cout << "Dificultad: " << dificultad<<endl;
	set<DTOLeccion>::iterator it;
	cout << "Las Lecciones del Curso Son: " << endl;
	for( it=this->lecciones.begin(); it!=this->lecciones.end();it++){
		cout << "________________________________________________" << endl;
		cout << "Leccion numero: " << it->getNumero()<<" Descripcion: "<<it->getTema()<<" Objetivo Aprendizaje: "<<it->getObjetivoAprendizaje() <<endl;
		it->mostrarEjercicios();
		cout << "________________________________________________" << endl;
	}
	set<string>::iterator it2;
	cout << "Las Previas Son: " << endl;
	for( it2=this->previas.begin(); it2!=this->previas.end();it2++){
		cout << "________________________________________________" << endl;
		cout << "Nombre: "<<*it2<<endl;
		cout << "________________________________________________" << endl;
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

//Evitar error no match for operator<
bool DTOCurso :: operator<(const DTOCurso& c) const{
	return true;
}

void DTOCurso::setLecciones(set<DTOLeccion> leccion){
	this->lecciones=leccion;
}

set<DTOLeccion> DTOCurso ::getLecciones(){
	return this->lecciones;
}
void DTOCurso::setPrevias(set<string> previa){
	this->previas=previa;
}
set<string> DTOCurso::getPrevias(){
	return this->previas;
}