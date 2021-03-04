#ifndef VISTAREPORTES_H_INCLUDED
#define VISTAREPORTES_H_INCLUDED
#include "../Modelo/validador.h"
#include "../Controlador/controlador.h"

//Interfaz grafica para reportes. Clase abstracta de la cual heredan demás reportes.

class vistaReportes
{
private:
    int i;
public:
    void opciones();
};

#endif // VISTAREPORTES_H_INCLUDED
