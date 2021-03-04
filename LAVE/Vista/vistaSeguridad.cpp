#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "vistaSeguridad.h"
#include "rlutil.h"
#include "ui.h"
#include "../Modelo/validador.h"

using namespace std;
using namespace rlutil;

enum opciones {generoCopia=1, restauroCopia=2, CANCELO=3};

vistaSeguridad::vistaSeguridad(){
exit=false;
flecha="=>";
posFlecha=14;
}

//Interfaz gráfica para copia de seguridad y restauración

void vistaSeguridad::encabezado(){
setlocale(LC_ALL, "Spanish");
system("cls");
gotoxy(40,3);
cout<<"Seguridad de archivos \n";

}

bool vistaSeguridad::opcionRestaurarCopia(){
    hidecursor();
    gotoxy(20,7);
    cout<<"ATENCIÓN: Usted va a restaurar una copia de seguridad de los archivos existentes\n";
    gotoxy(15,9);
    cout<<"Los archivos originales serán reemplazados por las copias de seguridad y no se podrán recuperar\n";
    gotoxy(25,11);
    cout<<"Confirme para poder continuar con el proceso de backup\n";
    while(!exit)
    {
        gotoxy(45,14);
        cout<<"   Si\n";
        gotoxy(45,15);
        cout<<"   No\n";
        gotoxy(45,posFlecha);
        cout<<flecha;
        tecla=getch();
//Tecla arriba
        if (tecla==72&&posFlecha==14)
            posFlecha=15;
        else if (tecla==72&&posFlecha==15)
            posFlecha=14;
//Tecla abajo
        if (tecla==80&&posFlecha==14)
            posFlecha=15;
        else if (tecla==80&&posFlecha==15)
            posFlecha=14;
//Tecla Enter
        if (tecla==13&&posFlecha==14)
            return true;
        else if (tecla==13&&posFlecha==15)
            return false;
}
}

bool vistaSeguridad::opcionRealizarCopia(){
    hidecursor();
    gotoxy(20,7);
    cout<<"ATENCIÓN: Usted va a generar una copia de seguridad de los archivos existentes\n"<<endl;
    gotoxy(25,9);
    cout<<"Confirme para poder continuar con el proceso de backup\n";
    while(!exit)
    {
        gotoxy(45,14);
        cout<<"   Si\n";
        gotoxy(45,15);
        cout<<"   No\n";
        gotoxy(45,posFlecha);
        cout<<flecha;
        tecla=getch();
//Tecla arriba
        if (tecla==72&&posFlecha==14)
            posFlecha=15;
        else if (tecla==72&&posFlecha==15)
            posFlecha=14;
//Tecla abajo
        if (tecla==80&&posFlecha==14)
            posFlecha=15;
        else if (tecla==80&&posFlecha==15)
            posFlecha=14;
//Tecla Enter
        if (tecla==13&&posFlecha==14)
            return true;
        else if (tecla==13&&posFlecha==15)
            return false;
}

}

void vistaSeguridad::interfazExito(int opcion){
    system("cls");
    //Porcentaje para visualir el avance de la copia de seguridad. Solamente visual
    int porcentaje=25;
    //Indica la carga de la barra de porcentaje
    int barraPorcentaje=porcentaje;
    //Interfaz para generación de copia de seguridad
    if (opcion==generoCopia)
    {
        for(int x=0; x<4; x++)
        {
            gotoxy(40,5);
            cout<<"Generando archivo de seguridad: ";
            gotoxy(53,9);
            cout<<porcentaje*(x+1);
            cout<<"%";
            gotoxy(barraPorcentaje,7);
            cout<<"|||||||||||||||";
            barraPorcentaje+=15;
            Sleep(1000);
            hidecursor();
        }
        gotoxy(33,12);
        //Cambio color a verde para indicar exito
        system("color 0A");
        cout<<"¡Se generó con EXITO el archivo de seguridad!";
        gotoxy(36,15);
        system("pause");
    }
    //Interfaz para restauración de copia de seguridad.
    else if(opcion==restauroCopia){
    for(int x=0; x<4; x++)
        {
            gotoxy(40,5);
            cout<<"Restaurando archivo de seguridad: ";
            gotoxy(53,9);
            cout<<porcentaje*(x+1);
            cout<<"%";
            gotoxy(barraPorcentaje,7);
            cout<<"|||||||||||||||";
            barraPorcentaje+=15;
            Sleep(1000);
            hidecursor();
        }
        gotoxy(33,12);
        //Cambio color a verde para indicar exito
        system("color 0A");
        cout<<"¡Se restauró con EXITO el archivo de seguridad!";
        gotoxy(36,15);
        system("pause");

    }
}

void vistaSeguridad::interfazError(int opcion){
    system("cls");
    //Porcentaje para visualir el avance de la copia de seguridad. Solamente visual
    int porcentaje=25;
    //Indica la carga de la barra de porcentaje
    int barraPorcentaje=porcentaje;
    //Interfaz para generación de copia de seguridad
    if (opcion==generoCopia)
    {
        for(int x=0; x<2; x++)
        {
            gotoxy(40,5);
            cout<<"Generando archivo de seguridad: ";
            gotoxy(53,9);
            cout<<porcentaje*(x+1);
            cout<<"%";
            gotoxy(barraPorcentaje,7);
            cout<<"|||||||||||||||";
            barraPorcentaje+=15;
            Sleep(1000);
            hidecursor();
        }
        gotoxy(20,12);
        //Cambio color a rojo para indicar error
        system("color 0C");
        cout<<"ERROR: Se encontraron errores criticos al momento de realizar la copia de seguridad";
        gotoxy(35,14);
        cout<<"Contacte a soporte para solucionar el problema";
        gotoxy(36,16);
        system("pause");
    }
    //Interfaz para restauración de copia de seguridad.
    else if(opcion==restauroCopia){
    for(int x=0; x<2; x++)
        {
            gotoxy(40,5);
            cout<<"Restaurando archivo de seguridad: ";
            gotoxy(53,9);
            cout<<porcentaje*(x+1);
            cout<<"%";
            gotoxy(barraPorcentaje,7);
            cout<<"|||||||||||||||";
            barraPorcentaje+=15;
            Sleep(1000);
            hidecursor();
        }
        gotoxy(20,12);
        //Cambio color a rojo para indicar error
        system("color 0A");
        cout<<"ERROR: Se encontraron errores criticos al momento de restaurar la copia de seguridad";
        gotoxy(35,14);
        cout<<"Contacte a soporte para solucionar el problema";
        gotoxy(36,16);
        system("pause");

    }
}
