#include "Controller.h"
#include "../Dto/DTOEstudiante.h"
#include "../Dto/DTOUsuario.h"
#include "../Dto/DTOProfesor.h"
#include "../Dto/DTOCurso.h"
#include "../Dominio/Estudiante.h"
#include "../Dominio/Profesor.h"
#include "../Dominio/Usuario.h"
#include "../Dominio/Idioma.h"
#include "../Dominio/Curso.h"
#include <set>


Controller::Controller() {
	//obtendo la unica instancia del Sistema
	this->sistema = Sistema::getInstance();
}

bool Controller::verificarNick(string nick) {
	//recorro los usuarios del sistema
	bool result = false;

	set<Usuario*>::iterator it;

	for (it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) {
		if (nick == (*it)->getNick()) {
			result = true;
			break;
		}
	}
	return result;
}

set<string> Controller::listIdiomas() {
	//recorro los idiomas del sistema y retorno una set de string
	set<string> result;

	set<Idioma*>::iterator it;
	for (it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
		result.insert((*it)->getIdioma());
	}
	return result;
}

void Controller::agregarUsuario(DTOUsuario* usuario) {
	Usuario *nuevoUsuario;
	DTOEstudiante* dtoEst = dynamic_cast<DTOEstudiante*>(usuario);
	//hago un casting para determinar el tipo de instancia
	if (dtoEst != nullptr) {
		//es un estudiante
		nuevoUsuario = new Estudiante(dtoEst->getNick(), dtoEst->getPass(),dtoEst->getNom(), dtoEst->getDescripcion(), dtoEst->getPaisResidencia(),dtoEst->getFecha());
	} else {
		DTOProfesor* dtoProf = dynamic_cast<DTOProfesor*>(usuario);

		//si no es un estudiante asumo que es un profesor
		nuevoUsuario = new Profesor(dtoProf->getNick(), dtoProf->getPass(), dtoProf->getNom(), dtoProf->getDescripcion(), dtoProf->getInstituto());

		//recorro la lista de idiomas del DTO enviado
		set<string>::iterator it;
		set<string> ListaIdiomaDTO= dtoProf->getIdiomas();
		for (it = ListaIdiomaDTO.begin(); it != ListaIdiomaDTO.end(); it++) {
			Idioma* idioma = this->sistema->buscarIdioma((*it));

			(dynamic_cast<Profesor*>(nuevoUsuario))->agregarIdioma((idioma));

		}
	}

	this->sistema->usuarios.insert(nuevoUsuario);
}


//CU2 Consulta de Usuario
//>ListarUsuarios
set<string>  Controller::listadoUsuarios() {
	//recorro los usuarios del sistema y los cargo en un SET.
	//bool result = false;

	set<string> listaUsuarios;

	set<Usuario*>::iterator it;
	int num = 0;
	for (it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) {
		num = num + 1;
		string nickUsuario;
		nickUsuario += to_string(num);
		nickUsuario += " - ";
		nickUsuario += (*it)->getNick();
		//cout << nickUsuario << endl;
		listaUsuarios.insert(nickUsuario);
		
	}
	return listaUsuarios;
}

//CU2 FIN Consulta de Usuario

//CU3 Alta idioma
void Controller::altaIdioma(string idioma){

	bool result = true;
	set<Idioma*>::iterator it;
	for (it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
		
		if (idioma == (*it)->getIdioma()) {
			result = false;
			
			break;
		}
	}
	
	if(result){
		Idioma *I = new Idioma(idioma);

		this->sistema->idiomas.insert(I);
		cout<<"Se a Agregado el Idioma"<<endl;
	}else{
		cout<<"El Idioma ya existia en sistema"<<endl;
	}

}
//FIN CU3 Alta idioma

set<string> Controller::consultarIdioma(){

	set<string> result; // strings que devuelvo a la capa de presentacion

	set<Idioma*>::iterator it;

	for (it = this->sistema->idiomas.begin(); it != this->sistema->idiomas.end(); it++) {
		string aux=(*it)->getIdioma();
		result.insert(aux);
		}
	return result;

	
}
//CU 5 Alta Curso
void Controller::altaCurso(string nombre,string descripcion, DTOIdioma *idioma, ENUMDificultad dificultad, bool habilitado,string nombreProf,set<string> previa,DTOLeccion nuevaLeccion)
{
	string select="";
	string idiomaProf;
	Profesor* nom;
	Curso* nuevocurso;
	bool resultNick = true;
	bool result = true;
	set<Curso*>::iterator it;
	set<Usuario*>::iterator itr;

	for (it = this->sistema->cursos.begin(); it != this->sistema->cursos.end(); it++) 
	{
		
		if (nombre == (*it)->getNombre()) 
		{
			result = false;			
			break;
		}
	}
	for(auto ct = sistema->usuarios.begin(); ct != sistema->usuarios.end(); ct++ )
	{
		if((*ct)->esProfesor() && (*ct)->getNick()==nombreProf)
		{
			(*ct)->listoIdiomaProfesor();

			cout<<"Ingrese el Idioma: "<<endl;
			getline(cin,idiomaProf);
			getchar();
			
			select = (*ct)->seleccionarIdioma(idiomaProf);
			resultNick = true;
			nom = dynamic_cast<Profesor*>(*ct);
		}
		else
		{
			resultNick= false;
		}
	}
	if(result && resultNick)
	{
		Curso *C1=nullptr;
		if (select != "")
		{
			Curso *C1 = new Curso(nombre,descripcion,idioma,dificultad,habilitado);
			this->sistema->cursos.insert(C1);	
		}
		else
		{
			cout<<"Profesor no tiene ese idioma"<<endl;
		}
		DTOCurso Cur1(nombre,descripcion, idioma, dificultad,habilitado);
		if (C1 != nullptr && IngresoLeccion(Cur1,nuevaLeccion))
		{
			cout<<"Leccion ingresada"<<endl;
		}
		else
		{
			cout<<"Error de ingreso"<<endl;
		}
		if (C1 != nullptr)
		{
		
		//nom->asociarCurso(C1);
		nom->setCurso(C1->getNombre());

	if(result){
		Curso *C1 = new Curso(nombre,descripcion,*itr2,dificultad,habilitado);
		this->sistema->cursos.insert(C1);	
	
		set<Curso*> result;
		//set<string> aux;
		set<string>::iterator strC;
		set<Curso*>::iterator cur;
		for (cur= this->sistema->cursos.begin(); cur != this->sistema->cursos.end(); cur++) 
		{
			for (strC= previa.begin(); strC != previa.end(); strC++) {
				if((*cur)->getNombre()==*strC){
					result.insert((*cur));
				}
			}
			
		}
		C1->setAllPrevias(result);

		cout<<"Se creo el Curso"<<endl;
		}
		nom->setCurso(C1);
		
	}else
	{
		cout<<"El Curso ya existia en sistema o Nick de Estudiante"<<endl;
		
	}
	getchar();
}
set<string> Controller::listaCursos()
{
	set<string> result;

	set<Curso*>::iterator it;
	for (it = this->sistema->cursos.begin(); it != this->sistema->cursos.end(); it++) 
	{
		result.insert((*it)->getNombre());
	}
	return result;
}
void Controller :: listoProfesor()
{
    set<Usuario*>::iterator it;
    for (it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) 
    {	
        if ((*it)->esProfesor())
        {
            cout << ": " << (*it)->getNick() << endl;	
        }
    }
}
//FIN CU 5 Alta Curso

//CU 6 Agregar Leccion
map<int,DTOCurso> Controller :: ConsultaCursosNoHabilitados()
{

	map<int,DTOCurso> CursosNoHab;	//Se crea map vacío.

	int cont = 1;

	for(auto ct = sistema->cursos.begin(); ct != sistema->cursos.end(); ct++ )
	{

		if( ! (*ct)->estaHabilitado()) //Si no está habilitado...
		{
			//Se crea ese DataType con los valores indicados...
			DTOCurso Temp((*ct)->getNombre(),(*ct)->getDescripcion(), (*ct)->getIdioma(), (*ct)->getDificultad(),(*ct)->estaHabilitado());
			//Ingreso al map...
			CursosNoHab.insert({cont,Temp});
			cont ++;
		}

	}

	return CursosNoHab;

}

bool Controller :: IngresoLeccion(DTOCurso curso, DTOLeccion leccion)
{

	for(auto ct = sistema->cursos.begin(); ct != sistema->cursos.end(); ct++ )
	{

		if((*ct)->getNombre() == curso.getNombreCurso() && (*ct)->getDescripcion() == curso.getDescripcion()) //Busca curso...
		{
			(*ct)->setLeccion(leccion);
			return true;
		}
	}
	return false;
}

//CU Consultar estadísticas (estudiante)
void Controller :: listarEstudiantes()
{
    set<Usuario*>::iterator it;
    for (it = this->sistema->usuarios.begin(); it != this->sistema->usuarios.end(); it++) 
    {	
        if (!(*it)->esProfesor())
        {
            cout << ": " << (*it)->getNick() << endl;	
        }
    }
}

void Controller :: consultarStatsEstudiante(string nick)
{
	//Se obtiene instancia de estudiante... 
	for(auto ct = sistema->usuarios.begin(); ct != sistema->usuarios.end(); ct++)
	{
		if (!(*ct)->esProfesor() && (*ct)->getNick() == nick)	//Mientras no sea profesor y coincida el nick
		{
			map<int,Inscripcion*> cie = (*ct)->obtenerCursosInscriptos(); // Se obtienen Cursos Inscriptos Estudiante
			
			for(auto ct = cie.begin(); ct != cie.end(); ct++)
			{
				cout << "Curso Número " << ct->first << endl;	//Por cada curso...
				ct->second->ObtenerPromedio();					//Su promedio...
			}
			
		}

	}

}
void Controller :: consultarStatsProfesor(string nick)
{
	//Se obtiene instancia de profesor... 

	set<Curso*> cursosProf;

	for(auto ct = sistema->usuarios.begin(); ct != sistema->usuarios.end(); ct++)
	{
		if ((*ct)->esProfesor() && (*ct)->getNick() == nick)	//Mientras sea profesor y coincida el nick
		{
			
			cursosProf = (*ct)->ObtenerCursos();	//Se obtienen sus cursos.

		}

	}

	for(auto ct = cursosProf.begin(); ct != cursosProf.end(); ct++)	//Por cada curso del profesor
	{	 
		map<int,Inscripcion*> cursosEst;

		float prom  = 0, 					//Promedio final del curso
			  total = 0;					//Suma de promedio de estudiantes.
		int cantEst = 0;					//Cantidad de estudiantes que cursaron.				

		if((*ct)->estaHabilitado())	//Si es un curso habilitado
		{
			cout << "Curso: " << (*ct)->getNombre();
			
			for(auto tt = sistema->usuarios.begin(); tt!= sistema->usuarios.end(); tt++)
			{
				cursosEst.clear();	//Se vacía el map

				if (!(*tt)->esProfesor())	//Si es estudiante
				{
					cursosEst = (*tt)->obtenerCursosInscriptos();	//Guarda inscripciones del estudiante.
					
					for(auto it = cursosEst.begin(); it != cursosEst.end(); it ++)
					{	
						if(it->second->esCurso((*ct)->getNombre(),(*ct)->getDescripcion()))	//Verifica que se trate del mismo
						{
							cantEst ++;
							total =	total + it->second->ObtenerDatoPromedio();
						}
					
					}
				
				}

			}
		
			prom = total/cantEst;

			if(prom != 0 && cantEst != 0)
			{
				cout << " - Promedio: " << prom << "%" << endl;
			}
			else
			{
				cout << "No ha sido cursado." << endl;
			}

		}
	}

}

map<int,DTOCurso> Controller :: ConsultaCursosHabilitados()
{

	map<int,DTOCurso> CursosHab;	//Se crea map vacío.

	int cont = 1;

	for(auto ct = sistema->cursos.begin(); ct != sistema->cursos.end(); ct++ )
	{

		if( ! (*ct)->estaHabilitado()) //Si no está habilitado...
		{
			//Se crea ese DataType con los valores indicados...
			DTOCurso Temp((*ct)->getNombre(),(*ct)->getDescripcion(), (*ct)->getIdioma(), (*ct)->getDificultad(),(*ct)->estaHabilitado());
			//Ingreso al map...
			CursosHab.insert({cont,Temp});
			cont ++;
		}

	}

	return CursosHab;

}

float Controller :: obtenerPromedioCurso(DTOCurso curso)
{
	map<int,Inscripcion*> inscripcionesEst;	//Almacén temporal de cursos de estudiantes.
	float total = 0;
	int cantEst = 0;
 
	for(auto ct = sistema->usuarios.begin(); ct != sistema->usuarios.end(); ct++)
	{
		inscripcionesEst.clear();	//Se vacía almacén de cursos para el siguiente estudiante...

		if (!(*ct)->esProfesor())	//Mientras sea estudiante
		{	
			inscripcionesEst = (*ct)->obtenerCursosInscriptos();
			
			for(auto tt = inscripcionesEst.begin(); tt != inscripcionesEst.end(); tt++)
			{
					
				if((*tt).second->esCurso(curso.getNombreCurso(),curso.getDescripcion()))	//Si se encuentra curso...
				{
					cantEst++;
					total = total + (*tt).second->ObtenerDatoPromedio();
				}
			}

		}

	}

	if(cantEst != 0)
	{
		return total/cantEst;
	}
	
	
	return 0;
	
}