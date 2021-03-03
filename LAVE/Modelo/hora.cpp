#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "hora.h"

Hora::Hora(){
    //Obtencion de hora actual y guardado en un Struct de Fecha.
    time_t t = time( NULL );
    struct tm today = *localtime( &t );
    horas =today.tm_hour;
    minutos =today.tm_sec;
}

