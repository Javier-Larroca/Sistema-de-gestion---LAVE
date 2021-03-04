#ifndef VISTAVENTA_H_INCLUDED
#define VISTAVENTA_H_INCLUDED
#include "../Modelo/venta.h"

class vistaVenta
{
private:
    Venta auxiliar;
    Producto listaProductos[20];
    float montoDeVenta;
    char usuario[50];
    char tecla;
    bool terminarVenta;
public:
    vistaVenta(char *u);
    Venta getVenta();
    void encabezado();
    void productosAcumulado(int cant);
    void montoAcumulado();
    float getMontoDeVenta();
    void cargaDeVenta(Producto *lista, int cantProd); //Le paso el vector de productos cargados en el controlador y la cantidad
    void msjExito();
    void msjError();
    void msjErrorListaProd();
};

#endif // VISTAVENTA_H_INCLUDED
