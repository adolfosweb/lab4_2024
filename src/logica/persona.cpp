

#include <iostream>
#include "persona.h"
#include <string>

using namespace std;

//es necesario agregar esta definición fuera de la clase
//int Persona::contador = 0;
//int Persona::contadorPrivado = 0;

Persona::Persona(){
	//siempre que creo un automovil incremento el contador
	//contador++;
}

Persona::Persona(int id, string nombre) {
	Persona();	//desde un constructor puedo llamar a otro.
	this->id = id;
	this->nombre = nombre;

}

Persona::~Persona() {

}

void Persona::setNombre(string nombre){
	this->nombre = nombre;
}
string Persona::getNombre() {
	return this->nombre;
}

void Persona::setId(int id) {
	this->id = id;
}

int Persona::getId(){
	return this->id;
}


void Persona::mostrarInformacion(){
	string info = "Información de la persona: ";
	info = info + "id " + to_string(this->id) +	" nombre: " + this->nombre;
	cout << info << endl;

}

