#include <iostream>
#include <set>
#include "../Logica/Controller/Controller.h"
#include "../Logica/Dominio/Usuario.h"
#include "../Logica/Dto/DTOCurso.h"
#include "Pcurso.h"
PCurso::PCurso()
{
    this->SystemInstance = new Controller();
}

PCurso::~PCurso()
{
    delete this->SystemInstance;
}

//CU 5 AltaCurso
void PCurso::altaCurso(){
    std::system("clear");

    string nombre = "", 
    objetivoAprendizaje = "", 
    tema = "", 
    descripcion = "";

    ENUMDificultad dif;
    int difInt = 0;

    bool habilitado = false;

    cin.ignore();

    cout << "Ingrese Nombre del Curso:" << endl;
    getline(cin, nombre);

    cout << "Ingrese una Descripcion:" << endl;
    getline(cin, descripcion);

    cout << "Ingrese la dificultad (0: Fácil, 1: Intermedio, 2: Avanzado):" << endl;
    cin >> difInt;
    cin.ignore();
    
    dif=obtenerDificultad(difInt); 
    string nombreProf=obtenerNombreDelProfesor(); //
    string idioma=obtenerIdiomasDeProfesor(nombreProf);
  
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

    this->SystemInstance->altaCurso(nombre, descripcion, idioma, nombreProf, dif, habilitado, previas);
}
ENUMDificultad PCurso::obtenerDificultad(int num){
    ENUMDificultad dif;
    switch (num) {
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
    return dif;
}
string PCurso::obtenerNombreDelProfesor(){

    cout << "Lista de Profesores:" << endl;
    set<string> listaProf = this->SystemInstance->listoProfesor();//Me traigo los nombres de los profesores

    set<string>::iterator it;
    for (it = listaProf.begin(); it != listaProf.end(); it++) //Recorro
    {
        cout << "Profesor: " << *it << endl;
    }
    string nombreProf;
    bool existeUsuario = false;
    while (existeUsuario == false){ //while para controlar si el nombre introducido coincide con lo listado

        cout << "Ingresa un usuario de la lista:" << endl;
        cin >> nombreProf;
        existeUsuario = this->SystemInstance->verificarNick(nombreProf);

        if (existeUsuario == false)
        {
            cout << "el nick ingresado no es correcto" << endl;
        }
    }
    return nombreProf;
}
string PCurso::obtenerIdiomasDeProfesor(string nombreProfe){
    set<string> idiomasProfesor = this->SystemInstance->idiomasProfesor(nombreProfe);
    cout << "Lista de Idioma del Profesor:" << endl;
    set<string>::iterator it2;

    for (it2 = idiomasProfesor.begin(); it2 != idiomasProfesor.end(); it2++){
        cout << "Idioma: " << *it2 << endl;
    }

    string idioma;
    bool existeIdioma = false;
    while (!existeIdioma)
    {
        cout << "Ingresa un Idioma de la lista:" << endl;
        cin >> idioma;

        if (idiomasProfesor.find(idioma) != idiomasProfesor.end()){
            existeIdioma = true;
        }else{
            cout << "El idioma ingresado no es correcto. Por favor, intenta nuevamente." << endl;
        }
    }
    return idioma;
}
set<string> PCurso::seleccionarCursos()
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
                // solo selecciono los cursos que existen
                CursosSeleccionados.insert(curs);
                cout << "Previa ingresado: " << curs << endl;
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
    } while (quiereIngresarcurso);

    return CursosSeleccionados;
}
//FIN CU5 Alta Curso

//CU 6 AgregarLeccion
void PCurso::AgregarLeccion(){
    DTOCurso curso=ObtenerCurso();

    string nombreLeccion = "", 
    objetivo = "";
    char sel = ' ';

    cin.ignore();
    cout << "\nIngrese nombre de la nueva lección:" << endl;
    getline(cin, nombreLeccion, '\n');

    cout << "\nIngrese objetivo de la lección:" << endl;
    getline(cin, objetivo, '\n');

    cout << "\nDesea ingresar También los ejercicios? S/N" << endl;
    sel = getchar();
    DTOEjercicio eje;
    bool agregarEjercicio = false;
    if (sel == 'S' || sel == 's')
    {
        cout<<"Elija que tipo de Ejercicio quere ingresar (1=Ejercicio de Completar Palabra, 2=Ejercicio de traduccion):"<<endl;
        int num;
        cin>>num;
        cin.ignore();
        eje=crearDTOejercicio(num);
        agregarEjercicio = true;
    }

    DTOLeccion NuevaLeccion(0, nombreLeccion, objetivo);

    if (SystemInstance->IngresoLeccion(curso, NuevaLeccion,agregarEjercicio,eje)){ // Se pasa el DTOCurso y DTOLeccion.
        cout << "\nIngreso Completado..." << endl;
    }
}
DTOCurso PCurso::ObtenerCurso(){
    map<int, DTOCurso> Temp;
    cout << "\nAgregando Lección.\nListando no Habilitados:\n"
         << endl;
    Temp = SystemInstance->ConsultaCursosNoHabilitados();

    for (auto ct = Temp.begin(); ct != Temp.end(); ct++)
    {
        cout << "Código Curso: C " << ct->first << endl;
        ct->second.MostrarDatos();
    }

    int in = 0;
    bool cursoAceptado = false;
    // string ingreso = "";

    while (!cursoAceptado)
    {
        cout << "\nIngrese el curso a seleccionar..." << endl;
        cin >> in;

        if (in >= 1 && in <= Temp.size())
        {
            cursoAceptado = true;
        }
        else
        {
            cout << "Número fuera de rango. Por favor, ingrese un número entre 1 y " << Temp.size() << "." << endl;
        }
    }
    auto Cur = Temp.find(in);
    return Cur->second;
}

//CU7
void PCurso::agregarEjercicio(){
    map<int,DTOCurso> cursos= this->SystemInstance->ConsultaCursosNoHabilitados();

    for (auto ct = cursos.begin(); ct != cursos.end(); ct++){
        cout << "Código Curso: C" << ct->first <<" "<< ct->second.getNombreCurso()<< endl;    
    }

    int in = 0;
    bool cursoAceptado = false;

    while (!cursoAceptado)
    {
        cout << "\nIngrese el curso a seleccionar..." << endl;
        cin >> in;
        if (in >= 1 && in <= cursos.size()){
            cursoAceptado = true;
        }else{
            cout << "Número fuera de rango. Por favor, ingrese un número entre 1 y " << cursos.size() << "." << endl;
        }
    }

    auto Cur = cursos.find(in);

    set<DTOLeccion> lecciones=this->SystemInstance->listarLecciones(Cur->second.getNombreCurso());

    cout<<"Las Lecciones del curso llamado "<<Cur->second.getNombreCurso()<<" son :"<<endl;

    set<DTOLeccion>::iterator it;

    for (it = lecciones.begin(); it != lecciones.end(); it++) {
        cout<<"Leccion "<<it->getNumero() <<" "<< it->getTema()<<endl;	
    }

    string nombreLeccion;
    bool leccionAceptada = false;
    DTOLeccion aux;
    while (!leccionAceptada) {
        cout << "\nIngrese el nombre de la lección a seleccionar..." << endl;
        cin >> nombreLeccion;

    // Verificar si existe una lección con el nombre ingresado
    for (it = lecciones.begin(); it != lecciones.end(); it++) {
        if (it->getTema() == nombreLeccion) {
            leccionAceptada = true;
            aux=*it;
            break;
        }
    }

        if (!leccionAceptada) {
                cout << "Lección no encontrada. Por favor, ingrese un nombre de lección válido." << endl;
        }
    }

    cout<<"Elija que tipo de Ejercicio quere ingresar (1=Ejercicio de Completar Palabra, 2=Ejercicio de traduccion):"<<endl;
    int num;
    cin>>num;
    cin.ignore();
    
    DTOEjercicio eje=crearDTOejercicio(num);
    
    if(num==1){
        this->SystemInstance->ingresarEjercicioTraduccion(Cur->second,aux,eje);

    }else if(num==2){
        this->SystemInstance->ingresarEjercicioTraduccion(Cur->second,aux,eje);
    }

}

DTOEjercicio PCurso::crearDTOejercicio(int num){
    string descripcion="";
    string frase="";
    string solucion="";
    ENUMTipo tipo;

    if(num==1){
        cout<<"Ingrese Descripcion del Ejercicio"<<endl;  
        getline(cin,descripcion);

        cout<<"Ingrese La Frase incompleta"<<endl;  
        getline(cin,frase);

        cout<<"Ingrese La Frase completa"<<endl;  
        getline(cin,solucion);

        tipo=ENUMTipo::COMPLETAR;
    }else if(num==2){

        cout<<"Ingrese Descripcion del Ejercicio"<<endl;  
        getline(cin,descripcion);

        cout<<"Ingrese La Frase a Traduccir"<<endl;  
        getline(cin,frase);

        cout<<"Ingrese La Frase Traducida "<<endl;  
        getline(cin,solucion);
        tipo=ENUMTipo::TRADUCCION;
        

    }
    DTOEjercicio resu(descripcion, frase, tipo, solucion);
    return resu;
}
//FIN CU 7

// CU 8 HABILITAR CURSO
void PCurso::habilitarCurso()
{
    map<int, DTOCurso> cursoNoHabilitados;

    cursoNoHabilitados = this->SystemInstance->ConsultaCursosNoHabilitados();
    if (!cursoNoHabilitados.empty())
    {
        cout << "Los cursos no habilitados son: " << endl;

        for (auto ct = cursoNoHabilitados.begin(); ct != cursoNoHabilitados.end(); ct++)
        {
            cout << "Curso " << ct->first << " " << ct->second.getNombreCurso() << endl;
        }

        int numeroCurso;
        bool exiteCurso = false;

        while (!exiteCurso)
        {
            cout << "selecciona el numero de un curso a habilitar" << endl;

            cin >> numeroCurso;

            auto it = cursoNoHabilitados.find(numeroCurso);

            if (it != cursoNoHabilitados.end())
            {

                this->SystemInstance->habilitarCurso(it->second.getNombreCurso());
                exiteCurso = true;
            }
            else
            {
                cout << "El curso eleguido no existe" << endl;
            }
        }
    }
    else
    {
        cout << "No hay curso para habilitar" << endl;
    }
}
//CU9 Eliminar Curso
void PCurso::eliminarCurso(){
    std::system("clear");
    set<string> nombres;
    string opcion = "";
    int pos = 1;
    nombres = this->SystemInstance->listarNombreCursos();
    cin.ignore();
    if(!nombres.empty()){
        cout << "Cursos creados:" << endl; 
        for(auto it = nombres.begin(); it != nombres.end(); it++){
            cout << "Curso " << pos << ": " << *it << endl;
            pos++;
        }
        cout << "Seleccione curso a eliminar:" << endl;
        getline(cin,opcion);
        if(this->SystemInstance->seleccionarCursoAEliminar(opcion)){
            cout << "Se ha eliminado el curso: " << opcion << endl;
        }else{
            cout << "El curso: " << opcion << "no existe" << endl;
        }
    }else{
        cout << "No hay cursos creados" << endl;
    }
}
//FIN Eliminar curso

//CU 10 ConsultarCurso
void PCurso :: consultarCurso(){

    set<string> nombreCursos=this->SystemInstance->listaCursos();
    set<string>::iterator it;
	for (it = nombreCursos.begin(); it != nombreCursos.end(); it++) {
		cout << "Curso: " << *it << endl;
	}

    string nomCurso;
	bool existeIdioma = false;
    while (!existeIdioma)
    {
        cout << "Ingresa un Idioma de la lista:" << endl;
        cin >> nomCurso;
       
       if (nombreCursos.find(nomCurso) != nombreCursos.end()) {
        existeIdioma = true;
       }else {
        cout << "El curso ingresado no es correcto. Por favor, intenta nuevamente." << endl;
        }
    }
    std::system("clear");
    DTOCurso infoCurso=this->SystemInstance->consultarCurso(nomCurso);
    
    infoCurso.MostrarDatos();
}

// CU11 inscripcion
void PCurso ::Inscripcion()
{
    string nombreEst = "", nombreCurs = "";
    if (this->SystemInstance->listarUsuarios('e') != 0)
    {
        cout << "Ingrese Nombre del Estudiante:" << endl;
        getline(cin, nombreEst);

        this->SystemInstance->listoCursosPendientes(nombreEst);
        cout << "Ingrese Nombre del curso:" << endl;
        getline(cin, nombreCurs);

        if (this->SystemInstance->Inscribir(nombreCurs, nombreEst))
        {
            cout << "Se realizo la inscripcion" << endl;
        }
        else
        {
            cout << "Error de inscripcion" << endl;
        }
    }
    else
    {
    cout << "No hay usuarios" << endl;
    }
}


void PCurso ::consultaEstaditicaDeCurso()
{
    map<int, DTOCurso> cursos = SystemInstance->ConsultaCursosHabilitados();
    // string ingreso = "";
    int seleccion = 0;
    int advisor = 0;

    // Se comprueba que hayan cursos habilitados disponibles.
    for (auto ct = cursos.begin(); ct != cursos.end(); ct++)
    {
        if (ct->second.estaHabilitado())
        {
            advisor++;
        }
    }

    if (!cursos.empty()) // Mientras mapa no esté vacío.
    {

        if (advisor != 0)
        {
            cout << "Mostrando todos los cursos: " << endl;

            for (auto ct = cursos.begin(); ct != cursos.end(); ct++)
            {
                if (ct->second.estaHabilitado())
                {
                    cout << "Código Curso: C" << ct->first << "Nombre Curso: " << ct->second.getNombreCurso() << endl;
                }
            }

            cout << "\nIngrese el curso a seleccionar." << endl;
            cin >> seleccion;

            // int seleccion = stoi(ingreso);  //Solo almacenará el número del ingreso.

            auto Cur = cursos.find(seleccion);                                  // Se obtiene DTOCurso
            float promedio = SystemInstance->obtenerPromedioCurso(Cur->second); // Se obtiene el promedio de ese curso entre todos los estudiantes.

            Cur->second.MostrarDatos();

            if (promedio != 0)
                cout << "Promedio total de este Curso: " << promedio << "%" << endl;
            else
                cout << "No hay estudiantes que hayan cursado/aprobado este curso." << endl;
            getchar();
            getchar();
        }
        else
        {
            cout << "\nNo existen cursos habilitados actualmente." << endl; // Mensaje error.
            getchar();
            getchar();
        }
    }
    else
    {
        cout << "\nNo existen cursos registrados." << endl; // Mensaje error.
        getchar();
        getchar();
    }
}
