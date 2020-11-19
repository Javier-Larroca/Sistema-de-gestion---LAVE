#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "validador.h"
#include "../Vista/rlutil.h"

#define ENTER 13
#define BACKSPACE 8
#define SPACE 32

using namespace std;

void Validador::validaIngresoDeNombre(char *n){


}

//Valida que se ingresen numeros. Le pasamos un char y numero por direccion.
void Validador:: validaNumero(char *n, int *i){
*i=atoi(n);
}

void Validador::validaIdLogin(char *id){
int pos=0;
int posCursor=49;
    while ((id[pos]=(char)getch())!= ENTER){  //validamos por tecla ingresada. Entra a menos que sea enter.
        if(id[pos]==BACKSPACE){ //Si seleccionamos tecla backspace, borramos un lugar.
            if (posCursor>49){
                cout << (char)8 << (char)32 << (char)8;
                    posCursor--;
                    pos--;
            }
        }
        else{
            gotoxy(posCursor,20);
            cout<<id[pos];
            if(posCursor<=56){
            posCursor++;
            pos++;
            }
        }
    }
    id[pos]=NULL;
}

//Valida espacios en una cadena. Retorna true si hay espacios y false si no los hay.
bool Validador::validaEspacios(char *n){
long int longitud;
longitud=strlen(n);
if(n[0] == ' ' || n[longitud-1] == ' ' || longitud==0){
return true;
}else return false;
}

int Validador::validaRol(char *n){
//i lo tenemos como referencia en caso de que no hayan ingresado 'Gerente', 'Asistente' o 'Cajero'.
int i=atoi(n);
if (strcmp("Gerente",n)== 0 || strcmp("gerente",n)==0)return 1;
if (strcmp("Asistente",n)== 0 || strcmp("asistente",n)==0) return 2;
if (strcmp("Cajero",n)== 0 || strcmp("cajero",n)==0)return 3;
//Al no haber ingresado ninguno de estos valores, pasamos a validar si se ingresaron numeros que correspondan a un rol.
else {
switch(i){
case 1:
    return 1;
case 2:
    return 2;
case 3:
    return 3;
default:
    return -1;
}
}
}

bool Validador::validaSioNo(char *n){
if (strcmp("SI",n)==0 || strcmp("Si",n)==0 || strcmp("No",n)==0 || strcmp("NO",n)==0){
return true;
}
else return false;
}
