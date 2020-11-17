#ifndef MENUCAJERO_H_INCLUDED
#define MENUCAJERO_H_INCLUDED
#include "menu.h"

/**
Declaracion de clase Menu cajero
*/

class MenuCajero:public Menu
{
protected:
    char usuarioLogueado[50];
    int nivel;
    int rolDeUsuario;
public:
    MenuCajero(char *u);
    int setNivel();
    char *setUsuario();
    void mostrarOpciones(); //Mostrar opciones para Menu gerente
};


#endif // MENUCAJERO_H_INCLUDED
