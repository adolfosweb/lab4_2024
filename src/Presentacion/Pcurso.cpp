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

void PCurso::AgregarLeccion()
{
    map<int,DTOCurso> Temp;
    cout << "\nAgregando Lección.\nListando no Habilitados:\n" << endl;
    Temp = SystemInstance->ConsultaCursosNoHabilitados();
    int cont = 1;

    for(auto ct = Temp.begin(); ct!= Temp.end(); ct++)
    {
        cout << "Curso Número " << cont << endl;
        ct->second.MostrarDatos();
        cont++;
    }

    int in = 0;

    while (in < 1 && in > Temp.size())  //Mientras sea menor a 1 o mayor al max del map...
    {   cout << "\nIngrese el número del curso a seleccionar..." << endl;
        cin >> in;
    }

    auto Cur = Temp.find(in);   //Se obtiene DTOCurso

    string nombreLeccion = "", objetivo = "";
    char sel = ' ';

    cout << "\nIngrese nombre de la nueva lección:" << endl;
    cin >> nombreLeccion;
    cout << "\nIngrese objetivo de la lección:" << endl;
    cin >> objetivo;

    cout << "\nDesea ingresar También los ejercicios? S/N" << endl;
    cin >> sel;

    if(sel == 'S' || sel == 's')
    {
        //Ingresar Ejercicio, uno del grupo lo está haciendo...
    }

    DTOLeccion NuevaLeccion(0,nombreLeccion,objetivo);

    if (SystemInstance->IngresoLeccion(Cur->second,NuevaLeccion))   //Se pasa el DTOCurso y DTOLeccion.
	{
        cout << "\nIngreso Completado..." << endl;
    }

    


}