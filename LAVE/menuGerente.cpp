#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "menuGerente.h"

using namespace std;

MenuGerente::MenuGerente(char *u, int rol){
strcpy(usuarioLogueado,u);
nivel=1;
rolDeUsuario=rol;
}


