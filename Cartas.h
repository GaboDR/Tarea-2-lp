#ifndef H_CARTAS
#define H_CARTAS

typedef struct Mano
{
    void ** carta;
    int disponibles;
} Mano;

extern Mano Cartas;
extern int canon_caido;
extern int tamano;

/*
***
Parametro 1 : None
***
Retorno: None
***
Libera la memoria utilizada para almacenar las cartas en la mano.
*/
void liberarMano();

/*
***
Parametro 1 : int x
Parametro 2 : int y
***
Retorno: None
***
Realiza un disparo en la posición (x, y) del tablero. Si no hay barco en la posición, imprime "Miss". Si impacta un barco, cambia su estado y decrece el contador de barcos.
*/
void disparar(int x, int y);

/*
***
Parametro 1 : None
***
Retorno: None
***
Inicializa el mazo de cartas con cinco cartas predefinidas, todas asignadas inicialmente a disparoSimple.
*/
void inicializarMazo();

/*
***
Parametro 1 : None
***
Retorno: None
***
Muestra las cartas disponibles en el mazo, indicando los tipos de disparo asignados a cada una.
*/
void mostrarMazo();

/*
***
Parametro 1 : None
***
Retorno: None
***
Permite al usuario seleccionar una carta y luego ingresar las coordenadas donde se realizará el disparo utilizando la función asociada a la carta seleccionada.
*/
void usarCarta();

/*
***
Parametro 1 : int x
Parametro 2 : int y
***
Retorno: void *
***
Disparo simple en las coordenadas (x, y). Si se cumple una condición aleatoria, devuelve una carta nueva para seguir disparando.
*/
void *disparoSimple(int x, int y);

/*
***
Parametro 1 : int x
Parametro 2 : int y
***
Retorno: void *
***
Disparo grande en un área de 3x3 centrada en las coordenadas (x, y). Dependiendo de una condición aleatoria, devuelve una carta nueva para seguir disparando.
*/
void *disparoGrande(int x, int y);

/*
***
Parametro 1 : int x
Parametro 2 : int y
***
Retorno: void *
***
Realiza un disparo lineal en la coordenada (x, y) en una línea de 5 casillas en horizontal o vertical, dependiendo de la orientación.
*/
void *disparoLineal(int x, int y);

/*
***
Parametro 1 : int x
Parametro 2 : int y
***
Retorno: void *
***
Disparo radar que detecta si hay algún barco en las cercanías de 5x5 alrededor de las coordenadas (x, y).
*/
void *disparoRadar(int x, int y);

/*
***
Parametro 1 : int x
Parametro 2 : int y
***
Retorno: void *
***
Realiza un disparo en un área de 11x11 centrada en las coordenadas (x, y) y desactiva el cañón.
*/
void *disparo500KG(int x, int y);

#endif