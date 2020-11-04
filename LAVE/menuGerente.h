#ifndef MENUGERENTE_H_INCLUDED
#define MENUGERENTE_H_INCLUDED
#include "menu.h"

class MenuGerente:public Menu
{
protected:
    char usuarioLogueado[50];
    int nivel;
    int rolDeUsuario;
public:
    MenuGerente(char *u);
    int setNivel();
    char *setUsuario();
    void mostrarOpciones(); //Mostrar opciones para Menu gerente
};

#endif // MENUGERENTE_H_INCLUDED
