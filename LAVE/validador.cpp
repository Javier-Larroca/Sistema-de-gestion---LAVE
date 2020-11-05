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
#include "rlutil.h"

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
            gotoxy(posCursor,3);
            cout<<id[pos];
            posCursor++;
            pos++;
        }
    }
    id[pos]=NULL;
}
