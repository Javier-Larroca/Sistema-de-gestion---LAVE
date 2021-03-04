#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "archivo.h"
#include "usuario.h"
#include "hora.h"
#include "fichaje.h"
using namespace std;


Fichaje::Fichaje(char *usuario){
    //Fichaje::cantidadDeObjetos(&codFich,1);
    Archivo::cantidadDeObjetos(&codFich,2);
    Hora horaIn();
    Fecha fecha();
    strcpy(usuarioF, usuario);
    estado=true;
}


