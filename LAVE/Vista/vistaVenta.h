#ifndef VISTAVENTA_H_INCLUDED
#define VISTAVENTA_H_INCLUDED
#include "../Modelo/venta.h"

class vistaVenta
{
private:
    Venta auxiliar;
public:
    void encabezado();
    void montoAcumulado();
    void cargaDeVenta();
    void msjExito(int i);
    void msjError(int i);
};

#endif // VISTAVENTA_H_INCLUDED
