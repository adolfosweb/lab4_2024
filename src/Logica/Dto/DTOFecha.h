#ifndef LOGICA_DTO_FECHA_H_
#define LOGICA_DTO_FECHA_H_
#include <iostream>

using namespace std;

class DTOFecha {
	//un DTO es un datatype, y un datatype debería de ser inmutable, por lo tanto
//teoricamente no puedo exponer el estado del objeto
//se implementan publicos para agilizar desarrollo del ejemplo
public:
	int dia;
	string mes;
	int anio;
	

	DTOFecha();
    DTOFecha(int dia, string mes, int anio);
	virtual ~DTOFecha();
};

#endif /* LOGICA_DTO_FECHA_H_ */