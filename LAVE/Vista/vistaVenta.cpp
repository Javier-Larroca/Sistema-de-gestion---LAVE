#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "vistaVenta.h"
#include "rlutil.h"

using namespace std;

vistaVenta::vistaVenta(char *u){
strcpy(usuario,u);
montoDeVenta=0;
terminarVenta=false;
}

void vistaVenta::encabezado(){
gotoxy(40,2);
cout<<"CARGA DE VENTA";
gotoxy(85,2);
cout<<"Cajero: "<<usuario;
for (int i=1;i<31;i++){
gotoxy(83,i);
cout<<"|";
}
}

void vistaVenta::productosAcumulado(int cant){
gotoxy (85,7);
cout<<"Productos vendidos: ";
int pos=9; //Posición donde empezamos a ubicar los productos vendidos
for (int e=0;e<cant;e++){
gotoxy(85,pos);
cout<<listaProductos[e].getNombre();
pos++;
}
}

void vistaVenta::montoAcumulado()
{
    gotoxy(85,5);
    cout<<"Monto acumulado: $"<<montoDeVenta;
}

void vistaVenta::cargaDeVenta(Producto *lista, int cantProd)
{
    system("cls");
    encabezado();
    productosAcumulado(0);
    montoAcumulado();
    int vendo=0; //Cantidad de ventas que empiezo a acumular
    int i=0;//Indice con el que vamos a recorres el vector de productos para mostrar el nombre.
    gotoxy(1,4);
    cout<<"Utilice flechas (Arriba/Abajo) para ver los diferentes productos configurados";
    gotoxy(1,6);
    cout<<"Seleccione ENTER para registrar producto en la venta a generar\n";
    gotoxy(1,8);
    cout<<"Seleccione ESC para finalizar venta";
    gotoxy(1,10);
    cout<<"Productos: ";
    while (!terminarVenta)
    {
        gotoxy (13,10);
        cout<<"                      ";
        gotoxy(13,10);
        cout<<lista[i].getNombre();
        tecla=getch();
        //Tecla arriba
        if (tecla==72 && (i<(cantProd-1)))
        {
            i++;
        }
        //Tecla abajo
        else if(tecla==80 && (i>0))
        {
            i--;
        }
        //Tecla enter. Selecciona productos
        else if(tecla==13)
        {
            listaProductos[vendo].setNombre(lista[i].getNombre());
            vendo++;
            montoDeVenta+=lista[i].getPrecio();
            montoAcumulado();
            productosAcumulado(vendo);
            encabezado();

        }
        //Si le da ESC y no registró nada, no lo guarda
        else if(tecla == 27 && montoDeVenta==0)
        {
            terminarVenta=true;
            gotoxy(1,15);
            cout<<"No se realizan ventas. Regresando a menu anterior\n";
            system("pause");
        }
        //Si le da ESC y registro. Lo guarda
        else if (tecla ==27)
        {
            auxiliar.setValores(usuario,vendo,montoDeVenta);
            terminarVenta=true;
        }

    }
}

void vistaVenta::msjErrorListaProd(){
system("cls");
encabezado();
gotoxy(1,4);
cout<<"Se encontraron errores al momento de querer acceder al archivo de Productos disponibles. Llame a soporte para solucionar el problema\n";
system("pause");
}

void vistaVenta::msjExito(){
        gotoxy (1,15);
        cout<<"Se registró correctamente la venta";
        gotoxy(1,18);
        system("pause");

}

void vistaVenta::msjError(){
gotoxy(1,15);
cout<<"Hubo un error al registrar la venta:";
gotoxy(1,18);
system("pause");
}

float vistaVenta::getMontoDeVenta(){
return montoDeVenta;
}

Venta vistaVenta::getVenta(){
return auxiliar;
}
