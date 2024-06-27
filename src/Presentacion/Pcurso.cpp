#include <iostream>
#include <set>
#include "../Logica/Controller/Controller.h"
#include "../Logica/Dominio/Usuario.h"
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
    string descripcion;
    ENUMDificultad dif;
    int difInt;
    int select;
    DTOIdioma *idioma;
    bool habilitado=false;
    string nombreProf;
	cout << "Ingrese Nombre del Curso:"<< endl;
	cin >> nombre;
    cout << "Ingrese una Descripcion:"<< endl;
	cin >> descripcion;
   cout << "Ingrese la dificultad (0: Fácil, 1: Intermedio, 2: Avanzado):" << endl;
    cin >> difInt;
    cout << "Lista de Profesores:" << endl;
    this->SystemInstance->listoProfesor();
    cout << "Ingrese Nombre del Profesor:"<< endl;
	cin >> nombreProf;
    switch (difInt) {
        case 0:
            dif = ENUMDificultad::FACIL;
            break;
        case 1:
            dif = ENUMDificultad::MEDIO;
            break;
        case 2:
            dif = ENUMDificultad::DIFICIL;
            break;
        default:
            cout << "Valor de dificultad no válido." << endl;
    }
    //muestro lista de idioma de prof
    //selecciona idioma
    if (this->SystemInstance->verificarNick(nombreProf))
    {
        this->SystemInstance->altaCurso(nombre,descripcion,idioma,dif,habilitado,nombreProf);
    }
    else
    {
        cout<<"Nombre de Usuario No encontrado"<<endl;
    }
}
void PCurso::AgregarLeccion()
{
    map<int,DTOCurso> Temp;
    cout << "\nAgregando Lección.\nListando no Habilitados:\n" << endl;
    Temp = SystemInstance->ConsultaCursosNoHabilitados();

    for(auto ct = Temp.begin(); ct!= Temp.end(); ct++)
    {
        cout << "Curso Número " << ct->first << endl;
        ct->second.MostrarDatos();
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