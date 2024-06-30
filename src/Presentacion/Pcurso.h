#ifndef PRESENTACION_PCURSO_H_
#define PRESENTACION_PCURSO_H_
#include "../Logica/Controller/Interface.h"
#include "../Logica/Dto/DTOCurso.h"
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
    //CU9 Eliminar Curso
    void eliminarCurso();
    DTOEjercicio crearDTOejercicio(int num);
    //CU 10 ConsultarCurso();
    void consultarCurso();
    //CU11 Inscribir curso
    void Inscripcion();
    //CU 13 Consultar estadísticas
    void consultaEstaditicaDeCurso();
    
};


    

#endif /* PCURSO_H_*/