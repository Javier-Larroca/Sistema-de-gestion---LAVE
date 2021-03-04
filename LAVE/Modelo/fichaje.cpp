#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "archivo.h"
#include "usuario.h"
#include "hora.h"
#include "fichaje.h"
using namespace std;

Fichaje::Fichaje(){

}


Fichaje::Fichaje(char *usuario){
    Archivo::cantidadDeObjetos(&codFich+1,4);
    if (codFich==-1){
        codFich=1;
    }
    Hora horaIn();
    Hora horaSa();
    Fecha fecha();
    strcpy(usuarioF, usuario);
    estado=true;
}

void Fichaje::setHoraSa(){
    horaSa.setHora();
}

void Fichaje::getFechaF(){
    fecha.getFecha();
}

void Fichaje::getHoraIn(){
    horaIn.getHora();
}

void Fichaje::getHoraSa(){
    horaSa.getHora();
}

int Fichaje::getCodFich(){
    return codFich;
}

