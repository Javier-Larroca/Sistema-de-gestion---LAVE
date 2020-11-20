#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

class Producto{
    private:
        int id;
        char nombre[50];
        char descripcion[50];
        float precio;
        bool estado;
    public:
        Producto();
        Producto(char *n, char *c,float p);
        void setPrecio(float);
        float getPrecio();
        int getId();
        const char *getNombre();
        const char *getDescripcion();
        bool escribirDisco(int p);
        bool leerDisco(int p);
};

#endif // PRODUCTO_H_INCLUDED

