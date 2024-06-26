#include "Curso.h"
#include <string>
Curso::Curso()
{
}
Curso::Curso(string nombre,string descripcion)
{
    this->nombre=nombre;
    this->descripcion=descripcion;
    //this->enum1=enum1;
    //this->idioma=idioma;
}
Curso::~Curso()
{
}
string Curso::getNombre()
{
    return this->nombre;
}
bool Curso :: estaHabilitado()
{
    if(habilitado == true)
    {
        return true;
    }

    return false;
}