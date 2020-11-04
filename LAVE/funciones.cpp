#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "funciones.h"
#include "rlutil.h"
#include "usuario.h"

#define ENTER 13
#define BACKSPACE 8
#define SPACE 32

using namespace std;
using namespace rlutil;

void login()
{
    char usuarioAux[50]; //Usuario auxiliar
    char contraAux[50]; //Contraseña auxiliar
    gotoxy(40,3);
    cout<<"Usuario: ";
    cin>>usuarioAux;
    gotoxy(35,5);
    cout<<"Contraseña: ";
    ingresoDePassword(contraAux);
    system("cls");
    menuPrincipal(1);
}

//Prototipo de ingreso de password
void ingresoDePassword(char *a){
int pos=0;
int posCursor=47;
while ((a[pos]=(char)getch())!= ENTER){  //Contraseña auxiliar, validamos por tecla ingresada. Entra a menos que sea enter.
        if(a[pos]==BACKSPACE){ //Si seleccionamos tecla backspace, borramos un lugar.
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
    a[pos]=NULL;
}

//Prototipo de Menu principal
void menuPrincipal(int r){
bool finDePrograma=false;
char tecla;
const char *flecha="=>";
int pos=4;
    while(!finDePrograma){
        hidecursor();
        gotoxy(1,1);
        cout << "           MENU PRINCIPAL         "<< endl;
        cout << "-----------------------------------------------"<< endl;
        cout <<endl;
        gotoxy(1,4);
        cout <<"  1. Movimientos"<< endl;
        cout <<"  2. Reportes"<< endl;
        cout <<"  3. Administracion"<< endl;
        cout <<"  4. Salir del programa"<< endl;
        gotoxy(1,pos);
        cout <<flecha;
        cout <<endl;
        tecla=getch();
        validaTecla(tecla, &finDePrograma, &pos, 1);
    }
}

//Tecla direccional
void validaTecla(char t, bool *f, int *p, int m){
int aux=*p;
if (t==72){ //TECLA ARRIBA
    switch(aux){
        case 4:
            aux=7;
            break;
        case 5:
            aux=4;
            break;
        case 6:
            aux=5;
            break;
        case 7:
            aux=6;
            break;
    }
}
if(t==80){ //TECLA ABAJO
    switch(aux){
        case 4:aux=5;
            break;
        case 5:aux=6;
            break;
        case 6:
            if (m==4 || m==5){ //Si es 4(Menu Reportes) o 5(Menu configuracion), al tener 2 opciones vuelve al comienzo.
                aux=4;
            }else{
                aux=7;
            }
            break;
        case 7:aux=4;
            break;

    }
}
if (t==ENTER){
   switch(aux){
    case 4:
        menuAdministracion();
        break;
    case 7: system("cls");
            cout<<" Gracias por acceder a LAVE \n";
            *f=true;
        break;
   }
}
*p=aux; //Despues de todo el recorrido del switch, le asigna el valor nuevo de la tecla al puntero p.
}

void menuAdministracion(){
char opc[10];
bool finDePrograma=false;
    while(!finDePrograma){
        system("cls");
        cout << "           Administración        "<< endl;
        cout << "-----------------------------------------------"<< endl;
        cout <<endl;
        cout <<"  1. Alta de usuario"<< endl;
        cout <<"  2. Baja de usuario"<< endl;
        cout <<"  3. Modificación de rol"<< endl;
        cout <<"  4. Modificación de horario de fichaje"<< endl;
        cout <<"  5. Alta de productos"<<endl;
        cout <<"  6. Baja de productos"<<endl;
        cout <<"  7. Realizar copia de seguridad"<<endl;
        cout <<"  8. Restaurar copia de seguridad"<<endl;
        cout <<"  9. Volver a menú principal"<<endl;
        cout <<endl;
        cout<<"Opción: ";
        cin>>opc;
        system("cls");
        int o=atoi(opc);
        validaOpcion(o, &finDePrograma);
    }
}

void validaOpcion(int o, bool *f){
    switch(o){
        case 1:
            {//Usuario u;
            //u.escribirDisco();
            }
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            *f=true;
            break;

    }
}
