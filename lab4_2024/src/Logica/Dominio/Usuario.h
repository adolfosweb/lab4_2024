#ifndef LOGICA_USUARIO_H_
#define LOGICA_USUARIO_H_
#include <iostream>
#include "../Dto/DTOCurso.h"
#include "../Dominio/Inscripcion.h"
#include <map>

using namespace std;

class Usuario {
protected:
	string nick;
	string pass;
	string nom;
	string descrip;

public:
	Usuario();
	Usuario(string nick, string pass, string nom, string descrip);
	virtual ~Usuario();
	 string getNick();
     string getPass();
     string getNom();
     string getDescrip();
	 virtual bool esProfesor()= 0;
	 virtual void setCurso(Curso* curso)=0;
	 virtual set<string> listoIdiomaProfesor()=0;
	 virtual string seleccionarIdioma(string idiomaProf)=0;
	 virtual map<int,Inscripcion*> obtenerCursosInscriptos() = 0;
	 virtual set<Curso*> ObtenerCursos() = 0;
};

#endif /* LOGICA_USUARIO_H_ */

