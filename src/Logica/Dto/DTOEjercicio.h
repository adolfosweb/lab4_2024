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
	DTOEjercicio(string descripcion, string frase,ENUMTipo tipo, string solucion);
	virtual ~DTOEjercicio();
    string getDescripcion() const;
    string getFrase() const;
    string getSolucion() const;
    ENUMTipo getTipo() const;
    string tipoToString(ENUMTipo tipo) const;
    bool operator<(const DTOEjercicio& l) const;
};

#endif /* LOGICA_DTO_EJERCICIO_H_ */