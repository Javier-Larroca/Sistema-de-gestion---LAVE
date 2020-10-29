#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "menu.h"
#include "rlutil.h"

using namespace std;

Menu::Menu()
{
Login principal;
strcpy(usuarioLogueado,principal.getUsuarioIngresado());
cout<<"\nUsuario ingresado: " << usuarioLogueado;
}


int Menu::setNivel(){


}

char *Menu::setUsuario(){


}

void Menu::mostrarOpciones(){
system("cls");
cout<<"Menu Principal\n";
cout<<"Usuario: "<<usuarioLogueado<<endl;
cout<<" Opciones: \n";
cout<<"1. Movimientos\n";
cout<<"2. Reportes\n";


}
