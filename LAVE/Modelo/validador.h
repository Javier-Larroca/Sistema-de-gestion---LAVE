#ifndef VALIDADOR_H_INCLUDED
#define VALIDADOR_H_INCLUDED

/**Validador de ingreso en diferentes campos. Podremos implementar los metodos estaticos de esta clase sin necesidad de instanciar un objeto.
A medida que necesitemos, vamos a agregando las validaciones en diferentes campos que creamos necesario.
*/

class Validador{

    public:
    static void validaIngresoDeNombre(char *n);
    static void validaNumero(char *n, int *i);
    static void validaIdLogin(char *id);
    static bool validaEspacios(char *n);
    static int validaRol(char *n);

};

#endif // VALIDADOR_H_INCLUDED
