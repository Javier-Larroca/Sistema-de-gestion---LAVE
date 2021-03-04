#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "producto.h"
#include "archivo.h"
using namespace std;

Producto::Producto(){
}
//Constructor para carga de producto. Asigna ID automaticamente.
Producto::Producto(char *n, char *c, float p){
    Archivo::cantidadDeObjetos(&id,1);
    strcpy(nombre, n);
    strcpy(descripcion, c);
    precio=p;
}

void Producto::setPrecio(float f){

}

int Producto::getId(){
    return id;
}

float Producto::getPrecio(){
    return precio;
}

const char *Producto::getNombre(){
    return nombre;
}

const char *Producto::getDescripcion(){
    return descripcion;
}

bool Producto::escribirDisco(int p){
    return true;
}

bool Producto::leerDisco(int p){
    return true;
}

char *Producto::setNombre(const char *n){
strcpy(nombre,n);
}
