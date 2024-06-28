#ifndef LOGICA_USUARIO_H_
#define LOGICA_USUARIO_H_
#include <iostream>
#include "../Dto/DTOCurso.h"
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
	 virtual void setCurso(string curso)=0;
	 virtual void listoIdiomaProfesor()=0;
};

#endif /* LOGICA_USUARIO_H_ */
