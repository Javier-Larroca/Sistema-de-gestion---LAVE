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
        Usuario(char *n, char *a, int d, int r, char *c);
        Usuario(int i, char *c); //Constructor de usuario para comparar
        Usuario(int i); //Constructor de usuario administrador
        void setFechaDeIngreso();
        int setRol(int);
        void setId(int d);
        int getId();
        int getRol();
        bool getEstado();
        Fecha getFechaDeIngreso();
        bool escribirDisco(int p);
        bool leerDisco(int p);
        const char *getContrasenia();
        const char *getNombre();
        const char *getApellido();
        int getDni();
};

#endif // USUARIO_H_INCLUDED
