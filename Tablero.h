#ifndef H_TABLERO
#define H_TABLERO
#include "Dificultades.h"

extern void *** tablero;

void inicializarTablero(int tamano);
void mostrarTablero();
void llenarTablero(Dificultades * dificultad);
void limpiar();

#endif
