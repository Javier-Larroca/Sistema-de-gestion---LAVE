#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "vistaMovimientos.h"

using namespace std;

vistaMovimientos::vistaMovimientos(char *u){
strcpy(cajero,u);
}
//Render de la clase
void vistaMovimientos::opciones()
{
    bool salirDelSubMenu=false;
    char opcAux[20]; //Char auxiliar para validar numero
    int opcion; //Numero donde asignamos el valor que nos da opcAux al pasarlo a la función validaNumero de Validador.cpp. Lo pasamos por direccion
    while (!salirDelSubMenu)
    {
    system("cls");
    //Color de cmd original por si en algun menú cambiamos de color
    system("color 0b");
    cout<<" MOVIMIENTOS - GESTION FINANCIERA\n";
    cout<<"\n1. Venta";
    cout<<"\n2. Volver a menu anterior";
    cout<<endl<<"Ingrese opcion: ";
    cin>>opcAux;
    Validador::validaNumero(opcAux,&opcion); //Le pasamos el char auxiliar para ingresar opciones y la direccion del int opcion para que le asigne el valor.
        switch(opcion)
        {
        case 1:Controlador::instancia().cargarVenta(cajero);
            break;
        case 2:salirDelSubMenu=true;
                system("cls");
            break;
        default:
            break;
        }
    }
}

char *vistaMovimientos::getCajero(){
return cajero;
}
