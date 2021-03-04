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
gotoxy(50,2);
cout<<"Carga de venta";
}

void vistaVenta::montoAcumulado(){
gotoxy(60,50);
cout<<"Monto acumulado: $";
}

void vistaVenta::cargaDeVenta(){
encabezado();
montoAcumulado();
cout<<"\nProductos: ";
}
