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

void Pusuarios::cargarDatos(){
    //ingreso usuarios
    DTOFecha f1(15, "Julio", 1995);
    DTOEstudiante* U1 = new DTOEstudiante("jpidiom", "asdfg123", "Juan Perez", "Soy un apasionado del aprendizaje de idiomas.", "Argentina", f1);

    DTOFecha f2(28, "Febrero", 1998);
    DTOEstudiante* U2 = new DTOEstudiante("marsilva", "qwer456", "Maria Silva", "Como amante de los idiomas disfruto explorando nuevas formas de interactuar.", "Ecuador", f2);

    DTOFecha f3(10, "Noviembre", 1994);
    DTOEstudiante* U3 = new DTOEstudiante("pero12", "789werty", "Pedro Rodriguez", "Soy un entusiasta del aprendizaje de idiomas.", "Peru", f3);

    DTOFecha f4(22, "Abril", 1994);
    DTOEstudiante* U4 = new DTOEstudiante("laugu", "c1v2b3m4", "Laura Gutierrez", "Estoy fascinada por la forma en que las palabras pueden unir a las personas", "Chile", f4);

    DTOFecha f5(3, "Septiembre", 1994);
    DTOEstudiante* U5 = new DTOEstudiante("carlo22", "tyuipz147", "Carlos Lopez", "Emocionado por adquirir fluidez en diferentes lenguas.", "Uruguay", f5);

    DTOFecha f6(12, "Enero", 1994);
    DTOEstudiante* U6 = new DTOEstudiante("anator", "1qsxc36", "Ana Torres", "Disfruto de la belleza de las diferentes estructuras y sonidos.", "Argentina", f6);

    DTOFecha f7(25, "Junio", 1994);
    DTOEstudiante* U7 = new DTOEstudiante("luher24", "t7h8y5u6", "Lucia Hernandez", "Emocionada en la riqueza cultural que cada idioma ofrece.", "Colombia", f7);

    DTOFecha f8(8, "Diciembre", 1994);
    DTOEstudiante* U8 = new DTOEstudiante("dagon", "1w2e3r4t5", "David Gonzalez", "Aprender nuevas lenguas y sumergirme en diferentes culturas.", "Uruguay", f8);

    DTOFecha f9(17, "Marzo", 1994);
    DTOEstudiante* U9 = new DTOEstudiante("carmor", "6yu7i8m9", "Carmen Morales", "El aprendizaje de idiomas y expandir mis habilidades comunicativas en diferentes lenguas.", "Chile", f9);

    DTOFecha f10(2, "Agosto", 1994);
    DTOEstudiante* U10 = new DTOEstudiante("jose24", "qwj789p", "Jose Fernandez", "Disfruto del proceso de descubrir nuevas formas de comunicarme", "Bolivia", f10);

    set<string> LI1 = {"Ingles", "Portugues"};
    DTOProfesor* U11 = new DTOProfesor("langMaster", "P4s512", "Marta Grecia", "Soy una profesora apasionada por los idiomas", "Instituto de Idiomas Moderno", LI1);

    set<string> LI2 = {"Ingles", "Aleman", "Portugues"};
    DTOProfesor* U12 = new DTOProfesor("linguaPro", "Pess23", "Carlos Petro", "Mi objetivo es inspirar a mis estudiantes a explorar nuevas culturas e idiomas", "Centro Global", LI2);

    set<string> LI3 = {"Aleman"};
    DTOProfesor* U13 = new DTOProfesor("talkExpert", "Secret1", "Laura Perez", "Soy una profesora entusiasta del aprendizaje de idiomas", "Instituto de Idiomas Vanguardia", LI3);

    set<string> LI4 = {"Portugues"};
    DTOProfesor* U14 = new DTOProfesor("lingoSensei", "Secure2", "Franco Lopez", "Apasionada en guiar a mis estudiantes en su viajepor nuevos horizontes idiomaticos", "Centro de Idiomas", LI4);

    set<string> LI5 = {"Ingles"};
    DTOProfesor* U15 = new DTOProfesor("wordMaestro", "Passw0", "Ana Morales", "Soy una profesora comprometida en desarrollo de habilidades idiomaticas", "Instituto de Idiomas Progreso", LI5);

    set<DTOUsuario*> usuarios;
    
    usuarios.insert(U1);
    usuarios.insert(U2);
    usuarios.insert(U3);
    usuarios.insert(U4);
    usuarios.insert(U5);
    usuarios.insert(U6);
    usuarios.insert(U7);
    usuarios.insert(U8);
    usuarios.insert(U9);
    usuarios.insert(U10);
    usuarios.insert(U11);
    usuarios.insert(U12);
    usuarios.insert(U13);
    usuarios.insert(U14);
    usuarios.insert(U15);

    for (DTOUsuario* usuario : usuarios) {
        iPusuario->agregarUsuario(usuario);
    }

    //fin ingreso usuarios

    
set<string> previa; 

// Curso 1
this->iPusuario->altaCurso("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", "Ingles", "langMaster", FACIL, true, previa);

// Curso 2
this->iPusuario->altaCurso("Curso de ingles basico", "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.", "Ingles", "langMaster", FACIL, false, previa);


// Curso 3
set<string> p3={"Ingles para principiantes"};
this->iPusuario->altaCurso("Ingles intermedio: mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.", "Ingles", "linguaPro", MEDIO, true, p3);

// Curso 4
set<string> p4={"Ingles para principiantes","Ingles intermedio: mejora tu nivel"};
this->iPusuario->altaCurso("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.", "Ingles", "linguaPro", DIFICIL, true, p4);

// Curso 5
this->iPusuario->altaCurso("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.", "Portugues", "linguaPro", MEDIO, true, previa);

// Curso 6
set<string> p6={"Portugues intermedio",};
this->iPusuario->altaCurso("Portugues avanzado", "Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", "Portugues", "lingoSensei", DIFICIL, false, p6);
//fin creacion cursos cursos



DTOCurso curso1("Ingles para principiantes", "Curso para personas con poco o ningun conocimiento de ingles. Se enfoca en vocabulario basico, gramatica y habilidades de conversacion.", DTOIdioma("Ingles"), FACIL, true);
DTOCurso curso2("Curso de ingles basico", "Construye una base solida en el idioma. Cubre gramatica, vocabulario, comprension auditiva y expresion oral.", DTOIdioma("Ingles"), FACIL, false);
DTOCurso curso3("Ingles intermedio: mejora tu nivel", "Para estudiantes con conocimientos basicos de ingles que desean avanzar en su habilidad comunicativa. Se centra en la fluidez oral, lectura comprensiva y escritura.", DTOIdioma("Ingles"), MEDIO, true);
DTOCurso curso4("Curso avanzado de ingles", "Dirigido a personas con un nivel intermedio-alto que desean perfeccionar sus habilidades en todos los aspectos del idioma. Incluye gramatica avanzada, vocabulario y comprension escrita y auditiva.", DTOIdioma("Ingles"), DIFICIL, true);
DTOCurso curso5("Portugues intermedio", "Curso para aquellos que tienen conocimientos basicos de portugues y desean mejorar su nivel. Incluye practica de lectura, escritura y comprension auditiva.", DTOIdioma("Portugues"), MEDIO, true);
DTOCurso curso6("Portugues avanzado", "Curso avanzado para personas con un nivel intermedio-alto de portugues que desean perfeccionar su fluidez y dominio del idioma. Se trabaja en la gramatica avanzada y la expresion oral.", DTOIdioma("Portugues"), DIFICIL, false);

DTOLeccion leccion1(1, "Saludos y Presentaciones", "Aprender a saludar y despedirse");
DTOLeccion leccion2(2, "Articulos y Plurales", "Comprender y utilizar los articulos definidos e indefinidos, y aprender a formar los plurales regulares e irregulares de sustantivos");
DTOLeccion leccion3(1, "Actividades Cotidianas", "Comprender y utilizar los articulos definidos e indefinidos, y aprender a formar los plurales regulares e irregulares de sustantivos");
DTOLeccion leccion4(2, "Presente Simple", "Aprender el uso del presente simple");
DTOLeccion leccion5(1, "Conversaciones cotidianas", "Aprender a hacer preguntas y respuestas en situaciones comunes");
DTOLeccion leccion6(1, "Uso de modales avanzados", "Explorar el uso de los modales complejos");
DTOLeccion leccion7(1, "Lectura y comprension de textos", "Analizar el contenido, vocabulario y estructuras gramaticales utilizadas");

DTOEjercicio ejercicio1("Presentaciones", "Mucho gusto en conocerte", TRADUCCION, "Nice to meet you");
DTOEjercicio ejercicio2("Presentaciones formales", "Please -- me to introduce --", COMPLETAR, "allow, myself");
DTOEjercicio ejercicio3("Plurales regulares", "I have two brothers and three sisters", TRADUCCION, "Tengo dos hermanos y tres hermanas");
DTOEjercicio ejercicio4("Sustantivos contables en plural", "Can I have -- water, please?", COMPLETAR, "some");
DTOEjercicio ejercicio5("Actividades diarias", "Wake --", COMPLETAR, "up");
DTOEjercicio ejercicio6("Consultas de la hora", "Q: Do you -- the time? A: Yes, it is half -- 4", COMPLETAR, "have, past");
DTOEjercicio ejercicio7("Dar consejos o expresar obligacion", "You should visit that museum", TRADUCCION, "Deberías visitar ese museo");
DTOEjercicio ejercicio8("Imperativo", "Fale comigo", TRADUCCION, "Habla conmigo");

this->iPusuario->IngresoLeccion(curso1, leccion1, false, ejercicio1);
this->iPusuario->ingresarEjercicioTraduccion(curso1,leccion1,ejercicio1);

this->iPusuario->IngresoLeccion(curso1, leccion2, false, ejercicio2);//aca no agrgega ejercicio
this->iPusuario->ingresarEjercicioPalabra(curso1,leccion1,ejercicio2);

this->iPusuario->IngresoLeccion(curso2, leccion3, false, ejercicio3);
this->iPusuario->ingresarEjercicioTraduccion(curso1,leccion2,ejercicio3);

this->iPusuario->IngresoLeccion(curso2, leccion4, false, ejercicio4);
this->iPusuario->ingresarEjercicioPalabra(curso1,leccion2,ejercicio4);

this->iPusuario->IngresoLeccion(curso3, leccion5, false, ejercicio5);
this->iPusuario->ingresarEjercicioPalabra(curso2,leccion3,ejercicio5);

this->iPusuario->IngresoLeccion(curso4, leccion6, false, ejercicio6);
this->iPusuario->ingresarEjercicioPalabra(curso3,leccion5,ejercicio6);

this->iPusuario->IngresoLeccion(curso5, leccion7, false, ejercicio7);
this->iPusuario->ingresarEjercicioTraduccion(curso4,leccion6,ejercicio7);

this->iPusuario->IngresoLeccion(curso5, leccion7, false, ejercicio8);
this->iPusuario->ingresarEjercicioTraduccion(curso5,leccion7,ejercicio8);

this->iPusuario->Inscribir("Ingles para principiantes","jpidiom");
this->iPusuario->Inscribir("Ingles intermedio: mejora tu nivel","jpidiom");
this->iPusuario->Inscribir("Curso avanzado de ingles","jpidiom");
this->iPusuario->Inscribir("Ingles para principiantes","marsilva");
this->iPusuario->Inscribir("Ingles para principiantes","pero12");
this->iPusuario->Inscribir("Ingles para principiantes","laugu");

this->iPusuario->Inscribir("Portugues intermedio","laugu");
this->iPusuario->Inscribir("Portugues intermedio","carlo22");

}