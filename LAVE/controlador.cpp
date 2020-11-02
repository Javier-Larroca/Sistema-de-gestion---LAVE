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

using namespace std;

Controlador::Controlador(){
}

Controlador& Controlador::instancia(){
    static Controlador sInstancia;
    return sInstancia;
}

bool Controlador::existeUsuario(char *usuario, char *password){
return Archivo::buscarUsuario(usuario, password);
}
