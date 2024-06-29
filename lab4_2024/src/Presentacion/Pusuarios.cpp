#include "Pusuarios.h"
#include "../Logica/Controller/Controller.h"
#include "../Logica/Dto/DTOFecha.h"
#include <set>
#include <iostream>

using namespace std;

Pusuarios::Pusuarios(){
    this->iPusuario = new Controller();
}
Pusuarios::~Pusuarios(){
    delete this->iPusuario;
}

void  Pusuarios::altaUsuario(){
    string nick;
	cout << "Ingrese nick:"<< endl;
	cin >> nick;

	bool existe = this->iPusuario->verificarNick(nick);
	if (!existe) {
		cout << "Es estudiante o profesor? (E estudiante o P profesor)" << endl;
		string tipoUsuario;
		DTOUsuario *nuevoUsuario;

        // Validacion tipo usuario
		cin >> tipoUsuario;
        while (tipoUsuario != "e" && tipoUsuario != "p" && tipoUsuario != "E" && tipoUsuario != "P"){
            cout << "error, las opciones son 1 Estudiante o 2 Profesor";
            cin >> tipoUsuario;
        }

		if (tipoUsuario == "e" or tipoUsuario == "E") {
			nuevoUsuario = ingresarEstudiante(nick);

		} 
        else
        {
			nuevoUsuario = ingresarProfesor(nick);
		}

		this->iPusuario->agregarUsuario(nuevoUsuario);

		cout << "Fin ingreso de usuario " << endl;
		
	} else  {
		cout << "Ya existe el usuario. Imposible continuar..." << endl;
	}

}

DTOEstudiante* Pusuarios::ingresarEstudiante(string nick){
//TODO evitar duplicar este codigo
    string pass;
    string nom;
    string descrip;
    string pais;
    int dia;
    string mes;
    int anio;

    cout << "Ingresar pass:" << endl;
    cin >> pass;
    cout << "Ingresar nombre:" << endl;
    cin.ignore();
    getline(cin, nom); // Usa getline para leer toda la línea de entrada
    cout << "Ingresar descripcion:" << endl;
    getline(cin, descrip); // Usa getline para leer toda la línea de entrada
    cout << "Ingresar pais:" << endl;
    cin >> pais;
    cout << "Ingresar Fecha Nacimiento:" << endl;
    cout << "Ingresar dia:" << endl;
    cin >> dia;
    cout << "Ingresar mes:" << endl;
    cin >> mes;
    cout << "Ingresar año:" << endl;
    cin >> anio;

    DTOFecha  fecha = DTOFecha(dia,mes,anio);
    DTOEstudiante * nuevoEstudiante = new DTOEstudiante(nick,pass,nom,descrip,pais,fecha);

    return nuevoEstudiante;
}

DTOProfesor* Pusuarios::ingresarProfesor(string nick){
//TODO evitar duplicar este codigo
    string pass;
    string nom;
    string descrip;
    string instituto;
    set<string> idiomas;

    cout << "Ingresar pass:" << endl;
    cin >> pass;
    cout << "Ingresar nombre:" << endl;
    cin.ignore();
    getline(cin, nom); // Usa getline para leer toda la línea de entrada
    cout << "Ingresar descripcion:" << endl;
    cin.ignore();
    getline(cin, descrip); // Usa getline para leer toda la línea de entrada
    cout << "Ingresar instituto:" << endl;
    cin >> instituto;

    int agregarIdioma;
    cout << " ¿Desea agregar idiomas? (1=si 2 =no)? " <<endl;
    cin >> agregarIdioma;
    if (agregarIdioma == 1) {
        idiomas = seleccionarIdiomas();
    } else {
        cout << "No se seleccionan idiomas " << endl;
    }

    DTOProfesor * nuevoProfesor = new DTOProfesor(nick,pass,nom,descrip,instituto,idiomas);

    return nuevoProfesor;
}

set<string>  Pusuarios::seleccionarIdiomas(){

    set<string> idiomasExistentes = this->iPusuario->listIdiomas();
	set<string> idiomasSeleccionados;

	set<string>::iterator it;
	for (it = idiomasExistentes.begin(); it != idiomasExistentes.end(); it++) {
		cout << "Idioma: " << *it << endl;
	}
	string idioma;
	bool quiereIngresarIdiomas = true;
	do {
		cout << "Ingrese un idioma de la lista: (S/s para salir)" << endl;
		cin >> idioma;
		if (idioma != "S" && idioma != "s") {
			it = idiomasExistentes.find(idioma);
			if (it != idiomasExistentes.end()) {
				//solo selecciono los idiomas que existen
				idiomasSeleccionados.insert(idioma);
				cout << "Idioma ingresado: " << idioma  << endl;
			} else {
				cout << "El idioma ingresado no existe" << endl;
			}
		} else {
			quiereIngresarIdiomas = false;
		}

	} while (quiereIngresarIdiomas);

	return idiomasSeleccionados;
}

//void  Pusuarios::listadoUsuarios(){
//    cout << "Listado de Usuarios"<< endl;
//	this->iPusuario->listadoUsuarios();
//}

//CU2 - Consulta de Usuario
void Pusuarios::infoUsuario() {

	cout << "Listado de Usuarios"<< endl;

	set<string> usuariosExistentes = this->iPusuario->listadoUsuarios();
	set<string> usuarioSelecionado;

	set<string>::iterator it;
	for (it = usuariosExistentes.begin(); it != usuariosExistentes.end(); it++) {
		cout << *it << endl;
	}
    //controlo que sea un usuario que existe
    string elUsuario;
	bool existeUsuario = false;
    while (existeUsuario == false)
    {
        cout << "Ingresa un usuario de la lista:" << endl;
        cin >> elUsuario;
        existeUsuario = this->iPusuario->verificarNick(elUsuario);
    }

    //verifico si es estudiante, presento estudiante
    bool result =  this->iPusuario->esEstudiante(elUsuario);
    if (result == true){
        cout << "Datos del estudiante" << endl;
        DTOEstudiante elEstudiante = this->iPusuario->infoEstudiante(elUsuario);
        cout << "Nick: " << elEstudiante.getNick() << endl;
        cout << "Nombre: " << elEstudiante.getNom() << endl;
        cout << "Descripcion: " << elEstudiante.getDescripcion() << endl;
        cout << "Pais Recidencia1: " << elEstudiante.getPaisResidencia() << endl;
        cout << "Fecha Nac: " << elEstudiante.getFecha().dia << "/" <<
        elEstudiante.getFecha().mes << "/" <<
        elEstudiante.getFecha().anio << endl;
    }
    //si no es estudiante, presento profesor
    else{
        cout << "Datos del Profesor" << endl;
        DTOProfesor elProfesor = this->iPusuario->infoProfesor(elUsuario);
        cout << "Nick: " << elProfesor.getNick() << endl;
        cout << "Nombre: " << elProfesor.getNom() << endl;
        cout << "Descripcion: " << elProfesor.getDescripcion() << endl;
        cout << "Instituto: " << elProfesor.getInstituto() << endl;
        //cout << elProfesor->*getIdiomas() << endl;
        
        /*
        set<string>::iterator it;
	    for (it = elProfesor.getIdiomas().begin(); it != elProfesor.getIdiomas().end(); it++) {
		    cout << "-" << *it << endl;
	    } */

        set<string> idiomas = elProfesor.getIdiomas();
        if (idiomas.empty()) {
            cout << "No hay idiomas registrados." << endl;
        } else {
            for (const auto& idioma : idiomas) {
                cout << "-" << idioma << endl;
            }
        }
    }
}
//Fin  - CU2 Consulta de suaruio

//CU13 Consultar estadísticas
void Pusuarios :: consultaEstudiante()
{	
	string INick = "";
	cout << "Mostrando listado de estudiantes:" << endl;	//Muestra todos los estudiantes del sistema...
	int pass = iPusuario->listarUsuarios('e');

	if(pass != 0)
    {    
        cout << "Ingrese Nick de estudiante a seleccionar" << endl;
	    cin >> INick;

	    iPusuario->consultarStatsEstudiante(INick);	        //Se muestran las stats del estudiante.
    }
    else
    {
        cout << "No existen estudiantes registrados." << endl;
        getchar();getchar();
    }
}

void Pusuarios :: consultaProfesor()
{
	string INick = "";
	cout << "Mostrando listado de profesores" << endl;	//Muestra todos los estudiantes del sistema...
	int pass = iPusuario->listarUsuarios('p');	
	
    if(pass != 0)
	{
        cout << "Ingrese Nick de profesor a seleccionar" << endl;
	    cin >> INick;

	    iPusuario->consultarStatsProfesor(INick);	
    }
    else
    {
        cout << "No existen profesores registrados." << endl;
        getchar();getchar();
    }
}