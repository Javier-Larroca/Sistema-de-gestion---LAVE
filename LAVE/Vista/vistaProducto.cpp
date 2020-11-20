#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "vistaProducto.h"
#include "rlutil.h"
#include "ui.h"

using namespace std;

//Interfaz grafica para carga de usuario.
void vistaProducto::cargaDeProducto(){
    char nombre[50];
    char descripcion[50];
    //char aux[20]; //Cadena auxiliar para validar numeros en DNI.
    float precio;

    system("cls");
    gotoxy(40,1);
    cout<<" ALTA DE PRODUCTO ";
    cin.ignore();
    cout<<"\nNombre: ";
    cin.getline(nombre, 50);
    cout<<"\nDescripcion: ";
    cin.getline(descripcion, 50);
    cout<<"\nPrecio: $";
    cin>>precio;

    Producto a(nombre, descripcion, precio);
    auxiliar=a;
}

Producto vistaProducto::getProducto(){
    return auxiliar;
}



//Mensaje de exitos. Cada int que reciba va a estar asociado a un módulo.
void vistaProducto::msjExito(int i){
//Si es 1, quiere decir que recibe mensaje de exito del controlador al guardarse el Usuario en disco.
if (i==1){
    cout<<"\nSe guardo correctamente el producto: "<<auxiliar.getNombre()<<" - "<<auxiliar.getDescripcion();
    system("pause");
}
}


void vistaProducto::msjError(int i){
if(i==1){
    cout<<"\nHubo un error al intentar guardar el producto: "<<auxiliar.getNombre();
    cout<<"\nComunicarse con soporte tecnico o reinstale la aplicacion";
    system("pause");
}

}


