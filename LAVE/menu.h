#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "usuario.h"
#include "login.h"

class Menu{
    protected:
        //Usuario u; Al instanciar un menu, se ejecuta el constructor de Usuario.
        char usuarioLogueado[50];
        int nivel;
        int rolDeUsuario;
    public:
    Menu();
    int setNivel();
    char *setUsuario();
    void mostrarOpciones();
};

#endif // MENU_H_INCLUDED
