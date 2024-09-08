#include <stdlib.h>
#include <stdio.h>
#include "Cartas.h"
#include "Tablero.h"
#include "Dificultades.h"

int seleccionNiveles(Dificultades * dificultad){
    
    int opcion;
    printf("Selecciona la Dificultad:\n");
    printf("1. Facil  -> 11 X 11 , 5 Barcos\n");
    printf("2. Medio  -> 17 X 17 , 7 Barcos\n");
    printf("3. Dificil -> 21 X 21 , 9 Barcos\n");
    
    while (opcion<1 || opcion>3){
    printf("Ingrese un numero: ");
    scanf("%d", &opcion);
    switch (opcion) {
        case 1:
            dificultad->dimensiones = 11;
            dificultad->barcos[0] = 2;
            dificultad->barcos[1] = 1;
            dificultad->barcos[2] = 1;
            dificultad->barcos[3] = 1;
            dificultad->turnos = 30;

            printf("Has seleccionado: Facil\n");
            break;
        case 2:
            dificultad->dimensiones = 17;
            dificultad->barcos[0] = 3;
            dificultad->barcos[1] = 2;
            dificultad->barcos[2] = 1;
            dificultad->barcos[3] = 1;
            dificultad->turnos = 25;
            printf("Has seleccionado: Medio\n");
            break;
        case 3:
            dificultad->dimensiones = 21;
            dificultad->barcos[0] = 3;
            dificultad->barcos[1] = 2;
            dificultad->barcos[2] = 2;
            dificultad->barcos[3] = 2;
            dificultad->turnos = 30;
            printf("Has seleccionado: Dificil\n");
            break;
        default:
            printf("Opción no válida. Por favor, ingrese un número entre 1 y 3.\n");
    }

    }
    
    return dificultad->dimensiones;
}
