#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "login.h"
#include "rlutil.h"

#define ENTER 13
#define BACKSPACE 8
#define SPACE 32

using namespace std;


Login::Login(){
char *aux;
gotoxy(40,3);
cout<<"Usuario: ";
cin.getline(usuarioIngresado,50);
gotoxy(35,5);
cout<<"Contraseña: ";
formatoContrasenia(contraseniaIngresada);
cout<<" "<<contraseniaIngresada;
}

void Login::getUsuarioIngresado(){


}
void Login::getContraseniaIngresada(){


}

void Login::formatoContrasenia(char *password){
int pos=0;
int posCursor=47;
    while ((password[pos]=(char)getch())!= ENTER){  //Contraseña auxiliar, validamos por tecla ingresada. Entra a menos que sea enter.
        if(password[pos]==BACKSPACE){ //Si seleccionamos tecla backspace, borramos un lugar.
            if (posCursor>47){
                cout << (char)8 << (char)32 << (char)8;
                    posCursor--;
                    pos--;
            }
        }
        else{
            gotoxy(posCursor,5);
            cout<<"*";
            posCursor++;
            pos++;
        }
    }
    password[pos]=NULL;
}
