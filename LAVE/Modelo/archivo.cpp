#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include <iostream>
#include "archivo.h"

using namespace std;

//Definición archivo de usuarios
const char *archivoUsuario="data/usuarios.dat";

//Definición archivo de Productos
const char *archivoProducto="data/archivos.dat";

//Definición de usuario administrador
const char *administrador="admin";


//Busca usuario logueado. Recibe contraseña
int Archivo::buscarUsuario(char *usuario,char *password, int *rol)
{
    int idUsuario;
    FILE *f;
    f =fopen(archivoUsuario,"rb"); //Abrimos el archivo de usuarios para empezar a buscar
    if (f == NULL)
    {
        return -3;
    }
    if (!strcmp(administrador,usuario))  //Compara si el usuario ingresado es administrativo. Si es 0 es porque las cadenas son iguales.
    {
        Usuario reg(0, password); //Al ser usuario administrativo, creamos un usuario de referencia para poder comparar contrasenia.
        while (fread(&reg, sizeof(Usuario),1,f))
        {
            if (!strcmp(reg.getContrasenia(),password))
            {
                *rol=reg.getRol(); //Asigna rol
                fclose(f);
                return 1; //Reveer si con otro usuario con misma contraseña falla, creo que no
            }
            else  //Se ingresa mal la contraseña de administrador
            {
                fclose(f);
                return -2;
            }
        }
    }
    else
    {
        idUsuario=atoi(usuario); //El id que seria el DNI, lo ingresamos como char en Login, entonces si no es admin lo pasamos a numeros. Si llega a tener un caractern no numerico, es invalido.
        if (idUsuario==0)
        {
            fclose(f);
            return -1; //Usuario invalido
        }
        Usuario normal; //Lo mismo, si logramos pasarlo a numeros efectivamente, creamos un usuario de referencia para poder compararlo.
        while (fread(&normal, sizeof(Usuario),1,f))
        {
            if ((normal.getDni()==idUsuario) && (!strcmp(normal.getContrasenia(),password)))
            {
                *rol=normal.getRol(); //Asigna Rol de usuario auxiliar normal.
                fclose(f);
                return 1;
            }
        }
        fclose(f);
        return -2; //Usuario o contraseña erronea. No aclaramos cual de los 2 por seguridad.


    }
}

//Busca usuario para baja logica, modificacion de rol u horario fichaje
int Archivo::buscarUsuario(Usuario &aux, int dni){
    int resultado=0;
    FILE *f;
    f =fopen(archivoUsuario,"rb"); //Abrimos el archivo de usuarios para empezar a buscar
    if (f == NULL)
    {
        resultado=-3; //No puede abrir el archivo, retorna -3
    }
while (fread(&aux,sizeof(Usuario),1,f)){
    if(dni==aux.getDni() && aux.getEstado()==false){
    return -4; //Lo encuentra pero ya estaba dado de baja. Retorna negativo -4
    }else if(dni==aux.getDni()){
    return 1; //Si se escapa del primer If, vuelve a preguntarse si coincide.
    }
}

fclose(f);
return resultado;
}

//Si es la primera vez que se ingresa al sistema, creamos el archivo usuario con un solo usuario, el administrador.
void Archivo::creacionDeArchivoUsuario()
{
    FILE *p= fopen(archivoUsuario,"rb"); //Abre en modo lectura el archivo.
    if (p == NULL)  //Si no lo puede abrir, es la primera vez que se ingresa al archivo, entonces creamos por default el usuario admin.
    {
        Usuario admin(0); //Le pasamos un solo parametro, llamando al constructor de usuario admin.
        p= fopen(archivoUsuario, "ab"); //Generamos el archivo
        if (p == NULL){cout<<"\nHubo un error al acceder a datos del programa\n",exit(1);}
        fwrite(&admin,sizeof(Usuario),1,p); //Guardamos a admin
        fclose(p);
    }
    fclose(p);
}

//Podemos usar esta función para saber cuantos objetos guardamos en cada archivo.
void Archivo::cantidadDeObjetos(int *i, int tipoDeObjeto)  //Le pasamos el tipo de objeto.
{
    FILE *f;
    switch(tipoDeObjeto)
    {
    case 1: //Le pasa usuario
        {
            f = fopen(archivoUsuario, "rb");
            if (f == NULL)
            {
                cout<<"\nError al acceder al archivo\n";
            }
            fseek(f, 0, SEEK_END);
            *i = ftell(f) / sizeof(Usuario);
            fclose(f);
        }
        break;
    default:
        break;
    }

}

bool Archivo::guardarUsuario(Usuario &u){
    bool grabo;
    FILE *f;
    f = fopen(archivoUsuario, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
    if (f == NULL){
        return false;
    }
    grabo = fwrite(&u, sizeof(Usuario), 1, f);
    fclose(f);
    return grabo;
}

//Baja lógica usando el ID autonumerico que tenemos
bool Archivo::bajaLogica(Usuario u, int idInterno){
bool grabo;
FILE *f;
f = fopen(archivoUsuario, "rb+");
if (f == NULL){
return false;
}
u.setEstado(false);
fseek (f,idInterno*sizeof(Usuario), SEEK_SET);
grabo = fwrite(&u, sizeof(Usuario),1,f);
fclose(f);
return grabo;
}

bool Archivo::modificaRol(Usuario u, int idInterno){
bool grabo;
FILE *f;
f = fopen(archivoUsuario, "rb+");
if (f == NULL){
return false;
}
fseek (f,idInterno*sizeof(Usuario), SEEK_SET);
grabo = fwrite(&u, sizeof(Usuario),1,f);
fclose(f);
return grabo;
}

bool Archivo::guardarProducto(Producto &u){
    bool grabo;
    FILE *f;
    f = fopen(archivoProducto, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
    if (f == NULL){
        return false;
    }
    grabo = fwrite(&u, sizeof(Producto), 1, f);
    fclose(f);
    return grabo;
}

