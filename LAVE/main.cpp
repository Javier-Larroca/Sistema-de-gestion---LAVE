#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "rlutil.h"
#include "login.h"
#include "controlador.h"
using namespace std;

int main()
{
    int noIngresa=0;
    Login principal;
    principal.ingreso();
    if(Controlador::instancia().existeUsuario(principal.getUsuarioIngresado(), principal.getContraseniaIngresada(),&noIngresa)){
        Controlador::instancia().asignarMenu(principal.getUsuarioIngresado());
    }else{
    principal.loginErroneo(noIngresa);
    }
    return 0;
}
