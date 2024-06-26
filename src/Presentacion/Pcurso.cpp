#include <iostream>
#include <set>
#include "../Logica/Controller/Controller.h"
#include "../Logica/Dto/DTOCurso.h"
#include "Pcurso.h"
PCurso::PCurso(){
    this->SystemInstance=new Controller();
}

PCurso::~PCurso(){
    delete this->SystemInstance;
}
void PCurso::altaCurso()
{
    string nombre;
    string descr;
    
	cout << "Ingrese Nombre del Curso:"<< endl;
	cin >> nombre;
    cout << "Ingrese una Descripcion:"<< endl;
	cin >> descr;

    this->SystemInstance->altaCurso(nombre,descr);
}
void PCurso::AgregarEjercicio()
{

}