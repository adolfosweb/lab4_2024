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
    std::system("clear");
    string nombre = "", objetivoAprendizaje = "", tema = "", nombreProf = "", descripcion = "";
    ENUMDificultad dif;
    int difInt = 0, select = 0;
    DTOIdioma *idioma;
    bool habilitado = false;

    cout << "Ingrese Nombre del Curso:" << endl;
    getline(cin, nombre); 
    getchar();
    
    cout << "Ingrese una Descripcion:" << endl;
    getline(cin, descripcion); 
    getchar();
    
    cin.ignore();
    cout << "Ingrese la dificultad (0: Fácil, 1: Intermedio, 2: Avanzado):" << endl;
    cin >> difInt;
    getchar();

    cout << "Lista de Profesores:" << endl;
    this->SystemInstance->listoProfesor();
    cout << "Ingrese Nombre del Profesor:" << endl;
    getline(cin, nombreProf); 
    getchar();

    switch (difInt)
    {
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

    set<string> previas;
    int agregarCurso;

    cout << "¿Desea agregar Previas? (1=si, 2=no): " << endl;
    cin >> agregarCurso; 
    getchar();
    if (agregarCurso == 1)
    {
        previas = seleccionarCursos();
    }
    else
    {
        cout << "No se agregó previa" << endl;
    }

    int Adleccion;
    cout << "¿Desea agregar Lecciones? (1=si, 2=no): " << endl;
    cin >> Adleccion;
    getchar();
    DTOLeccion nuevaLeccion(0, tema, objetivoAprendizaje);

    if (Adleccion == 1)
    {
        cout << "Ingrese un tema: " << endl; 
        getline(cin, tema); 
        getchar();

        cout << "Ingrese un objetivo de aprendizaje: " << endl;
        getline(cin, objetivoAprendizaje); 
        getchar();
    }
    else
    {
        cout << "No se agregó Lecciones" << endl;
    }

    if (this->SystemInstance->verificarNick(nombreProf))
    {
        this->SystemInstance->altaCurso(nombre, descripcion, idioma, dif, habilitado, nombreProf, previas, nuevaLeccion);
    }
    else
    {
        cout << "Nombre de Usuario No encontrado" << endl;
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

//CU 8 HABILITAR CURSO
void PCurso::habilitarCurso(){
    map<int,DTOCurso>  cursoNoHabilitados;

    cursoNoHabilitados = this->SystemInstance->ConsultaCursosNoHabilitados();
    if(!cursoNoHabilitados.empty()){
            cout<<"Los cursos no habilitados son: "<<endl;

    for(auto ct = cursoNoHabilitados.begin(); ct!= cursoNoHabilitados.end(); ct++)
        {
            cout << "Curso " << ct->first <<" "<<ct->second.getNombreCurso() << endl;
            
        }

        int numeroCurso;
        bool exiteCurso=false;
        

        while(!exiteCurso){
            cout<<"selecciona el numero de un curso a habilitar"<<endl;

            cin>>numeroCurso;

            auto it = cursoNoHabilitados.find(numeroCurso);

            if(it != cursoNoHabilitados.end()){

                this->SystemInstance->habilitarCurso(it->second.getNombreCurso());
                exiteCurso=true;
            }else{
                cout<<"El curso eleguido no existe"<<endl;
            }


        }
    }else{
        cout<<"No hay curso para habilitar"<<endl;
    }
}