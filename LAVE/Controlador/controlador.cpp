#include <iostream>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <cstdio>
#include <ctime>
#include <string.h>
#include <windows.h>
#include <stdio.h>
#include "controlador.h"
#include "../Vista/menuGerente.h"
#include "../Vista/menuAsistente.h"
#include "../Vista/menuCajero.h"
#include "../Vista/submenu.h"
#include "../Vista/vistaProducto.h"

using namespace std;

Controlador::Controlador(){
}

Controlador& Controlador::instancia(){
    static Controlador sInstancia;
    return sInstancia;

}

void Controlador::asignarMenu(char *u, int r){
system("cls");
if(r==1){
MenuGerente nuevo(u);
nuevo.mostrarOpciones();
}if(r==2){
MenuAsistente nuevo(u);
nuevo.mostrarOpciones();
}else if(r==3){
MenuCajero nuevo(u);
nuevo.mostrarOpciones();
}

}

//Asigna submenu. En vez de usar la clase submenu, instancia las clases que son del tipo vista.
void Controlador::asignarModulo(int i, char *u)
{
    switch(i)
    {
    case 1:
    {
        vistaMovimientos nueva(u);
        nueva.opciones();
    }
    break;
    case 2:{

    }
    break;
    case 3: //Vista administracion
    {
        vistaAdministracion nueva;
        nueva.opciones();
    }
    break;
    default:
        break;
    }
}

void Controlador::ingresoPrincipal()
{
    int rol, ingreso;
    Login principal;
    principal.ingreso();
    Archivo::creacionDeArchivoUsuario();
    ingreso=Archivo::buscarUsuario(principal.getUsuarioIngresado(), principal.getContraseniaIngresada(),&rol);
    if (ingreso==1)
    {
        Controlador::instancia().asignarMenu(principal.getUsuarioIngresado(),rol);

    }else principal.loginErroneo(ingreso);

}

void Controlador::nuevoUsuario()
{
    vistaUsuario nuevaVista;
    nuevaVista.cargaDeUsuario();
    Usuario U;
    U=nuevaVista.getUsuario();
    if(Archivo::guardarUsuario(U)==0){
    nuevaVista.msjError(1);
    }else nuevaVista.msjExito(1);
}

//Baja logica de usuario.
void Controlador::bajaDeUsuario(){
    vistaUsuario nuevo;
    nuevo.encabezado(2);
    Usuario reg;
    int busqueda=Archivo::buscarUsuario(reg,nuevo.ingresoID());
    if(busqueda==1)
    {
        if(nuevo.bajaDeUsuario(reg))
        {
        if(Archivo::bajaLogica(reg, reg.getId())){
        nuevo.msjExito(2);
        }else nuevo.msjError(2);
        }
    }
    else
        nuevo.msjError(busqueda);
}

void Controlador::modificacionUsuario()
{
    vistaUsuario nuevo;
    nuevo.encabezado(3);
    Usuario reg;
    int busqueda=Archivo::buscarUsuario(reg,nuevo.ingresoID());
    if (busqueda==1)
    {
        if (nuevo.modificacionDeRol(reg))
        {
        if (Archivo::modificaRol(reg, reg.getId()))nuevo.msjExito(3);
        else nuevo.msjError(3);
        }
    }
    else
        nuevo.msjError(busqueda);
}

void Controlador::inicioDeAplicacion(){
VistaInicioPrincipal inicio;
inicio.mostrar();
}

void Controlador::nuevoProducto(){
vistaProducto nuevaVista;
    nuevaVista.cargaDeProducto();
    Producto P;
    P=nuevaVista.getProducto();
    if(Archivo::guardarProducto(P)==0){
        nuevaVista.msjError(1);
    }else nuevaVista.msjExito(1);
}

void Controlador::creacionBackup(){
    vistaSeguridad nuevaVista;
    nuevaVista.encabezado();
    if (nuevaVista.opcionRealizarCopia())
    {
        if(Archivo::crearBackUpUsuario() && Archivo::crearBackUpProducto())
        {
            nuevaVista.interfazExito(1);
        }
        else
            nuevaVista.interfazError(1);
    }
}

void Controlador::restauracionBackup(){
    //Instancio nueva vista
    vistaSeguridad nuevaVista;
    nuevaVista.encabezado();
    //Si la opcion ingresada es la de restaurar copia entro al IF
    if (nuevaVista.opcionRestaurarCopia())
    {
        //Si logre restaurar Backup de Usuario y producto, muestro mensaje de exito
        if(Archivo::restaurarBackUpUsuario() && Archivo::restaurarBackUpProducto())
            nuevaVista.interfazExito(2);
        else
            nuevaVista.interfazError(2);
    }
}

void Controlador::cargarVenta(char *u)
{
//Instancia vista nueva de venta
    vistaVenta nueva(u);
    Venta n;
    Producto *lista;
//Vector dinamico de productos, donde voy a cargar los productos disponibles para pasarselos a la vista y que los muestre
    int cantidadProductos;
//Cantidad de objetos correspondientes a producto
    Archivo::cantidadDeObjetos(&cantidadProductos,2);
//El metodo estatico me devuelve 1 si pudo cargar en el vector dinamico que creamos todos los productos que estan guardados
    if (Archivo::listaDeProductos(lista=new Producto[cantidadProductos],cantidadProductos))
    {
        nueva.cargaDeVenta(lista,cantidadProductos);
        if (nueva.getMontoDeVenta()>0)
        {
            n=nueva.getVenta();
            if (Archivo::guardarVenta(n)){
            nueva.msjExito();
            }
            else nueva.msjError();
        }
    }
    else{
     nueva.msjErrorListaProd();
    }
    delete lista;
}
