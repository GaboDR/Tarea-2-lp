#ifndef H_TABLERO
#define H_TABLERO
#include "Dificultades.h"

extern void *** tablero;
extern int tamano;
extern int game_over;
extern int barcos_f;

typedef struct Casillas
{
    int estado; // 0 errado, 1 ocupada, 2 destruida
}Casillas;


/*
***
Parametro 1 : None
***
Retorno: int
***
Esta función genera de forma aleatoria una orientación, devolviendo 0 para vertical y 1 para horizontal.
*/
int Horizontal_vertical();

/*
***
Parametro 1 : int tamano
***
Retorno: None
***
Esta función inicializa un tablero de tamaño "tamano" en memoria dinámica, donde cada casilla es un puntero a vacío (NULL) inicialmente.
*/
void inicializarTablero(int tamano);

/*
***
Parametro 1 : None
***
Retorno: None
***
Esta función imprime el estado del tablero en consola, mostrando 'O' para agua, 'S' para un barco completo, y 'X' para una parte dañada del barco.
*/
void mostrarTablero();

/*
***
Parametro 1 : int numero
Parametro 2 : int medida
***
Retorno: None
***
Inserta un número de barcos de una medida específica en el tablero, asegurándose de que no haya colisiones con otros barcos.
*/
void insertar_barco(int numero, int medida);

/*
***
Parametro 1 : Dificultades * dificultad
***
Retorno: None
***
Llena el tablero con barcos según los valores de la dificultad pasada, insertando barcos de medidas desde 2 hasta 5.
*/
void llenarTablero(Dificultades * dificultad);

/*
***
Parametro 1 : None
***
Retorno: None
***
Libera la memoria dinámica del tablero, eliminando todas las casillas y el tablero en sí.
*/
void limpiar();


#endif
