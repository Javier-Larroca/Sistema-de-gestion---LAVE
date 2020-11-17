#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED
#include "../Modelo/usuario.h"
#include "../Modelo/validador.h"
#include "rlutil.h"

/**Interfaz para Login.
*/

class Login{
    private:
    char usuarioIngresado[50];
    char contraseniaIngresada[50];

    public:
    void ingreso();
    void formatoContrasenia(char *password);//Formato con asteriscos
    char *getUsuarioIngresado();
    char *getContraseniaIngresada();
    void loginErroneo(int tipoDeError);
};


#endif // LOGIN_H_INCLUDED
