#ifndef LOGICA_DTO_EJERCICIO_H_
#define LOGICA_DTO_EJERCICIO_H_
#include "../Dominio/Ejercicio.h"
#include <iostream>

using namespace std;

class DTOEjercicio {
private:
    string descripcion;
    string frase;
    string solucion;
    ENUMTipo tipo;
public:	
	DTOEjercicio(string descripcion, string frase, string solucion);
	virtual ~DTOEjercicio();
    string getDescripcion();
    string getFrase();
    string getSolucion();
    ENUMTipo getTipo();
};

#endif /* LOGICA_DTO_EJERCICIO_H_ */