#ifndef VISTASEGURIDAD_H_INCLUDED
#define VISTASEGURIDAD_H_INCLUDED

class vistaSeguridad {
private:
    bool exit;
    const char *flecha;
    int posFlecha;
    char tecla;
public:
    vistaSeguridad();
    void encabezado(); //Encabezado para "Segurida"
    bool opcionRestaurarCopia(); //Interfaz de opciones para Restaurar copia
    bool opcionRealizarCopia(); //Interfaz de opciones para Realizar copia
    void interfazExito(int opcion); //Mensaje de exito
    void interfazError(int opcion); //Mensaje de error

};

#endif // VISTASEGURIDAD_H_INCLUDED
