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
#include "../Vista/menuGerente.h"
#include "../Vista/menuAsistente.h"
#include "../Vista/menuCajero.h"
#include "../Vista/submenu.h"


using namespace std;

Controlador::Controlador(){
}

Controlador& Controlador::instancia(){
    static Controlador sInstancia;
    return sInstancia;

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

//Asigna submenu. En vez de usar la clase submenu, instancia las clases que son del tipo vista.
void Controlador::asignarModulo(int i)
{
    switch(i)
    {
    case 3: //Vista administracion
    {
        vistaAdministracion nueva;
        nueva.opciones();
    }
    break;
    default:
        break;
    }
}

void Controlador::ingresoPrincipal()
{
    int rol, ingreso;
    Login principal;
    principal.ingreso();
    Archivo::creacionDeArchivoUsuario();
    ingreso=Archivo::buscarUsuario(principal.getUsuarioIngresado(), principal.getContraseniaIngresada(),&rol);
    if (ingreso==1)
    {
        Controlador::instancia().asignarMenu(principal.getUsuarioIngresado(),rol);

    }else principal.loginErroneo(ingreso);

}

void Controlador::nuevoUsuario()
{
    vistaUsuario nuevaVista;
    nuevaVista.cargaDeUsuario();
    Usuario U;
    U=nuevaVista.getUsuario();
    if(Archivo::guardarUsuario(U)==0){
    nuevaVista.msjError(1);
    }else nuevaVista.msjExito(1);
}
void Controlador::bajaDeUsuario(){
system("cls");
char idAux[50];
int id;
cout<<"Baja de usuario";
cout<<"\nIngrese el ID de usuario a eliminar: ";
cin>>idAux;
Validador::validaNumero(idAux,&id);
if(id==0){
cout<<"\nID no valido. Solo se permiten numeros\n";
system("pause");
}else {
cout<<"\nExiste el usuario\n";
system("pause");
}
}
