#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "menuGerente.h"

using namespace std;

MenuGerente::MenuGerente(char *u)
{
    strcpy(usuarioLogueado,u);
    nivel=1;
}

void MenuGerente::mostrarOpciones()
{
    bool salirDelMenu=false;
    char opcAux[20]; //Char auxiliar para validar numero
    int opcion; //Numero donde asignamos el valor que nos da opcAux al pasarlo a la función validaNumero de Validador.cpp. Lo pasamos por direccion
    while (!salirDelMenu)
    {
        cout<<"Usuario: "<<usuarioLogueado;
        if(strcmp(usuarioLogueado,"admin")==0)
        {
            cout<<"\nRol: Administrador de sistema\n";
        }
        else{
        cout<<"\nRol: Gerente\n";
        }
    cout<<"\n1. Movimientos";
    cout<<"\n2. Reportes";
    cout<<"\n3. Administracion";
    cout<<"\n4. Salir del sistema";
    cout<<endl<<"\nIngrese opcion: ";
    cin>>opcAux;
    Validador::validaNumero(opcAux,&opcion); //Le pasamos el char auxiliar para ingresar opciones y la direccion del int opcion para que le asigne el valor.
    if(opcion==0 || opcion>4){  //Si ingresa letras o una opcion mayor a 4. Muestra mensaje de opcion invalida
    cout<<"\nOpcion invalida\n";
    system("pause");
    system("cls");
    }else if (opcion==4){ // Si es 4, sale del sistema
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
    }else Controlador::instancia().asignarSubmenu(opcion); //Llamamos al controlador y asignamos SubMenu.
    }
}

int MenuGerente::setNivel(){
return 0;
}


char *MenuGerente::setUsuario(){
return usuarioLogueado;
}


