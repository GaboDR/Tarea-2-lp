CC = gcc
CFLAGS = -Wall

all: ejecutable

ejecutable: CityDefender.o Tablero.o Cartas.o
	$(CC) $(CFLAGS) -o ejecutable CityDefender.o Tablero.o Cartas.o

CityDefender.o: CityDefender.c Tablero.h Cartas.h
	$(CC) $(CFLAGS) -c CityDefender.c

Tablero.o: Tablero.c Tablero.h Cartas.h dificultades.h
	$(CC) $(CFLAGS) -c Tablero.c

Cartas.o: Cartas.c Tablero.h Cartas.h
	$(CC) $(CFLAGS) -c Cartas.c


clean:
	rm -f ejecutable main.o Tablero.o Cartas.o 
run:
	./ejecutable