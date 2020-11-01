#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include "usuario.h"
#include "validador.h"


class Login{
    private:
    char usuarioIngresado[50];
    char contraseniaIngresada[50];

    public:
    void ingreso();
    void formatoContrasenia(char *password);//Formato con asteriscos
    char *getUsuarioIngresado();
    void getContraseniaIngresada();
};


#endif // LOGIN_H_INCLUDED
