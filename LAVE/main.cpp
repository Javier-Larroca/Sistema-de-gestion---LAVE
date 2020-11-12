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
    Controlador::instancia().ingresoPrincipal();
    return 0;
}
