#ifndef PERSONA_H_
#define PERSONA_H_
#include <string>

using namespace std;

class Persona {

private:
	int id;
	string nombre;

	//atributo de clase privado
	//static int contadorPrivado;


public:
	//atributo de clase publico
	//static int contador;

	Persona();
	Persona(int id, string nombre);
	virtual ~Persona();

	void setId(int id);
	int getId();


	void setNombre(string nombre);
	string getNombre();


	void mostrarInformacion();

	//un método también puede ser estático
	//static int obtenerContadorPrivado();

};


#endif /* EJERCICIO1_AUTOMOVIL_H_ */