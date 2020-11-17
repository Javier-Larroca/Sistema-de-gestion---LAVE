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
char aux[20]; //Cadena auxiliar para validar numeros en DNI.
int dni;
int rol;
char contraAux[50];
system("cls");
gotoxy(40,1);
cout<<" ALTA DE USUARIO ";
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

Usuario vistaUsuario::getUsuario(){
return auxiliar;
}

//Mensaje de exitos. Cada int que reciba va a estar asociado a un módulo.
void vistaUsuario::msjExito(int i){
//Si es 1, quiere decir que recibe mensaje de exito del controlador al guardarse el Usuario en disco.
if (i==1){
cout<<"\nSe guardo correctamente el usuario: "<<auxiliar.getNombre()<<auxiliar.getApellido();
system("pause");
}
}

void vistaUsuario::msjError(int i){
if(i==1){
cout<<"\nHubo un error al intentar guardar al usuario: "<<auxiliar.getNombre()<<auxiliar.getApellido();
cout<<"\nComunicarse con soporte tecnico o reinstale la aplicacion";
system("pause");
}

}
