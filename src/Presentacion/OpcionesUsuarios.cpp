#include "OpcionesUsuarios.h"
#include "Pusuarios.h"
//#include "RealizarEjercicio.h"
#include "ListarUsuarios.h"


OpcionesUsuarios::OpcionesUsuarios(){}

OpcionesUsuarios::~OpcionesUsuarios(){}

void OpcionesUsuarios::mostrarMenuUsarios() {
	int op = 0;
	do {
		cout << "*** Menu Usuarios ***" << endl;
		cout <<"1) Alta Usuario" << endl;
		cout <<"2) Listar Usuarios " << endl;
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
				cout << "Listar Usuarios" << endl;
				Pusuarios listaUsuarios;
				listaUsuarios.listadoUsuarios();
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