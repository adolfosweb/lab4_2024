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
        this->SystemInstance->altaCurso(nombre,descripcion,idioma,nombreProf,dif,habilitado,previas);
    
}

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

    int in = 1;
    bool cursoAceptado=false;
    while (!cursoAceptado){   
        cout << "\nIngrese el número del curso a seleccionar..." << endl;
        cin >> in;
        if(in >= 1 && in <= Temp.size() ){
            cursoAceptado=true; 
        }else{
            cout << "Número fuera de rango. Por favor, ingrese un número entre 1 y " << Temp.size() << "." << endl;
        }
    }

      
    auto Cur = Temp.find(in); //Se obtiene DTOCurso
    string nombreLeccion = "", objetivo = "";
    char sel = ' ';

    cout << "\nIngrese tema de la nueva lección:" << endl;
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

void PCurso :: consultaCurso()
{
    cout << "Mostrando todos los cursos: " << endl;
    map<int,DTOCurso> cursos = SystemInstance->ConsultaCursosHabilitados();
    string ingreso = "";
    
    for(auto ct = cursos.begin(); ct != cursos.end(); ct++)
    {
        cout << "Código Curso: C" << ct->first << "Nombre Curso: "<< ct->second.getNombreCurso() << endl ;
            
    }

    cout << "\nIngrese el curso a seleccionar." << endl;
    cin >> ingreso;

    int seleccion = stoi(ingreso);  //Solo almacenará el número del ingreso.

    auto Cur = cursos.find(seleccion);   //Se obtiene DTOCurso

    float promedio = SystemInstance->obtenerPromedioCurso(Cur->second);  //Se obtiene el promedio de ese curso entre todos los estudiantes.

    Cur->second.MostrarDatos();

    if(promedio != 0)
        cout << "Promedio total de este Curso: " << promedio << "%"<< endl;
    else
        cout << "No hay estudiantes que hayan cursado/aprobado este curso." << endl;

}