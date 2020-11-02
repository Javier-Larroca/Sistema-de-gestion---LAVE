#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "usuario.h"
#include "login.h"

class Menu{
    protected:
        char usuarioLogueado[50];
        int nivel;
        int rolDeUsuario;
    public:
    virtual int setNivel()=0;
    virtual char *setUsuario()=0;
    virtual void mostrarOpciones()=0;
};

#endif // MENU_H_INCLUDED
