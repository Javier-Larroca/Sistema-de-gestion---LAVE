#ifndef VISTAINICIOPRINCIPAL_H_INCLUDED
#define VISTAINICIOPRINCIPAL_H_INCLUDED
#include "../Controlador/controlador.h"
class VistaInicioPrincipal{
private:
    int opcion;
    char tecla;
    const char *flecha;
    int pos;
    bool exit;
public:
    VistaInicioPrincipal();
    void mostrar();
};


#endif // VISTAINICIOPRINCIPAL_H_INCLUDED
