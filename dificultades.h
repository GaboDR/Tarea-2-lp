#ifndef DIFICULTADES_H
#define DIFICULTADES_H

typedef struct Dificultades {
    int dimensiones;
    int barcos[4];
    int turnos;
} Dificultades;

int seleccionNiveles(Dificultades * dificultad);
#endif // DIFICULTADES_H
