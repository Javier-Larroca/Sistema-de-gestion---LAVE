#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "rlutil.h"
#include "ui.h"
#include "vistaInicioPrincipal.h"

using namespace std;

VistaInicioPrincipal::VistaInicioPrincipal(){
opcion=0;
pos=20;
flecha="=>";
exit=false;
}

void VistaInicioPrincipal::mostrar(){
//setlocale(LC_ALL, "Spanish");
SetConsoleTitle("LAVE - GESTION");
        while(!exit){
        system("color 0b");
        rlutil::hidecursor();
        gotoxy(33,5);
        cout<<"   .........................................."<<endl;
        gotoxy(33,6);
        cout<<"   .%%.......%%%%.....%..........%....%%%%%%."<<endl;
        gotoxy(33,7);
        cout<<"   .%%......%%..%%.....%........%.....%%....."<<endl;
        gotoxy(33,8);
        cout<<"   .%%......%%%%%%......%......%......%%%%..."<<endl;
        gotoxy(33,9);
        cout<<"   .%%......%%..&&.......%....%.......%%....."<<endl;
        gotoxy(33,10);
        cout<<"   .%%%%%...%%..%%.........%%.........%%%%%%."<<endl;
        gotoxy(33,11);
        cout<<"   .........................................."<<endl;
        cout<<endl<<endl;
        gotoxy(33,14);
        cout<<"- Sistema de gestion para comercios gastronómicos -"<<endl;
        gotoxy(41,20);
        cout<<"   Ingresar al sistema"<<endl;
        gotoxy(41,21);
        cout<<"   Salir de la aplicación"<<endl;
        gotoxy(41,pos);
        cout<<flecha;
        tecla=getch();
        //Tecla arriba
        if (tecla==72&&pos==20)pos=21;
        else if (tecla==72&&pos==21)pos=20;
        //Tecla abajo
        if (tecla==80&&pos==20)pos=21;
        else if (tecla==80&&pos==21)pos=20;
        //Tecla enter
        if (tecla==13&&pos==20)Controlador::instancia().ingresoPrincipal();
        else if (tecla==13&&pos==21){
        exit=true;
        cout<<endl;
        gotoxy(40,25);
        cout<<"Saliendo de la aplicación...\n";
        }
        }
}

