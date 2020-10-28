#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include "usuario.h"


class Login{
    private:
    char usuarioIngresado[50];
    char contraseniaIngresada[50];
    public:
    Login();
    void formatoContrasenia(char *password);//Formato con asteriscos
    void getUsuarioIngresado();
    void getContraseniaIngresada();
};


#endif // LOGIN_H_INCLUDED
