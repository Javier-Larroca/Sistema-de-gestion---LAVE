#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "Vista/rlutil.h"
#include "Vista/login.h"
#include "Controlador/controlador.h"
#include "Vista/vistaInicioPrincipal.h"
using namespace std;

int main()
{
    Controlador::instancia().inicioDeAplicacion();
    return 0;
}
