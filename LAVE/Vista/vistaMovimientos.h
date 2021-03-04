#ifndef VISTAMOVIMIENTOS_H_INCLUDED
#define VISTAMOVIMIENTOS_H_INCLUDED
#include "../Modelo/validador.h"
#include "../Controlador/controlador.h"

//Interfaz grafica para menu Movimientos

class vistaMovimientos
{
private:
    char cajero[50];
public:
    vistaMovimientos(char *u);
    void opciones();
    char *getCajero();

};

#endif // VISTAMOVIMIENTOS_H_INCLUDED
