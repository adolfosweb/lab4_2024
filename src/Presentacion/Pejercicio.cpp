#include <iostream>
#include <set>
#include "../Logica/Controller/Controller.h"
#include "../Logica/Dominio/Usuario.h"
#include "../Logica/Dto/DTOCurso.h"
#include "Pejercicio.h"
PEjercicio::PEjercicio()
{
    this->SystemInstance = new Controller();
}

PEjercicio::~PEjercicio()
{
    delete this->SystemInstance;
}



//CU12

void PEjercicio::realizarEjercicio(){
    // Listar usuarios
    this->SystemInstance->listarUsuarios('e');
    cout << "Ingrese nick estudiante: ";
    string nick;
    cin >>  nick;
    // Listar ejercicios
    this->SystemInstance->listarEjercicios(nick);
    // Seleccionar ejerccio
    // verificarRespuesta(respuestaEjercicio, descEjer)


}
//FIN CU 12
