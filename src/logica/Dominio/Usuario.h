#ifndef LOGICA_USUARIO_H_
#define LOGICA_USUARIO_H_
#include <iostream>
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
	virtual string getNombre();
	virtual string getNick();
    virtual string getPass();
    virtual string getNom();
    virtual string getDescrip();
};

#endif /* LOGICA_USUARIO_H_ */
