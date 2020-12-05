#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "vistaUsuario.h"
#include "rlutil.h"
#include "ui.h"

using namespace std;

//Interfaz grafica para carga de usuario.
void vistaUsuario::cargaDeUsuario(){
char nombreAux[50];
char apellidoAux[50];
int dni;
int rol;
char contraAux[50];
system("cls");
encabezado(1); //Encabezado. Mostramos Alta de usuario. Al ser una vista con una carga de datos directa, va a adentro del metodo.
cout<<"\nNombre: ";
cin>>nombreAux;
//Empieza validacion de espacios en el nombre
while(Validador::validaEspacios(nombreAux)){
cout<<"\nNo se permiten espacios. Ingrese nuevamente:\n";
cout<<"\nNombre: ";
cin>>nombreAux;
} //Termina validacion
//Empieza validación de espacios en apellido.
cout<<"\nApellido: ";
cin>>apellidoAux;
while(Validador::validaEspacios(apellidoAux)){
cout<<"\nNo se permiten espacios. Ingrese nuevamente:\n";
cout<<"\nNombre: ";
cin>>apellidoAux;
}//Termina validacion
cout<<"\nDNI: ";
cin>>aux;
//Empieza validación de la cadena AUX, que despues la pasamos a numero con el metodo del Validador.
Validador::validaNumero(aux, &dni);
while(strlen(aux)!=8 || dni ==0){ //Entra a menos que se hayan ingresado char o que el dni no tenga 8 digitos.
cout<<"\nDNI Invalido. Ingrese nuevamente numero de documento: ";
cin>>aux;
Validador::validaNumero(aux, &dni);
}
//Termina validacion.
cout<<"\nRol: ";
cin>>aux;
//Empieza validacion de tipo de rol. Se puede ingresar la descripcion del rol o directamente numeros.
rol=Validador::validaRol(aux);
while (rol==-1){
cout<<"\nRol ingresado no valido. Ingrese descripcion del puesto o 1(Gerente) | 2(Asistente) | 3(Cajero)\n";
cout<<"Rol: ";
cin>>aux;
rol=Validador::validaRol(aux);
}
//Termina validacion de Rol
cout<<"\nEstablezca contraseña: ";
cin>>contraAux;
if(strlen(contraAux)<=5){
cout<<"\nNivel de seguridad de contraseña: BAJO\n";
}else if(strlen(contraAux)<=9){
cout<<"\nNivel de seguridad de contraseña: MEDIO\n";
}else cout<<"\nNivel de seguridad de contraseña: ALTO\n";
system("pause");

Usuario a(nombreAux, apellidoAux, dni, rol, contraAux);
auxiliar=a;
}

bool vistaUsuario::bajaDeUsuario(Usuario u){
cout<<"\nEsta seguro que desea dar de baja al usuario: ";
cout<<u.getNombre()<<" "<<u.getApellido();
cout<<"\nSi/No: ";
cin>>aux;
while(!Validador::validaSioNo(aux)){
cout<<"\nIngrese 'Si' o 'No' para poder continuar: ";
cin>>aux;
}
if (strcmp("Si",aux)==0 || strcmp("SI",aux)==0){
return true;
}else {
cout<<"\nSe cancela baja de usuario...\n";
system("pause");
}
return false;
}

Usuario vistaUsuario::getUsuario(){
return auxiliar;
}

//Mensaje de exitos. Cada int que reciba va a estar asociado a un módulo.
void vistaUsuario::msjExito(int i)
{
    switch(i)
    {
    case 1: //Si es 1, quiere decir que recibe mensaje de exito del controlador al guardarse el Usuario en disco.
    {
        cout<<"\nSe guardo correctamente el usuario: "<<auxiliar.getNombre()<<" "<<auxiliar.getApellido()<<endl;
        system("pause");
    }
    break;
    case 2: //Si es 2, da de baja correctamente al usuario.
    {
        cout<<"\nSe dio de baja correctamente al usuario\n";
        system("pause");
    }
    break;
    case 3: //Si es 3, modifica correctamente el rol del usuario.
    {
        cout<<"\nSe modifico correctamente el rol al usuario\n";
        system("pause");
    }
    break;
    case 4: //Si es 4, modifica correctamente el horario de fichaje.
    {
        cout<<"\nSe modifico correctamente el horario de fichaje del usuario\n";
        system("pause");
    }
    break;
    default:
    {
        cout<<"\nError de asignacion de modulo para mensaje";
        system("pause");
    }
    break;
    }
}
void vistaUsuario::msjError(int i)
{
    switch(i)
    {
    case 1: //Si es 1, error al querer guardar en disco
    {
        cout<<"\nHubo un error al intentar guardar al usuario: "<<auxiliar.getNombre()<<auxiliar.getApellido();
        cout<<"\nComunicarse con soporte tecnico o reinstale la aplicacion";
    }
    break;
    case 2: //Si es 2, error de baja de usuario.
    {
        cout<<"\nHubo un error al intentar dar de baja al usuario: "<<auxiliar.getNombre()<<auxiliar.getApellido();
        cout<<"\nComunicarse con soporte tecnico o reinstale la aplicacion";
    }
    break;
    case 3: //Si es 3, error al querer modificar el usuario
    {
        cout<<"\nHubo un error al intentar modificar el rol del usuario: "<<auxiliar.getNombre()<<auxiliar.getApellido();
        cout<<"\nComunicarse con soporte tecnico o reinstale la aplicacion";
    }
    break;
    case 4: //Si es 4,error al querer modificar el horario de fichaje
    {
        cout<<"\nHubo un error al intentar modificar el horario de fichaje del usuario: "<<auxiliar.getNombre()<<auxiliar.getApellido();
        cout<<"\nComunicarse con soporte tecnico o reinstale la aplicacion";
    }
    break;
    //Numeros negativos o 0 nos indican que hubo Archivo.cpp retorno un error de apertura al controlador.
    case 0:
        {
        cout<<"\nNo se encontro al usuario\n";
        }
        break;

    case -3:{
     cout<<"\nNo se pudo abrir el archivo de Usuarios. Contacte mesa de ayuda.\n";
    }
        break;
    case -4:{
    cout<<"\nEl usuario ya se encontraba dado de baja\n";
    }
    break;
    default:
    {
        cout<<"\nError de asignacion de modulo para mensaje";
    }
    }
    system("pause");
}

//Interfaz grafica para ingreso de ID. Lo implementamos en cualquier metodo donde necesitemos buscar por usuario.
int vistaUsuario::ingresoID(){
int id;
cout<<"\nIngrese ID de usuario: ";
cin>>aux;
Validador::validaNumero(aux, &id); //Validacion de ID.
while(strlen(aux)!=8 || id ==0){ //Entra a menos que se hayan ingresado char o que el dni no tenga 8 digitos.
cout<<"\nID Invalido. Ingrese nuevamente: ";
cin>>aux;
Validador::validaNumero(aux, &id);
}
return id;
//auxiliar.setId(id);
}

//Encabezado para diferentes modulos para un Usuario.
void vistaUsuario::encabezado(int i)
{
    system("cls");
    gotoxy(40,1);
    switch (i)
    {
    case 1:
        cout<<" ALTA DE USUARIO"<<endl;
        break;
    case 2:
        cout<<" BAJA DE USUARIO"<<endl;
        break;
    case 3:
        cout<<" MODIFICACION DE ROL"<<endl;
        break;
    case 4:
        cout<<" MODIFICACION DE HORARIO FICHAJE"<<endl;
            break;
    default:
        cout<<"Error de asignación de menú";
        break;
    }

}

bool vistaUsuario::modificacionDeRol(Usuario &u){
int rolNuevo;
cout<<"\nUsuario: ";
cout<<u.getNombre()<<" "<<u.getApellido();
cout<<"\nRol actual: ";
if(u.getRol()==1)cout<<"Gerente";
else if(u.getRol()==2)cout<<"Asistente";
else cout<<"Cajero";
cout<<"\nRol nuevo: ";
cin>>aux;
rolNuevo=Validador::validaRol(aux);
while(rolNuevo==-1){
cout<<"\nRol ingresado no valido. Ingrese descripcion del puesto o 1(Gerente) | 2(Asistente) | 3(Cajero)\n";
cout<<"Rol: ";
cin>>aux;
rolNuevo=Validador::validaRol(aux);
}
u.setRol(rolNuevo);
cout<<"Rol nuevo: ";
cout<<aux;
cout<<"\n¿Guardar cambios?";
cout<<"\nSi/No: ";
cin>>aux;
while(!Validador::validaSioNo(aux)){
cout<<"\nIngrese 'Si' o 'No' para poder continuar: ";
cin>>aux;
}
if (strcmp("Si",aux)==0 || strcmp("SI",aux)==0){
return true;
}else {
cout<<"\nSe cancela modificacion de rol...\n";
system("pause");
}
return false;
}
