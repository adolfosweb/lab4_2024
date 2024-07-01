#include "Inscripcion.h"

Inscripcion::Inscripcion(){
}
Inscripcion::Inscripcion(int dd,int mm,int aaaa, bool aprobado,Curso* curso)
{
   this->dd=dd;
   this->mm=mm;
   this->aaaa=aaaa;
   this->aprobado=aprobado;
   this->curso=curso;
}

Inscripcion::~Inscripcion(){
}

bool Inscripcion::getAprobado(){
    return this->aprobado;
}
void Inscripcion :: ObtenerPromedio()
{
   float prom = (*curso).obtenerPromedio();

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
   return (*curso).obtenerPromedio();
}

bool Inscripcion :: esCurso(string nombreCurso,string descripcion)
{
   if((*curso).getNombre() == nombreCurso && (*curso).getDescripcion() == descripcion)
   {
      return true;
   }
   else
   {
      return false;
   }

}
Curso* Inscripcion :: getCurso()
{
   return curso;
}

void Inscripcion :: setEjAprobado(Ejercicio* ejercicio){
   this->ejAprobados.insert(ejercicio);
}

set<Ejercicio*> Inscripcion :: getEjAprobados(){
   return this->ejAprobados;
}