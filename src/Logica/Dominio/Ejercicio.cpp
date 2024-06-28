#include "Ejercicio.h"

Ejercicio::Ejercicio(/* args */)
{
}

Ejercicio::~Ejercicio()
{
}

Ejercicio :: Ejercicio(string descripcion,bool aprobado): descripcion(descripcion), aprobado(aprobado) 
{}

bool Ejercicio :: getAprobado()
{
    return aprobado;
}