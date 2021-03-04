#ifndef VENTA_H_INCLUDED
#define VENTA_H_INCLUDED
#include "usuario.h"
#include "producto.h"

class Venta {
private:
    int id;
    char usuario[50];
    int cantProductos;
    float montoTotal;
public:
    Venta();
    void setValores(char *u, int c, float m); //Constructor para generar una venta con esos valores
    int getMontoTotal();
    int setMontoTotal();
    char *getUsuarioDeVenta();
    Producto *getProductosVendidos();
    Producto *setProductoVendidos();
};

#endif // VENTA_H_INCLUDED
