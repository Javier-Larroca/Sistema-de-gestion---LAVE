#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "venta.h"
#include "archivo.h"

Venta::Venta(){
Archivo::cantidadDeObjetos(&id,3);
}

void Venta::setValores(char *u, int c, float m){
strcpy(usuario,u);
cantProductos=c;
montoTotal=m;
}
