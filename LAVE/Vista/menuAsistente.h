#ifndef MENUASISTENTE_H_INCLUDED
#define MENUASISTENTE_H_INCLUDED
#include "menu.h"


/**
Declaración de clase para Menu asistente.
*/

class MenuAsistente:public Menu
{
protected:
    char usuarioLogueado[50];
    int nivel;
    int rolDeUsuario;
public:
    MenuAsistente(char *u);
    int setNivel();
    char *setUsuario();
    void mostrarOpciones(); //Mostrar opciones para Menu gerente
};


#endif // MENUASISTENTE_H_INCLUDED
