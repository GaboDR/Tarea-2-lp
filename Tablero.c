#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Dificultades.h"
#include "Tablero.h"


int Horizontal_vertical(){
    srand(time(NULL));
    return rand() % 2;

}

void inicializarTablero(int tamano){
    tablero = (void ***) malloc(tamano * sizeof(void **));
    for(int i = 0; i < tamano; i++){
        tablero[i] = (void **) malloc(tamano * sizeof(void *));
        for(int j = 0; j < tamano; j++){
            /*
            int *estado = (int *) malloc(sizeof(int));
            *estado = 0;*/
            tablero[i][j] = NULL;
        }
    }
}

void mostrarTablero(){
    for(int i = 0; i< tamano; i++){
        for (int j = 0; j < tamano; j++){
            if (tablero[i][j] == NULL){
                printf("| ");
                }
            else{
                char mostrar = ' ';
                if(((Casillas *) tablero[i][j])->estado == 0){
                     mostrar = 'O';
                    printf("|%c", mostrar);
                }
                 else if (((Casillas *) tablero[i][j])->estado == 1 && game_over == 1){
                     mostrar = 'S';
                    printf("|%c", mostrar);

                    }
                else if (((Casillas *) tablero[i][j])->estado == 2){
                     mostrar = 'X';
                    printf("|%c", mostrar);
                    }    
                
                else {
                    printf("| ");
                }
                }
            }
        printf("|\n");
        
        }
    }

void insertar_barco(int numero, int medida){

    srand(time(NULL));

    for (int i = 0; i < numero; i++) {
        int x, y, orientacion;
        int sePuedeColocar;

        do {
            sePuedeColocar = 1;  // Asumimos que se puede colocar

            // Generar coordenadas aleatorias dentro de los límites del tablero
            orientacion = Horizontal_vertical();


            // Verificar si se puede colocar el barco de forma más eficiente
            if (orientacion == 1) { // Horizontal

                x = rand() % (tamano - medida);  // Asegurar que haya espacio para el barco
                y = rand() % (tamano);
                for (int j = x; j < x + medida; j++) {
                    if (tablero[j][y] != NULL) {
                        sePuedeColocar = 0;
                        break;
                    }
                }
            } else { // Vertical
                x = rand() % (tamano );  // Asegurar que haya espacio para el barco
                y = rand() % (tamano -medida);


                for (int j = y; j < y + medida; j++) {
                    if (tablero[x][j] != NULL) {
                        sePuedeColocar = 0;
                        break;
                    }
                }
            }

        } while (!sePuedeColocar);

        if (orientacion == 1) {
            for (int j = x; j < x + medida; j++) {
                tablero[j][y] = malloc(sizeof(Casillas));
                ((Casillas *)tablero[j][y])->estado = 1;
                barcos_f +=1;

            }
        } else {
            for (int j = y; j < y + medida; j++) {              
                tablero[x][j] = malloc(sizeof(Casillas));
                ((Casillas *)tablero[x][j])->estado = 1;
                barcos_f +=1;

            }
        }
    }
}

void llenarTablero(Dificultades * dificultad){
    for (int i = 0; i < 4; i++){
        int cantidad = dificultad->barcos[i];
        insertar_barco(cantidad, i+2);
    }

    
}

void limpiar(){
    for (int i = 0; i < tamano; i++) {
        if (tablero[i] != NULL) {
            for (int j = 0; j < tamano; j++) {
                if (tablero[i][j] != NULL) {
                    free(tablero[i][j]);
                    tablero[i][j] = NULL;
                }
            }
            free(tablero[i]);
            tablero[i] = NULL;
        }
    }
    free(tablero);
    tablero = NULL;
}
