/*
 * MenuPpal.cpp
 *
 *  Created on: 10 jun 2024
 *      Author: gabriel
 */

#include "Menu.h"
#include "OpcionesUsuarios.h"

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
		cout <<"1) Menu Opciones para Usuarios" << endl;
		cout <<"3) Menu Opciones para Idiomas" << endl;
		cout <<"0) Salir " << endl;
		cout <<"Ingrese una opcion: " << endl;

		cin >> op;
		switch (op) {
			case 1: {
				std::system("clear");
				OpcionesUsuarios opcionesUsuarios;
				opcionesUsuarios.mostrarMenuUsarios();
			}
			break;
		case 2:
			{
			std::system("clear");
			}
			break;
		case 0:
			break;
		default:
			cout << "Opcion desconocida" << endl;
		}

	} while (op != 0);

cout << "Fin del programa" << endl;
}