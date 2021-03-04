#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "vistaFichaje.h"
#include "rlutil.h"
#include "ui.h"

using namespace std;


void vistaFichaje::listarFichajes(Fichaje fAux){
    system("cls");
    cout<<"Id fichaje: ";
    fAux.getCodFich();
    cout<<"Fecha fichaje: ";
    fAux.getFechaF();
    cout<<"Horario entrada: ";
    fAux.getHoraIn();
    cout<<"Horario salida: ";
    fAux.getHoraSa();
}
