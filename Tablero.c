#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "Dificultades.h"


typedef struct Casillas
{
    int estado; // 0 errado, 1 ocupada, 2 destruida
}Casillas;

extern void *** tablero;
extern int tamano;


int Horizontal_vertical(){//0 vertical 1 horizontal
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
                if (((Casillas *) tablero[i][j])->estado == 1){
                     mostrar = 'S'; // se tiene que modificar pq mostrará siempre los barcos vivos y no tiene gracia
                    printf("|%c", mostrar);

                    }
                if (((Casillas *) tablero[i][j])->estado == 2){
                     mostrar = 'X';
                    printf("|%c", mostrar);
                    }    
                }
            }
        printf("|\n");
        
        }
    }

void insertar_barco(int numero, int medida){ //numero = canridad de bascos de esa medida

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

        // Colocar el barco
        printf("colocando barco: %d / %d orienracion: %d\n",x,y,orientacion);
        if (orientacion == 1) {
            for (int j = x; j < x + medida; j++) {
                tablero[j][y] = malloc(sizeof(Casillas));
                ((Casillas *)tablero[j][y])->estado = 1;

            }
        } else {
            for (int j = y; j < y + medida; j++) {              
                tablero[x][j] = malloc(sizeof(Casillas));
                ((Casillas *)tablero[x][j])->estado = 1;
            }
        }
    }
}

void llenarTablero(Dificultades * dificultad){
    for (int i = 0; i < 4; i++){
        int cantidad = dificultad->barcos[i];
        printf("@@@ %d\n",cantidad);
        insertar_barco(cantidad, i+2);
    }

    
}

void limpiar(){
    for (int i = 0; i < tamano; i++) {
        for (int j = 0; j < tamano; j++) {
                free(tablero[i][j]);
        }
        free(tablero[i]);
    }
    free(tablero);
}