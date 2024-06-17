/*
 * MenuPpal.cpp
 *
 *  Created on: 10 jun 2024
 *      Author: gabriel
 */

#include "Menu.h"
#include "AltaUsuario.h"
//#include "RealizarEjercicio.h"
#include <iostream>

using namespace std;

Menu::Menu() {

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}

void Menu::mostrarMenu() {
	int op = 0;
	do {
		cout << "*** Menu principal ***" << endl;
		cout <<"1) Alta Usuario" << endl;
		cout <<"2) Realizar Ejercicio " << endl;
		cout <<"3) Salir " << endl;
		cout <<"Ingrese una opcion: " << endl;

		cin >> op;
		switch (op) {
			case 1: {
				AltaUsuario altaUsuario;
				altaUsuario.altaUsuario();
			}
			break;
		case 2:
			{
			//RealizarEjercicio realizarEjercicio;
			//realizarEjercicio.realizarEjercicio();
			}
			break;
		case 3:
			break;
		default:
			cout << "Opcion desconocida" << endl;
		}

	} while (op != 3);

cout << "Fin del programa" << endl;
}