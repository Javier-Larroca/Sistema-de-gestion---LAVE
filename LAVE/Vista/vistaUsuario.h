#ifndef VISTAUSUARIO_H_INCLUDED
#define VISTAUSUARIO_H_INCLUDED
#include "../Modelo/usuario.h"
#include "../Modelo/validador.h"

class vistaUsuario {
private:
    Usuario auxiliar;
public:
    void cargaDeUsuario();
    bool bajaDeUsuario(Usuario);
    bool modificacionDeRol(Usuario);
    bool modificacionHorarioFichaje(Usuario);
    void msjExito(int i);
    void msjError(int i);
    Usuario getUsuario();
};

#endif // VISTAUSUARIO_H_INCLUDED
