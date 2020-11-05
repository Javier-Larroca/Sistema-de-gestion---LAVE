#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED
#include "usuario.h"
#include "rlutil.h"
#include "login.h"
#include "validador.h"
#include "controlador.h"

/**
Clase abstracta Menu. De esta clase heredan todos los diferentes tipos de Menu
*/
class Menu
{
public:
    virtual int setNivel()=0;
    virtual char *setUsuario()=0;
    virtual void mostrarOpciones()=0;
};

#endif // MENU_H_INCLUDED
