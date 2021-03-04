#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "usuario.h"
#include "producto.h"


class Venta {
private:
    int id;
    char *usuario;
    Producto *p;
    int montoTotal;
public:
    Venta();
    int getMontoTotal();
    int setMontoTotal();
    char *getUsuarioDeVenta();
    Producto *getProductosVendidos();
};

#endif // VENTA_H_INCLUDED
