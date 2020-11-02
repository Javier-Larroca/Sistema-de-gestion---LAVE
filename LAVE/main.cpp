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
    Login principal;
    principal.ingreso();
    Controlador::instancia().existeUsuario(principal.getUsuarioIngresado(), principal.getContraseniaIngresada());
    return 0;
}
