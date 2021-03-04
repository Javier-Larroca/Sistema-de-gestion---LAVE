#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "MenuCajero.h"

using namespace std;

MenuCajero::MenuCajero(char *u)
{
    strcpy(usuarioLogueado,u);
    nivel=1;
}

void MenuCajero::mostrarOpciones()
{
    bool salirDelMenu=false;
    char opcAux[20]; //Char auxiliar para validar numero
    int opcion; //Numero donde asignamos el valor que nos da opcAux al pasarlo a la función validaNumero de Validador.cpp. Lo pasamos por direccion
    while (!salirDelMenu)
    {
    cout<<"Usuario: "<<usuarioLogueado;
    cout<<"\nRol: Cajero\n";
    cout<<"\n1. Movimientos";
    cout<<"\n2. Reportes";
    cout<<"\n3. Salir del sistema";
    cout<<endl<<"\nIngrese opcion: ";
    cin>>opcAux;
    Validador::validaNumero(opcAux,&opcion); //Le pasamos el char auxiliar para ingresar opciones y la direccion del int opcion para que le asigne el valor.
    if(opcion==0 || opcion>3){  //Si ingresa letras o una opcion mayor a 4. Muestra mensaje de opcion invalida
    cout<<"\nOpcion invalida\n";
    system("pause");
    system("cls");
    }else if (opcion==3){ // Si es 4, sale del sistema
    system("cls");          //Muestra cierre de sesion
    gotoxy(30,5);
    cout<<"Cerrando sesion";
    Sleep(800);
    cout<<".";
    Sleep(800);
    cout<<".";
    Sleep(800);
    cout<<".";
    salirDelMenu=true;
    system("cls");
    }else Controlador::instancia().asignarModulo(opcion,usuarioLogueado); //Llamamos al controlador y asignamos SubMenu.
    }
}

int MenuCajero::setNivel(){
return 0;
}


char *MenuCajero::setUsuario(){
return usuarioLogueado;
}
