#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "controlador.h"
#include "menuGerente.h"
#include "menuAsistente.h"
#include "menuCajero.h"
#include "submenu.h"


using namespace std;

Controlador::Controlador(){
}

Controlador& Controlador::instancia(){
    static Controlador sInstancia;
    return sInstancia;

}

bool Controlador::existeUsuario(char *usuario, char *password, int *tipoDeIngreso, int *rol)
{
    int referencia; //Referencia para almacenar el resutlado de buscarUsuario.
    Archivo::creacionDeArchivoUsuario();
    referencia=Archivo::buscarUsuario(usuario, password, rol); //Busca usuario

    if(referencia==1)  //Si referencia es 1, es porque encontro el usuario y retorna true saliendo de la función.
    {
        return true;
    }
    *tipoDeIngreso=referencia; //En caso de no retornar 1, nos va a retornar -1 o -2 para saber que tipo de error tuvo y lo almacena en el puntero.
    return false;
}

void Controlador::asignarMenu(char *u, int r){
system("cls");
if(r==1){
MenuGerente nuevo(u);
nuevo.mostrarOpciones();
}if(r==2){
MenuAsistente nuevo(u);
nuevo.mostrarOpciones();
}else if(r==3){
MenuCajero nuevo(u);
nuevo.mostrarOpciones();
}

}

//Asigna submenu
void Controlador::asignarSubmenu(int i){
Submenu nuevo(3); //Submenu administracion
nuevo.mostrarOpciones();
}

void Controlador::evaluarOpcion(int submenu, int opcion)
{

    if (submenu==1)  //Submenu Movimientos
    {


    }
    else if(submenu==2)   //Submenu Reportes
    {

    }
    else if(submenu==3)   //Submenu Administración
    {
        switch(opcion)
        {
        case 1:
        {   system("cls");
            cout<<"Carga de usuario: \n"<<endl;
            Usuario u;
            u.cargar();
            if (Archivo::guardarUsuario(u)){
            cout<<"\nSe guardo correctamente al usuario!\n";
            system("pause");
            }
            else {
            cout<<"\nNo se puedo guardar al usuario. Contactese con soporte para más informacion\n";
            system("pause");
            }
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
        }

    }
}
