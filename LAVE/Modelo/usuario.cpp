#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "usuario.h"
#include "archivo.h"
using namespace std;

Usuario::Usuario(){
}
//Constructor para carga de usuario. Asigna ID automaticamente.
Usuario::Usuario(char *n, char *a, int d, int r, char *c){
Archivo::cantidadDeObjetos(&id,1);
strcpy(nombre, n);
strcpy(apellido, a);
dni=d;
rol=r;
strcpy(contrasenia, c);
estado=true;
}

//Constructor de usuario administrativo. Lo usamos en Archivo::creacionDeArchivoUsuario.
Usuario::Usuario(int i){
id=i;
strcpy(nombre,"administrador");
strcpy(apellido,"administrador");
dni=0;
rol=1;
strcpy(contrasenia,"admin123");
estado=true;
}

//Este constructor es usado en archivos, para pasarle dni y contraseña asi valida si existe.
Usuario::Usuario(int i, char *c){
dni=i;                          //Si es 0, sabemos que el usuario es administrador.
strcpy(contrasenia,c);
}


void Usuario::setFechaDeIngreso(){


}

int Usuario::getId(){

return id;
}

Fecha Usuario::getFechaDeIngreso(){
return fechaDeNacimiento;
}

bool Usuario::escribirDisco(int p){
return true;
}

bool Usuario::leerDisco(int p){
return true;
}

const char *Usuario::getContrasenia(){
return contrasenia;
}

int Usuario::getDni(){
return dni;
}

int Usuario::getRol(){
return rol;
}

const char *Usuario::getNombre(){
return nombre;
}
const char *Usuario::getApellido(){
return apellido;
}

//Modificación de ID(DNI) para un usuario
void Usuario::setId(int d){
dni=d;
}

bool Usuario::getEstado(){
return estado;
}

void Usuario::setEstado(bool cambio){
estado=cambio;
}

