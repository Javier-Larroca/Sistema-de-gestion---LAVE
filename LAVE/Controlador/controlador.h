#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED
#include "../Modelo/archivo.h"
#include "../Vista/menu.h"
#include "../Vista/login.h"
#include "../Vista/vistaAdministracion.h"
#include "../Vista/vistaUsuario.h"
#include "../Vista/vistaInicioPrincipal.h"

/**Controlador de la aplicación. Interactua con lo que ve el usuario y con los datos.
Usa patron de singleton
*/

class Controlador {
    private:
    Controlador(); //Declaro como privado el constructor para asegurar que nadie mas que la clase pueda acceder a la instancia.

    public:
    static Controlador& instancia();
    Controlador(const Controlador&) = delete; //Usamos el delete para que no podamos realizar una copia de la instancia.
    Controlador& operator=(const Controlador&) = delete; //Sobrecarga de operador '=' para Controlador. De esta forma no se puede usar el operador.
    //bool existeUsuario(char *usuario,char *password,int *tipoDeIngreso, int *rol); //Le pasamos el usuario que se ingresa y el bool para saber si el usuario es de soporte.
    void asignarMenu(char *u, int r);
    void ingresoPrincipal();
    void asignarModulo(int i);
    void nuevoUsuario();
    void bajaDeUsuario();
    void inicioDeAplicacion();
    void modificacionUsuario();
};


#endif // CONTROLADOR_H_INCLUDED
