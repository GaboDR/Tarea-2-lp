#include <stdlib.h>
#include <stdio.h>
#include "Cartas.h"
#include "Tablero.h"

int barcos_f;
typedef void * (*FuncionDisparo)(int, int);

void liberarMano() {
    if (Cartas.carta != NULL) {
        free(Cartas.carta);
        Cartas.carta = NULL;
    }
}

void disparar(int x, int y){
    if (tablero[x][y] == NULL){
        tablero[x][y] = malloc(sizeof(Casillas));
        ((Casillas *)tablero[x][y])->estado = 0;
    }
    else if (((Casillas *)tablero[x][y])->estado == 1){
        ((Casillas *)tablero[x][y])->estado = 2;
        barcos_f -= 1;
        printf("Hit!!\n");
    }
}

void inicializarMazo(){
    Cartas.carta = (void **) malloc(5 * sizeof(void*));
    for (int i = 0; i < 5; i++){
        Cartas.carta[i] = disparoSimple;
    }
}

void mostrarMazo(){
    printf("Cartas: \n");
    for (int i = 0; i < 5 - canon_caido; i++){
        if (Cartas.carta[i] == disparoSimple){
            printf("Simple | ");
        }
        else if (Cartas.carta[i] == disparoLineal){
            printf("Lineal | ");
        }
        else if (Cartas.carta[i] == disparoRadar){
            printf("Radar | ");
        }
        else if (Cartas.carta[i] == disparoGrande){
            printf("Grande | ");
        }
        else if (Cartas.carta[i] == disparo500KG){
            printf("500kg | ");
        }
    } 
    printf("\n");
}

void usarCarta(){
    int numero;
    int cooX;
    int cooY;

    do {
        printf("Seleccione una carta : ");
        scanf("%d", &numero);

        if (numero < 1 || numero > 5 ) {
            printf("Número de carta no válido. Intente nuevamente.\n");
        }
        else if (Cartas.carta[numero-1] == NULL){
            printf("Canon deshabilitado. Intente nuevamente.\n");
        }
    } while (numero < 1 || numero > 5 || Cartas.carta[numero-1] == NULL);

    do {
        printf("\nX: ");
        scanf("%d", &cooX);

        if (cooX < 0 || cooX > tamano) {
            printf("Coordenada X no válida. Intente nuevamente.\n");
        }
    } while (cooX < 0 || cooX > tamano);

    do {
        printf("\nY : ");
        scanf("%d", &cooY);

        if (cooY < 0 || cooY > tamano) {
            printf("Coordenada Y no válida. Intente nuevamente.\n");
        }
    } while (cooY < 0 || cooY > tamano);

    FuncionDisparo funcion = (FuncionDisparo)Cartas.carta[numero - 1];
    Cartas.carta[numero - 1] = funcion(cooY - 1, cooX - 1);
}

void *disparoSimple(int x, int y) {
    disparar(x, y);    
    int retorno = rand() % 100;
    if (retorno < 65) {
        return disparoSimple;
    } else if (retorno < 85) {
        return disparoGrande;
    } else if (retorno < 90) {
        return disparoLineal;
    } else {
        return disparoRadar;
    }
}

void *disparoGrande(int x, int y) {

    for (int i = x - 1; i < x + 2; i++){
        for (int j = y - 1; j < y + 2; j++){
            if (i >= 0 && i < tamano && j >= 0 && j < tamano){
                disparar(i, j);
            }
        }
    }

    int retorno = rand() % 100;

    if (canon_caido) {
        do {
            retorno = rand() % 100;
        } while (retorno >= 98);
    }

    if (retorno < 80) {
        return disparoSimple;
    } else if (retorno < 83) {
        return disparoGrande;
    } else if (retorno < 93) {
        return disparoLineal;
    } else if (retorno < 98) {
        return disparoRadar;
    } else {
        return disparo500KG;
    }
}

void *disparoLineal(int x, int y) {

    int orientacion = Horizontal_vertical();

    if (orientacion == 0){
        for (int i = y - 2; i < y + 3; i++){
            if (i >= 0 && i < tamano){
                disparar(x, i);
            }
        }
    } else {
        for (int i = x - 2; i < x + 3; i++){
            if (i >= 0 && i < tamano){
                disparar(i, y);
            }
        }
    }

    int retorno = rand() % 100;

    if (canon_caido) {
        do {
            retorno = rand() % 100;
        } while (retorno >= 98);
    }

    if (retorno < 85) {
        return disparoSimple;
    } else if (retorno < 90) {
        return disparoGrande;
    } else if (retorno < 92) {
        return disparoLineal;
    } else if (retorno < 98) {
        return disparoRadar;
    } else {
        return disparo500KG;
    }
}

void *disparoRadar(int x, int y) {
    int radar = 0;
    for (int i = x - 2; i < x + 3; i++){
        for (int j = y - 2; j < y + 3; j++){
            if (i >= 0 && i < tamano && j >= 0 && j < tamano){
                if (tablero[i][j] != NULL && ((Casillas *)tablero[i][j])->estado == 1){
                    radar = 1;
                    break;
                }
            }
        }
        if (radar){
            printf("Hay barco/s en la zona\n");
            break;
        }
    }

    int retorno = rand() % 100;

    if (canon_caido) {
        do {
            retorno = rand() % 100;
        } while (retorno >= 97);
    }

    if (retorno < 75) {
        return disparoSimple;
    } else if (retorno < 90) {
        return disparoGrande;
    } else if (retorno < 95) {
        return disparoLineal;
    } else if (retorno < 97) {
        return disparoRadar;
    } else {
        return disparo500KG;
    }
}

void *disparo500KG(int x, int y) {
    for (int i = x - 5; i < x + 6; i++){
        for (int j = y - 5; j < y + 6; j++){
            if (i >= 0 && i < tamano && j >= 0 && i < tamano){
                disparar(i, j);
            }
        }
    }
    canon_caido = 1;
    return NULL;
}
