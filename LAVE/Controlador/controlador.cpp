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

//Baja logica de usuario.
void Controlador::bajaDeUsuario(){
    vistaUsuario nuevo;
    nuevo.encabezado(2);
    Usuario reg;
    int busqueda=Archivo::buscarUsuario(reg,nuevo.ingresoID());
    if(busqueda==1)
    {
        cout<<reg.getId();
        if(nuevo.bajaDeUsuario(reg))
        {
        if(Archivo::bajaLogica(reg, reg.getId())){
        nuevo.msjExito(2);
        }else nuevo.msjError(2);
        }
    }
    else
        nuevo.msjError(busqueda);
}

void Controlador::inicioDeAplicacion(){
VistaInicioPrincipal inicio;
inicio.mostrar();
}
