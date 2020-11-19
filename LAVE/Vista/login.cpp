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
#include "ui.h"

#define ENTER 13
#define BACKSPACE 8
#define SPACE 32

using namespace std;

void Login::ingreso()
{
rlutil::hidecursor();
interfazIngreso(38,19,27,2);
system("color 0b");
SetConsoleTitle("   -  LAVE  -  ");
gotoxy(40,20);
cout<<"Usuario: ";
Validador::validaIdLogin(usuarioIngresado);
interfazIngreso(33,22,35,2);
//setlocale(LC_ALL, "Spanish");
gotoxy(35,23);
cout<<"Contrasenia: ";
formatoContrasenia(contraseniaIngresada);
}

char *Login::getUsuarioIngresado(){

return usuarioIngresado;
}

char *Login::getContraseniaIngresada(){

return contraseniaIngresada;
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
            gotoxy(posCursor,23);
            cout<<"*";
            posCursor++;
            pos++;
        }
    }
    password[pos]=NULL;
}

void Login::loginErroneo(int tipoDeError){
    system("color 04");
    gotoxy(40,25);
    if(tipoDeError==-1)cout<<"Usuario invalido!\n";
    else if(tipoDeError==-2)cout<<"Usuario o contraseña invalidos!\n";
    system("pause");
    system("cls");
}

void Login::interfazIngreso(short iniX, short iniY, short ancho, short alto){
 int i, j;
    for(i=iniX; i<=iniX+ancho; i++){
        for(j=iniY; j<=iniY+alto; j++){
            gotoxy(i, j);
            if(i==iniX && j==iniY){cout << (char) 201;                          ///ARRIBA  - IZQUIERDA
            }
            else if(i==iniX+ancho && j==iniY){cout << (char) 187;               ///ARRIBA  - DERECHA
            }
            else if(i==iniX && j==iniY+alto){cout << (char) 200;                ///ABAJO   - IZQUIERDA
            }
            else if(i==iniX+ancho && j==iniY+alto){cout << (char) 188;          ///ABAJO   - DERECHA
            }
            else if(j==iniY || j==iniY+alto){cout << (char) 205;                ///ARRIBA  - ABAJO
            }
            else if(i==iniX || i==iniX+ancho){cout << (char) 186;               ///DERECHA - IZQUIERDA
            }
            else{cout << " ";                                                   ///DENTRO DEL RECUADRO
            }
        }
    }
}

