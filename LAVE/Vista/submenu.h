#ifndef SUBMENU_H_INCLUDED
#define SUBMENU_H_INCLUDED
#include "menu.h"

class Submenu:public Menu{
private:
    char usuarioLogueado[50];
    int nivel;
    int rolDeUsuario;

public:
    Submenu(int i);
    int setNivel();
    char *setUsuario();
    void mostrarOpciones();
    void submenuMovimientos(char *o, bool *sale);
    void submenuReportes(char *o, bool *sale);
    void submenuAdministracion(char *o, bool *sale);

};


#endif // SUBMENU_H_INCLUDED
