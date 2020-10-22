#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

//Declaracion de funciones
void login();//Función de login
void ingresoDePassword(char *a);
void menuPrincipal(int r); //Menu principal. Recibe el rol
void validaTecla(char t, bool *f, int *p, int m);//Valido la tecla que selecciono. Si es flecha arriba, flecha abajo o ENTER. Recibe el ultimo int para saber en que menú entrar
void menuAdministracion();
void validaOpcion(int o, bool *f);
#endif // FUNCIONES_H_INCLUDED
