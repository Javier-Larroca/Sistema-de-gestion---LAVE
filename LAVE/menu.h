#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "usuario.h"

class Menu{
    protected:
        Usuario u;
        int nivel;
        int rolDeUsuario;
    public:
    Menu();
    ~Menu();
    setNivel();
    setUsuario();
};

#endif // MENU_H_INCLUDED
