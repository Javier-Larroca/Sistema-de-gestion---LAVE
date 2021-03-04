#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "fecha.h"

using namespace std;

Fecha::Fecha(){
 //Obtencion de fecha actual y guardado en un Struct de Fecha.
    time_t t = time( NULL );
    struct tm today = *localtime( &t );
    mes =today.tm_mon + 1;
    dia =today.tm_mday;
    anio =(today.tm_year+1900);

}

void Fecha::getFecha(){
    cout<<dia;
    cout<<"/";
    cout<<mes;
    cout<<"/";
    cout<<anio;
}

