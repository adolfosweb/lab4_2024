#include "Curso.h"

Curso::Curso(/* args */)
{
}

Curso::~Curso()
{
}

bool Curso :: estaHabilitado()
{
    if(habilitado == true)
    {
        return true;
    }

    return false;
}