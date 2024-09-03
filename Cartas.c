#include <stdlib.h>
#include <stdio.h>
#include "Cartas.h"
#include "Tablero.h"


Mano Cartas;
typedef void * (*FuncionDisparo)(int, int);
extern int canon_caido;


void inicializarMazo(){
    Cartas.carta = (void **) malloc(5 * sizeof(void*));
    for (int i = 0; i < 5; i++){
        Cartas.carta[i] = disparoSimple;
    }   
}

void mostrarMazo(){
    printf("Cartas: \n");
    for (int i = 0; i < 5- canon_caido; i++){
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

}

void * disparoSimple(int x, int y){

}
void * disparoGrande(int x, int y){

}
void * disparoLineal(int x, int y){

}
void * disparoRadar(int x, int y){

}
void * disparo500KG(int x, int y){

}