#include <iostream>
#include <set>
#include "../Logica/Controller/Controller.h"
#include "../Logica/Dominio/Usuario.h"
#include "../Logica/Dto/DTOCurso.h"
#include "Pcurso.h"
PCurso::PCurso(){
    this->SystemInstance=new Controller();
}

PCurso::~PCurso(){
    delete this->SystemInstance;
}


void PCurso::altaCurso(){

    std::system("clear");
    string nombre = "", objetivoAprendizaje = "", tema = "", descripcion = "";
    ENUMDificultad dif;
    int difInt = 0, select = 0;
    
    bool habilitado = false;
    
    cin.ignore();

    cout << "Ingrese Nombre del Curso:" << endl;
    getline(cin, nombre); 
    
    
    cout << "Ingrese una Descripcion:" << endl;
    getline(cin, descripcion); 
    
    
    
    cout << "Ingrese la dificultad (0: Fácil, 1: Intermedio, 2: Avanzado):" << endl;
    cin >> difInt;
    cin.ignore();
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

    cout << "Lista de Profesores:" << endl;
    set<string> listaProf =this->SystemInstance->listoProfesor();

    set<string>::iterator it;
	for (it = listaProf.begin(); it != listaProf.end(); it++) {
		cout << "Idioma: " << *it << endl;
	}
    string nombreProf;
	bool existeUsuario = false;
    while (existeUsuario == false)
    {
        cout << "Ingresa un usuario de la lista:" << endl;
        cin >> nombreProf;
        existeUsuario = this->SystemInstance->verificarNick(nombreProf);
        if(existeUsuario==false){
            cout<<"el nick ingresado no es correcto"<<endl;
        }
    }

    set<string> idiomasProfesor=this->SystemInstance->idiomasProfesor(nombreProf);
    cout << "Lista de Idioma del Profesor:" << endl;
    set<string>::iterator it2;
	for (it2 = idiomasProfesor.begin(); it2 != idiomasProfesor.end(); it2++) {
		cout << "Idioma: " << *it2 << endl;
	}

    string idioma;
	bool existeIdioma = false;
    while (!existeIdioma)
    {
        cout << "Ingresa un Idioma de la lista:" << endl;
        cin >> idioma;
       
       if (idiomasProfesor.find(idioma) != idiomasProfesor.end()) {
        existeIdioma = true;
       }else {
        cout << "El idioma ingresado no es correcto. Por favor, intenta nuevamente." << endl;
        }
    }
    
    set<string> previas;
    int agregarCurso;

    cout << "¿Desea agregar Previas? (1=si, 2=no): " << endl;
    cin >> agregarCurso; 
    cin.ignore();

    if (agregarCurso == 1){
        previas = seleccionarCursos();
    }else{
        cout << "No se agregó previa" << endl;
    }
        this->SystemInstance->altaCurso(nombre,descripcion,idioma,nombreProf,dif,habilitado,previas);
    
}

set<string>  PCurso::seleccionarCursos()
{

    set<string> cursosExistentes = this->SystemInstance->listaCursos();
	set<string> CursosSeleccionados;

	set<string>::iterator it;
	for (it = cursosExistentes.begin(); it != cursosExistentes.end(); it++) 
    {
		cout << "Curso: " << *it << endl;
	}
	string curs;
	bool quiereIngresarcurso = true;
	do 
    {
		cout << "Ingrese un curso de la lista: (S/s para salir)" << endl;
		cin >> curs;

		if (curs != "S" && curs != "s") 
        {
			it = cursosExistentes.find(curs);

			if (it != cursosExistentes.end()) 
            {
				//solo selecciono los cursos que existen
				CursosSeleccionados.insert(curs);
				cout << "Previa ingresado: " << curs  << endl;
			} 
            else 
            {
				cout << "El curso ingresado no existe" << endl;
			}
		} 
        else 
        {
			quiereIngresarcurso = false;
		}
	} 
    while (quiereIngresarcurso);

	return CursosSeleccionados;
}


void PCurso::AgregarLeccion()
{
    map<int,DTOCurso> Temp;
    cout << "\nAgregando Lección.\nListando no Habilitados:\n" << endl;
    Temp = SystemInstance->ConsultaCursosNoHabilitados();

    for(auto ct = Temp.begin(); ct!= Temp.end(); ct++)
    {
        cout << "Código Curso: C" << ct->first << endl;
        ct->second.MostrarDatos();
    }

    int in = 0;
    bool cursoAceptado = false;
    //string ingreso = "";

    while (!cursoAceptado)  
    {  
        cout << "\nIngrese el curso a seleccionar..." << endl;
        cin >> in;
        //ingreso = ingreso.substr(1);
        //in = stoi(ingreso);

        if(in >= 1 && in <= Temp.size() )
        {
            cursoAceptado = true; 
        }
        else
        {
            cout << "Número fuera de rango. Por favor, ingrese un número entre 1 y " << Temp.size() << "." << endl;
        }
    }

      
    auto Cur = Temp.find(in); //Se obtiene DTOCurso
    string nombreLeccion = "", objetivo = "";
    char sel = ' ';

    cin.ignore();
    cout << "\nIngrese nombre de la nueva lección:" << endl;
    getline(cin,nombreLeccion,'\n');

    cout << "\nIngrese objetivo de la lección:" << endl;
    getline(cin,objetivo,'\n');

    cout << "\nDesea ingresar También los ejercicios? S/N" << endl;
    sel = getchar();

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

void PCurso :: consultaCurso()
{
    map<int,DTOCurso> cursos = SystemInstance->ConsultaCursosHabilitados();
    //string ingreso = "";
    int seleccion = 0;
    int advisor = 0;

    //Se comprueba que hayan cursos habilitados disponibles.
    for(auto ct = cursos.begin(); ct != cursos.end(); ct++){if(ct->second.estaHabilitado()){advisor++;}}

    if(!cursos.empty()) //Mientras mapa no esté vacío.
    {

        if(advisor != 0)
        {
            cout << "Mostrando todos los cursos: " << endl;
        
            for(auto ct = cursos.begin(); ct != cursos.end(); ct++)
            {
                if(ct->second.estaHabilitado())
                {
                  cout << "Código Curso: C" << ct->first << "Nombre Curso: "<< ct->second.getNombreCurso() << endl ;
                }

            }

            cout << "\nIngrese el curso a seleccionar." << endl;
            cin >> seleccion;

            //int seleccion = stoi(ingreso);  //Solo almacenará el número del ingreso.

            auto Cur = cursos.find(seleccion);   //Se obtiene DTOCurso
            float promedio = SystemInstance->obtenerPromedioCurso(Cur->second);  //Se obtiene el promedio de ese curso entre todos los estudiantes.

            Cur->second.MostrarDatos();

            if(promedio != 0)
            cout << "Promedio total de este Curso: " << promedio << "%"<< endl;
            else
            cout << "No hay estudiantes que hayan cursado/aprobado este curso." << endl;
        }
        else
        {
            cout << "\nNo existen cursos habilitados actualmente." << endl; //Mensaje error.
        }

    }
    else
    {
        cout << "\nNo existen cursos registrados." << endl; //Mensaje error.
        getchar();
        getchar();
    }

}