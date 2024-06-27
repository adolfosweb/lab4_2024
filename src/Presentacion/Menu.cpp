/*
 * MenuPpal.cpp
 *
 *  Created on: 10 jun 2024
 *      Author: gabriel
 */

#include "Menu.h"
//#include "AltaUsuario.h"
//#include "RealizarEjercicio.h"
//#include "ListarUsuarios.h"
//#include "AltaIdioma.h"
#include "Pusuarios.h"
#include "Pidioma.h"
#include "Pcurso.h"
#include <iostream>

using namespace std;

Menu::Menu() {

}

Menu::~Menu() {
	// TODO Auto-generated destructor stub
}
				//MENU PRINCIPAL
void Menu::mostrarMenu() {
	int op = 0;
	do {
		cout << "*** Menu principal ***" << endl;
		cout <<"1) Opciones de Usuarios" << endl;
		cout <<"2) Menu de Opciones de idiomas" << endl;
		cout <<"3) Menu de Opciones de Curso" << endl;
		cout <<"0) Salir " << endl;
		cout <<"Ingrese una opcion: " << endl;
		cin >> op;
		switch (op) {
			case 1: {
				std::system("clear");
				mostrarMenuUsarios();
			}
			break;
		case 2:
			{
				std::system("clear");
				mostrarMenuIdioma();
			}
			break;
		case 3:
			{
				std::system("clear");
				mostrarMenuCursos();
			}
		case 0:
			break;
		default:
			cout << "Opcion desconocida" << endl;
		}

	} while (op != 0);

cout << "Fin del programa" << endl;
}

				/*MENU DE OPCIONES QUE INVOLUCRAN A USUARIOS*/
void Menu::mostrarMenuUsarios() {
	int op = 0;
	do {
		cout << "*** Menu Usuarios ***" << endl;
		cout <<"1) Alta Usuario" << endl;
		cout <<"2) Consulta de Usuario " << endl;
        cout <<"3) Volver A Menu Pricipal " << endl;
		cout <<"Ingrese una opcion: " << endl;

		cin >> op;
		switch (op) {
		case 1: {
				std::system("clear");
				Pusuarios altaUsuario;
				altaUsuario.altaUsuario();
			}
			break;
		case 2:
			{
				std::system("clear");
				cout << "Consulta de Usuario" << endl;
				Pusuarios consultaUsuario;
				consultaUsuario.infoUsuario();
			}
			break;
        case 3:
			{
				std::system("clear");
           		return ;
			}
			break;
		case 0:
			break;
		default:
			cout << "Opcion desconocida" << endl;
		}

	} while (op != 0);
}

				/*MENU DE OPCIONES QUE INVOLUCRAN A IDIOMA*/
void Menu::mostrarMenuIdioma()
{

    int op = 0;
	do {
		cout << "*** Menu de Idioma ***" << endl;
		cout <<"1) Alta Idioma" << endl;
		cout <<"2) Listar Idioma " << endl;
        cout <<"3) Volver A Menu Pricipal " << endl;
		cout <<"Ingrese una opcion: " << endl;

		cin >> op;
		switch (op) {
		case 1: {
				std::system("clear");
				cout << "Agregar Idioma" << endl;
				Pidioma opidioma;
                opidioma.altaIidoma();
			}
			break;
		case 2:
			{
				std::system("clear");
				Pidioma opidioma;
				opidioma.consultarIdioma();
			}
			break;
        case 3:
			{
				std::system("clear");
            	return ;
			}
			break;
		case 0:
			break;
		default:
			cout << "Opcion desconocida" << endl;
		}

	} while (op != 0);
   }
void Menu::mostrarMenuCursos()
   {
	    int op = 0;
	do {
		std::system("clear");
		cout << "*** Menu de Curso ***" << endl;
		cout <<"1) Alta Curso" << endl;
		cout <<"2) Agregar Leccion " << endl;
        cout <<"3) Agregar Ejercicio " << endl;
		cout <<"4) Habilitar Curso " << endl;
		cout <<"5) Eliminar Curso " << endl;
		cout <<"6) Consultar Curso " << endl;
		cout <<"7) Volver A Menu Pricipal "<< endl;
		cout <<"Ingrese una opcion: " << endl;
		PCurso datocurso;
		cin >> op;
		switch (op) {
		case 1: {
				std::system("clear");
				cout << "Agregar Curso" << endl;
				datocurso.altaCurso();
			}
			break;
		case 2:
			{
				std::system("clear");
				cout << "Agregar Leccion" << endl;
				datocurso.AgregarLeccion();
			}
			break;
        case 3:
			{
				std::system("clear");
            
			}
			break;
		case 4:
			{
				std::system("clear");
            
			}
			break;
		case 5:
			{
				std::system("clear");
            	
			}
			break;
		case 6:
			{
				std::system("clear");
            
			}
			break;
		case 7:
			{
				std::system("clear");
            	return;
			}
			break;
		case 0:
			break;
		default:
			cout << "Opcion desconocida" << endl;
		}

	} while (op != 0);
   }