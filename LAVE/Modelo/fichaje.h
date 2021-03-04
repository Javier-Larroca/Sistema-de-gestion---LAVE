#ifndef FICHAJE_H_INCLUDED
#define FICHAJE_H_INCLUDED
#include "fecha.h"
#include "hora.h"


class Fichaje{
    private:
        Fecha fecha; //Esta se podria iniciar ya directamente con la fecha del dia.
        Hora horaIn; //Se asignaria el horario del momento
        Hora horaSa;
        char usuarioF[50]; //SE asginaria el usuario que acaba de iniciar sesion
        int codFich; //ID de cada fichaje
        bool estado;
    public:
        Fichaje(char *usuario);
};

#endif // FICHAJE_H_INCLUDED

