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
using namespace std;

void Usuario::cargar(){
cout<<"Nombre: ";
cin>>nombre;
cout<<"\nApellido: ";
cin>>apellido;
cout<<"\nDNI: ";
cin>>dni;
cout<<"\nRol: ";
cin>>rol;
cout<<"\nEstablezca contraseña: ";
cin>>contrasenia;
estado=true;
}

void Usuario::setFechaDeIngreso(){


}

int Usuario::getId(){

return id;
}

Fecha Usuario::getFechaDeIngreso(){

}

bool Usuario::escribirDisco(int p){

}

bool Usuario::leerDisco(int p){

}
