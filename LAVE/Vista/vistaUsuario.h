#ifndef VISTAUSUARIO_H_INCLUDED
#define VISTAUSUARIO_H_INCLUDED
#include "../Modelo/usuario.h"
#include "../Modelo/validador.h"
#include "../Controlador/controlador.h"

class vistaUsuario {
private:
    Usuario auxiliar;
    char aux[50];
public:
    void encabezado(int i);
    void cargaDeUsuario();
    int ingresoID();
    bool bajaDeUsuario(Usuario u);
    bool modificacionDeRol(Usuario &u);
    bool modificacionHorarioFichaje(Usuario);
    void msjExito(int i);
    void msjError(int i);
    Usuario getUsuario();
};

#endif // VISTAUSUARIO_H_INCLUDED
