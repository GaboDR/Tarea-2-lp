#include <stdlib.h>
#include <stdio.h>
#include "Cartas.h"
#include "Tablero.h"
#include "Dificultades.h"
#include "consolas.c"

void *** tablero;
Mano Cartas;
int tamano;
int canon_caido = 0;
int game_over = 0;
extern int barcos_f;

Dificultades * dificultad; 

int main(int argc, char const *argv[])
{

    Dificultades *dificultad = (Dificultades *)malloc(sizeof(Dificultades));

    tamano = seleccionNiveles(dificultad);
    inicializarTablero(tamano);
    llenarTablero(dificultad);
    inicializarMazo();
    int turno =1;
    while (barcos_f >0 && turno <=dificultad->turnos)
    {
    printf("Turno: %d\n",turno++);
    mostrarTablero();
    mostrarMazo();
    usarCarta();
    }
    game_over = 1;
    if (barcos_f == 0)
    {
        printf("TODOS LOS BARCOS DESTRUIDOS , DEFENZA EXITOSA !");
    }
    else{
        printf("PERDISTE ");
    }
    printf("\n Tablero final:\n");
    mostrarTablero();
    liberarMano();
    limpiar();

}
/*
{
    tablero = (void ***) malloc(tamano * sizeof(void **));
    for(int i = 0; i < tamano; i++){
        tablero[i] = (void **) malloc(tamano * sizeof(void *));
        for(int j = 0; j < tamano; j++){
            int *estado = (int *) malloc(sizeof(int));
            *estado = 0;

            tablero[i][j] = (void *) malloc( sizeof(Casilla));
            Casilla *casilla = (Casilla *) tablero[i][j];
            //(Casilla *) tablero[i][j] = casilla;
            casilla->ocupacion = 0;
            casilla->barco=NULL;
            //((int *) tablero[i])[j] = tamano*i + j;
            printf("|%3d",*estado);
        }
        printf("|\n");
    }
    return 0;
}
*/