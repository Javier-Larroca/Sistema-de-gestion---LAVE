#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED
#include "../Modelo/archivo.h"
#include "../Modelo/producto.h"
#include "../Vista/menu.h"
#include "../Vista/login.h"
#include "../Vista/vistaAdministracion.h"
#include "../Vista/vistaUsuario.h"
#include "../Vista/vistaInicioPrincipal.h"
#include "../Vista/vistaSeguridad.h"
#include "../Vista/vistaMovimientos.h"
#include "../Vista/vistaVenta.h"

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
    void asignarMenu(char *u, int r); //Asigno menu correspondiente al usuario que ingreso
    void ingresoPrincipal(); //Login principal, instancio vista de Login y LOGO.
    void asignarModulo(int i, char *u); //Asigno vistas de modulos dependiendo de la opción ingresada
    void nuevoUsuario(); //Alta de usuario
    void bajaDeUsuario(); //Baja logica de usuario
    void inicioDeAplicacion(); //Instancio vista para inicio de aplicación y sus diferentes validaciones
    void modificacionUsuario(); //Instancio vista de modificacion de usuario
    void nuevoProducto(); //Instancio vista de nuevo producto para despues llamar a metodos estaticos de archivo y guardarlos
    void creacionBackup(); //Creación de backup. Llama a metodos estaticos de Archivos esperando respuesta.
    void restauracionBackup(); //Restauración de backup. Llama a metodos estaticos de Archivos esperando respuesta
    void cargarVenta(char *u); //Instancio vista nueva de venta y le paso el cajero logueado para que pueda vender.
};


#endif // CONTROLADOR_H_INCLUDED
