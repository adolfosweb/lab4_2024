#ifndef PRESENTACION_PCURSO_H_
#define PRESENTACION_PCURSO_H_
#include "../src/Logica/Controller/Interface.h"
#include "../src/Logica/Dto/DTOCurso.h"
#include <map>
class PCurso
{
private:

   Interface *SystemInstance;

public:
   
    PCurso();
    ~PCurso(); 
    //CU5 Alta Curso
    void altaCurso();
    set<string> seleccionarCursos();
    //CU6 Agregar Ejercicio
    void AgregarLeccion();
    //CU7 Agregar Ejercicio
    void agregarEjercicio();
    //CU8 HabilitarCurso
    void habilitarCurso();
    //CU11 Inscribir curso
    void Inscripcion();
    //CU 13 Consultar estadísticas
    void consultaCurso();
    
};


    

#endif /* PCURSO_H_*/