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
    int opcion;
    while (!salirDelMenu)
    {
        cout<<"Usuario: "<<usuarioLogueado;
        if(strcmp(usuarioLogueado,"Administrador")==0)
        {
            cout<<"\nRol: Administrador de sistema\n";
        }
        else{
        cout<<"\nRol: Gerente\n";
        }
    cout<<"\n1. Movimientos\n";
    cout<<"\n2. Reportes\n";
    cout<<"\n3. Administracion\n";
    cout<<"\n4. Salir del sistema\n";
    cout<<endl<<"\nIngrese opcion: ";
    cin>>opcion;
    }
}

int MenuGerente::setNivel(){
return 0;
}
char *MenuGerente::setUsuario(){
return usuarioLogueado;
}


