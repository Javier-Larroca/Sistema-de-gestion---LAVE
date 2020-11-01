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

void Validador:: validaNumero(char *n){

}

void Validador::validaIdLogin(char *id){
int pos=0;
int posCursor=49;
bool caracterNoValido=false;
    while ((id[pos]=(char)getch())!= ENTER){  //Contraseña auxiliar, validamos por tecla ingresada. Entra a menos que sea enter.
        if(id[pos]==BACKSPACE){ //Si seleccionamos tecla backspace, borramos un lugar.
            if (posCursor>49){
                cout << (char)8 << (char)32 << (char)8;
                    posCursor--;
                    pos--;
                /*if (caracterNoValido=true){
                gotoxy(8,4);
                cout<<"\e";
                cout<<"\e";
                caracterNoValido=false;
                gotoxy(posCursor,3);
                }*/
            }
        }else if(id[pos]==SPACE){
        gotoxy(8,4);
        cout<<"Atencion: Se ingreso un caracter no compatible con formato de usuario. Puede generar error de ingreso";
        gotoxy(posCursor,3);
        bool caracterNoValido=true;
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
