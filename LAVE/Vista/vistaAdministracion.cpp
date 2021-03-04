#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "vistaAdministracion.h"

using namespace std;

//Render de la clase
void vistaAdministracion::opciones()
{
    bool salirDelSubMenu=false;
    char opcAux[20]; //Char auxiliar para validar numero
    int opcion; //Numero donde asignamos el valor que nos da opcAux al pasarlo a la función validaNumero de Validador.cpp. Lo pasamos por direccion
    while (!salirDelSubMenu)
    {
    system("cls");
    //Color de cmd original por si en algun menú cambiamos de color
    system("color 0b");
    cout<<" ADMINISTRACION \n";
    cout<<"\n1. Alta de usuarios";
    cout<<"\n2. Baja de usuarios";
    cout<<"\n3. Modificacion de rol";
    cout<<"\n4. Modificacion de horario de fichaje";
    cout<<"\n5. Alta de productos";
    cout<<"\n6. Baja de productos";
    cout<<"\n7. Realizar copia de seguridad";
    cout<<"\n8. Restaurar copia de seguridad";
    cout<<"\n9. Volver a menu principal";
    cout<<endl<<"Ingrese opcion: ";
    cin>>opcAux;
    Validador::validaNumero(opcAux,&opcion); //Le pasamos el char auxiliar para ingresar opciones y la direccion del int opcion para que le asigne el valor.
        switch(opcion)
        {
        case 1:Controlador::instancia().nuevoUsuario();
            break;
        case 2:Controlador::instancia().bajaDeUsuario();
            break;
        case 3:Controlador::instancia().modificacionUsuario();
            break;
        case 4:
            break;
        case 5:Controlador::instancia().nuevoProducto();
            break;
        case 6:
            break;
        case 7:Controlador::instancia().creacionBackup();
            break;
        case 8:Controlador::instancia().restauracionBackup();
            break;
        case 9:salirDelSubMenu=true;
                system("cls");
            break;

        }
    }
}

