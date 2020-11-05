#ifndef USUARIO_H_INCLUDED
#define USUARIO_H_INCLUDED
#include "fecha.h"


class Usuario{
    private:
        int id;
        char nombre[50];
        char apellido[50];
        int dni;
        Fecha fechaDeNacimiento;
        Fecha fechaDeIngreso;
        int rol;
        char contrasenia[50];
        bool estado;

    public:
        Usuario();
        Usuario(int i, char *c); //Constructor de usuario para comparar
        Usuario(int i); //Constructor de usuario administrador
        void cargar();
        void setFechaDeIngreso();
        int setRol(int);
        int getId();
        int getRol();
        Fecha getFechaDeIngreso();
        bool escribirDisco(int p);
        bool leerDisco(int p);
        const char *getContrasenia();
        int getDni();
};

#endif // USUARIO_H_INCLUDED
