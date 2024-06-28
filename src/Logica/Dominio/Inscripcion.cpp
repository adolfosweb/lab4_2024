#include "Inscripcion.h"

Inscripcion::Inscripcion(){
}
//Inscripcion::Inscripcion(dtfecha fecha, bool aprobado){}

Inscripcion::~Inscripcion(){
}

bool Inscripcion::getAprobado(){
    return this->aprobado;
}


void Inscripcion :: ObtenerPromedio()
{
   float prom = (*Curso).obtenerPromedio();

   if(prom != 0)
   {
      cout << "- Promedio: " << prom << "%" << endl;
   }
   else
   {
     cout << "- Promedio: 0%" << endl;
   }
}

float Inscripcion :: ObtenerDatoPromedio()
{
   return (*Curso).obtenerPromedio();
}

bool Inscripcion :: esCurso(string nombreCurso,string descripcion)
{
   if((*Curso).getNombre() == nombreCurso && (*Curso).getDescripcion() == descripcion)
   {
      return true;
   }
   else
   {
      return false;
   }

}