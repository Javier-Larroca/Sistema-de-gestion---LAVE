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

void vistaVenta::encabezado(){
gotoxy(40,2);
cout<<"CARGA DE VENTA";
gotoxy(85,2);
cout<<"Cajero: ";
gotoxy (85,7);
cout<<"Productos vendidos: ";
for (int i=1;i<31;i++){
gotoxy(83,i);
cout<<"|";
}

}

void vistaVenta::montoAcumulado(){
gotoxy(85,5);
cout<<"Monto acumulado: $";
}

void vistaVenta::cargaDeVenta(){
system("cls");
encabezado();
montoAcumulado();
gotoxy(1,4);
cout<<"Utilice flechas (Arriba/Abajo) para ver los diferentes productos configurados";
gotoxy(1,5);
cout<<"Seleccione ENTER para registrar producto en la venta a generar\n";
gotoxy(1,6);
cout<<"Seleccione ESC para finalizar venta";
gotoxy(1,7);
cout<<"Productos: ";
system("pause");
}
