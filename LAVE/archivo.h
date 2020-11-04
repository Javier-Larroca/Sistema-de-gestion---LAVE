#ifndef ARCHIVO_H_INCLUDED
#define ARCHIVO_H_INCLUDED
#include "usuario.h"
class Archivo{
    public:
    static int buscarUsuario(char *usuario, char *password);
    static void creacionDeArchivoUsuario();
};

#endif // ARCHIVO_H_INCLUDED
