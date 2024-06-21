#include "Pusuarios.h"
#include "../Logica/Controller/Controller.h"
#include "../Logica/Dto/DTOFecha.h"
#include <set>
#include <iostream>
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
		cout << "Es estudiante o profesor? (1 estudiante 2 profesor)" << endl;
		int tipoUsuario;
		DTOUsuario *nuevoUsuario;

        // Validacion tipo usuario
		cin >> tipoUsuario;
        while (tipoUsuario != 1 && tipoUsuario != 2){
            cout << "error, las opciones son 1 Estudiante o 2 Profesor";
            cin >> tipoUsuario;
        }

		if (tipoUsuario == 1) {
			nuevoUsuario = ingresarEstudiante(nick);

		} else {
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
    cin >> nom;


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
    cin >> nom;
    cout << "Ingresar descripcion:" << endl;
    cin >> descrip;
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
        cout << "Pais Recidencia1: " << elEstudiante.getPaisResidencia() << endl;
        cout << "Fecha Nac: " << elEstudiante.getFecha().anio << endl;
    }
    //si no es estudiante, presento profesor
    else{
        cout << "Datos del Profesor" << endl;
        DTOProfesor elProfesor = this->iPusuario->infoProfesor(elUsuario);
        cout << "Nick: " << elProfesor.getNick() << endl;
        cout << "Nombre: " << elProfesor.getNom() << endl;

    }
    

    
	// es alumno ()
	// si es alumno 
	//  dinamyc cast y lo presento como alumno
	// else
	//	dinamyc cast y presento como profe

}
//Fin  - CU2 Consulta de suaruio