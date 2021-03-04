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

//Definición archivo de Ventas
const char *archivoVenta="data/venta.dat";

//Definición archivo de Fichajes

const char *archivoFichaje="data/fichaje.dat";

//Definición de archivo de seguridad de usuarios
const char *archivoUsuarioBkp="dataBkp/usuarios.BKP";

//Definición de archivo de seguridad de productos

const char *archivoProductoBkp="dataBkp/producto.BKP";

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
               exit(1);
            }
            fseek(f, 0, SEEK_END);
            *i = ftell(f) / sizeof(Usuario);
            fclose(f);
        }
        break;
    case 2: //Le paso producto
        {
         f = fopen(archivoProducto, "rb");
            if (f == NULL)
            {
                exit(2);
            }
            fseek(f, 0, SEEK_END);
            *i = ftell(f) / sizeof(Producto);
            fclose(f);

        }
    break;
    case 3: //Le paso venta
        {
        f = fopen(archivoVenta, "rb");
        if (f == NULL){
        *i = 1; //No existe el archivo, primera vez que lo abre.
        }
        fseek(f, 0, SEEK_END);
        *i = ftell(f) /sizeof(Venta);
        fclose(f);
        }
    break;
    case 4:
        {
        f = fopen(archivoFichaje, "rb");
            if (f == NULL)
            {
            *i = -1;
            }
            fseek(f, 0, SEEK_END);
            *i = ftell(f) / sizeof(Fichaje);
            fclose(f);

        }
    default:
        break;
    }

}

//Guardamos Usuario creado. Recibe 1 parametros
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

int Archivo::crearBackUpUsuario(){
    Usuario reg; //Usuario donde guardamos los archivos que leemos
//Entero donde vamos a almacenar la cantidad de cada objeto
    int cantidadUsuarios;
//Bandera para poder comparar cantidades
    int registrosGuardados=0;
//Buscamos la cantidad de objetos en archivo Usuario
    Archivo::cantidadDeObjetos(&cantidadUsuarios, 1);
    FILE *f;
    f=fopen(archivoUsuario, "rb");
    if (f == NULL)
    {
        return -1; //Retorna -1 si no pude abrir el archivo original
    }
    while (fread(&reg, sizeof (Usuario), 1, f))
    {
        FILE *bkp; //Archivo de backup
        bkp = fopen(archivoUsuarioBkp, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
        if (bkp == NULL)
        {
        return -2; //Retorna -2 si no pudo crear el archivo de BKP
        }
        fwrite(&reg, sizeof(Usuario), 1, bkp);
        registrosGuardados++;
        fclose(bkp);
    }
    fclose(f);
    if(registrosGuardados==cantidadUsuarios){
        return 1; //Si la cantidad de objetos que existían con lo que guardamos, devolvemos 1
    }else return 2; //Si no coincide, devuelve 2
}

int Archivo::crearBackUpProducto(){
    Producto reg; //Usuario donde guardamos los archivos que leemos
//Entero donde vamos a almacenar la cantidad de cada objeto
    int cantidadProductos;
//Bandera para poder comparar cantidades
    int registrosGuardados=0;
//Buscamos la cantidad de objetos en archivo Producto
Archivo::cantidadDeObjetos(&cantidadProductos, 2);
    FILE *f;
    f=fopen(archivoProducto, "rb");
    if (f == NULL)
    {
        return -1; //Retorna -1 si no pude abrir el archivo original
    }
    while (fread(&reg, sizeof (Producto), 1, f))
    {
        FILE *bkp; //Archivo de backup
        bkp = fopen(archivoProductoBkp, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
        if (bkp == NULL)
        {
        return -2; //Retorna -2 si no pudo crear el archivo de BKP
        }
        fwrite(&reg, sizeof(Producto), 1, bkp);
        registrosGuardados++;
        fclose(bkp);
    }
    fclose(f);
    if(registrosGuardados==cantidadProductos){
        return 1; //Si la cantidad de objetos que existían con lo que guardamos, devolvemos 1
    }else return 2; //Si no coincide, devuelve 2
}

int Archivo::restaurarBackUpUsuario(){
Usuario reg; //Usuario donde guardamos los usuarios que leemos
FILE *f; //Archivo backup
FILE *original; //Archivo original
bool restaura=false;
f=fopen(archivoUsuarioBkp, "rb"); //Abro archivo de backup
    if (f == NULL){
    return -1; //Retorna 1 si no puede abrir el archivo de backup
    }
    original=fopen(archivoUsuario, "wb"); //Seteo a 0 la información en usuarios.dat
    fclose(original); //Cierro archivo
        while (fread(&reg, sizeof (Usuario), 1, f)){
            original = fopen(archivoUsuario, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
            if (original == NULL){
            return -2; //Retorno -2 si no pudo abrir el archivo original
            }
            fwrite(&reg, sizeof(Usuario), 1, original); //Escribo los registros de backup en el archivo original
            fclose(original); //Cierro archivo
        }
        restaura=true;
    fclose(f);//Cierro archivo de usuarios backup
        if (restaura){
        return 1;
        } else return 2;

}

int Archivo::restaurarBackUpProducto(){
Producto reg; //Usuario donde guardamos los usuarios que leemos
FILE *f; //Archivo backup
FILE *original; //Archivo original
bool restaura=false;
f=fopen(archivoProductoBkp, "rb"); //Abro archivo de backup
    if (f == NULL){
    return -1; //Retorna 1 si no puede abrir el archivo de backup
    }
    original=fopen(archivoProducto, "wb"); //Seteo a 0 la información en usuarios.dat
    fclose(original); //Cierro archivo
        while (fread(&reg, sizeof (Producto), 1, f)){
            original = fopen(archivoProducto, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
            if (original == NULL){
            return -2; //Retorno -2 si no pudo abrir el archivo original
            }
            fwrite(&reg, sizeof(Producto), 1, original); //Escribo los registros de backup en el archivo original
            fclose(original); //Cierro archivo
        }
        restaura=true;
    fclose(f);//Cierro archivo de usuarios backup
        if (restaura){
        return 1;
        } else return 2;
}

int Archivo::listaDeProductos(Producto *vec, int cantProductos){
    FILE *p; //Archivo producto
    int bandera=0; //Variable para aumentar las posiciones del vector
    p=fopen(archivoProducto,"rb"); //Abrimos archivo de productos en modo  lectura
    if(p==NULL)return -1; //Si no pudo abrir el archivo, retornamos -1
    while(fread(&vec[bandera], sizeof (Producto),1,p))
    {
        bandera++; //A medida que vamos cargando el vector, vamos sumando la variable bandera que indica el indice
    }
    fclose(p);
    if ((bandera-1)==cantProductos)return 1; //Si coinciden los elementos guardados con la cantidad de productos, retornamos 1
    else return 2; //Si no coinciden, retornamos 2
}

bool Archivo::guardarVenta(Venta &u){
    bool grabo;
    FILE *f;
    f = fopen(archivoVenta, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
    if (f == NULL){
        return false;
    }
    grabo = fwrite(&u, sizeof(Venta), 1, f);
    fclose(f);
    return grabo;

}

bool Archivo::guardarFichaje(Fichaje &u){
    bool grabo;
    FILE *f;
    f = fopen(archivoFichaje, "ab"); //Le paso el const char que almacena la direccion donde lo guardamos.
    if (f == NULL){
        return false;
    }
    grabo = fwrite(&u, sizeof(Fichaje), 1, f);
    fclose(f);
    return grabo;
}

bool Archivo::modifHoraSa(){
    Fichaje fichaAux;
    bool grabo;
    FILE *f;
    f = fopen(archivoFichaje, "rb+");
    if (f == NULL){
    return false;
    }
    int cant;
    Archivo::cantidadDeObjetos(&cant,4);
    fseek (f,cant*sizeof(Fichaje), SEEK_SET);
    fread(&fichaAux, sizeof(Fichaje),1,f);
    fichaAux.setHoraSa();
    grabo = fwrite(&fichaAux, sizeof(Usuario),1,f);
    fclose(f);
    return grabo;
}

/*
bool Archivo::listarFichajes(){
    Fichaje fichaAux;
    FILE *f;
    f = fopen(archivoFichaje, "rb+");
    if (f == NULL){
        return false;
    }
    int cant;
    Archivo::cantidadDeObjetos(&cant,2);
    fseek (f,cant*sizeof(Fichaje), SEEK_SET);
    fread(&fichaAux, sizeof(Fichaje),1,f);
    fichaAux.setHoraSa();

    fclose(f);
    return grabo;
}
**/
