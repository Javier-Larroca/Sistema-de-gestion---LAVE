#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "usuario.h"
#include "producto.h"
#include "venta.h"
#include "fichaje.h"

/* A IMPLEMENTAR MAS ADELANTE.
enum Objeto{
usuario=1, //Si recibe numero 1, lo toma como Usuario
producto=2 //Si recibe numero 2, lo toma como Producto
};
*/

class Archivo{
    public:
    static int buscarUsuario(char *usuario, char *password, int *rol);
    static int buscarUsuario(Usuario &aux, int dni);
    static void creacionDeArchivoUsuario();
    static void cantidadDeObjetos(int *i, int tipoDeObjeto); //Objeto es un ENUM declarado arriba. No lo implementamos todavía.
    static bool guardarUsuario(Usuario &u);
    static bool bajaLogica(Usuario u, int  idInterno);
    static bool modificaRol(Usuario u, int idInterno);
    static bool guardarProducto(Producto &u);
    static bool guardarVenta(Venta &u);
    static int crearBackUpUsuario(); //Creo archivo de backup de usuario
    static int crearBackUpProducto(); //Creo archivo de backup de Producto
    static int restaurarBackUpUsuario(); //Restauro archivo de backup de usuario
    static int restaurarBackUpProducto(); //Restauro archivo de backup de producto
    static int listaDeProductos(Producto *vec, int cantProductos); //Cargo en un vector dinamico la lista de productos existentes
    static bool modifHoraSa();
    static bool guardarFichaje(Fichaje &u);
};

#endif // ARCHIVO_H_INCLUDED
