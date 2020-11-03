#ifndef CONTROLADOR_H_INCLUDED
#define CONTROLADOR_H_INCLUDED
#include "archivo.h"

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
    bool existeUsuario(char *usuario,char *password,int *tipoDeIngreso); //Le pasamos el usuario que se ingresa y el bool para saber si el usuario es de soporte.
    void asignarMenu();
};


#endif // CONTROLADOR_H_INCLUDED
