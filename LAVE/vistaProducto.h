#ifndef VISTAPRODUCTO_H_INCLUDED
#define VISTAPRODUCTO_H_INCLUDED
#include "../Modelo/producto.h"
//#include "../Modelo/validador.h"

class vistaProducto {
    private:
        Producto auxiliar;
    public:
        void cargaDeProducto();
        bool bajaDeProducto(Producto);
        void msjExito(int i);
        void msjError(int i);
        void setPrecio(float f);
        Producto getProducto();
};

#endif // VISTAPRODUCTO_H_INCLUDED
