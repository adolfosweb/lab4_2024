#include "OpcionesIdioma.h"
#include "AltaIdioma.h"
  OpcionesIidoma::OpcionesIidoma(){}
    OpcionesIidoma::~OpcionesIidoma(){}
   void OpcionesIidoma::mostrarMenuIdioma(){
    int op = 0;
	do {
		cout << "*** Menu Usuarios ***" << endl;
		cout <<"1) Alta Idioma" << endl;
		cout <<"2) Listar Idioma " << endl;
        cout <<"3) Volver A Menu Pricipal " << endl;
		cout <<"Ingrese una opcion: " << endl;

		cin >> op;
		switch (op) {
		case 1: {
				
			}
			break;
		case 2:
			{
			
			}
			break;
        case 3:
			{
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