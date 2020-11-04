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

using namespace std;

Controlador::Controlador(){
}

Controlador& Controlador::instancia(){
    static Controlador sInstancia;
    return sInstancia;

}

bool Controlador::existeUsuario(char *usuario, char *password, int *tipoDeIngreso)
{
    int referencia; //Referencia para almacenar el resutlado de buscarUsuario.
    Archivo::creacionDeArchivoUsuario();
    referencia=Archivo::buscarUsuario(usuario, password); //Busca usuario

    if(referencia==1)  //Si referencia es 1, es porque encontro el usuario y retorna true saliendo de la función.
    {
        return true;
    }
    *tipoDeIngreso=referencia; //En caso de no retornar 1, nos va a retornar -1 o -2 para saber que tipo de error tuvo y lo almacena en el puntero.
    return false;
}

void Controlador::asignarMenu(char *u){
MenuGerente nuevo(u);
system("cls");
nuevo.mostrarOpciones();
cout<<u;
}
