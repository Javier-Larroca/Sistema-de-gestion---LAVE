#ifndef VALIDADOR_H_INCLUDED
#define VALIDADOR_H_INCLUDED

/**Validador de ingreso en diferentes campos. Podremos implementar los metodos estaticos de esta clase sin necesidad de instanciar un objeto.
A medida que necesitemos, vamos a agregando las validaciones en diferentes campos que creamos necesario.
*/

class Validador{

    public:
    static void validaIngresoDeNombre(char *n);
    static void validaNumero(char *n);
    static void validaIdLogin(char *id);

};

#endif // VALIDADOR_H_INCLUDED
