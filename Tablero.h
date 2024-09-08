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


void inicializarTablero(int tamano);
void mostrarTablero();
void llenarTablero(Dificultades * dificultad);
void limpiar();
int Horizontal_vertical();
void insertar_barco(int numero, int medida);

#endif
