#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "archivo.h"

using namespace std;

//Definición archivo de usuarios
const char *archivoUsuario="datos/usuarios.dat";

//Definición archivo de Productos
const char *archivoProducto="datos/archivos.dat";

//Definición de usuario administrador
const char *administrador="admin";

bool Archivo::buscarUsuario(char *usuario, char *password){
int idUsuario;
cout<<endl<<usuario<<endl;
system("pause");
if (!strcmp(administrador,usuario)){ //Compara si el usuario ingresado es administrativo. Si es 0 es porque las cadenas son iguales.
cout<<"\nUsuario administrativo\n";
system("pause");
return true;
}
else {
idUsuario=atoi(usuario);
    if (idUsuario==0){
    cout<<"\nUsuario no valido\n";
    system("pause");
    return false;
    }
    cout<<"\n"<<idUsuario;
    system("pause");
    return true;
}

}
