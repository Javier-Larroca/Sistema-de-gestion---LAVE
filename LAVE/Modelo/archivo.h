#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "usuario.h"
#include "producto.h"
#include "fichaje.h"

/* A IMPLEMENTAR MAS ADELANTE.
enum Objeto{
usuario=1, //Si recibe numero 1, lo toma como Usuario
fichaje=2 //Si recibe numero 2, lo toma como Fichaje
producto=3 //Si recibe numero 3, lo toma como Producto
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
    static bool guardarFichaje(Fichaje &u);
    static bool guardarProducto(Producto &u);
};

#endif // ARCHIVO_H_INCLUDED
