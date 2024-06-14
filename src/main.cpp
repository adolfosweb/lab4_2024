#include <iostream>
#include <string>
#include "persona.h"


using namespace std;

int main()
{
    cout << "Hello world!" << endl;
    string nombre = "Adolfos";
    cout << nombre;
    Persona p1(1,nombre);
    p1.mostrarInformacion();
    return 0;
}
// Fue el Gaby 
// yo adolfo