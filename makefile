# Makefile para o projeto Minesweeper

CC = gcc
CFLAGS = -Wall -Wextra -std=c99
OBJ = main.o tabuleiro.o interface.o

all: minesweeper

minesweeper: $(OBJ)
	$(CC) $(CFLAGS) -o minesweeper $(OBJ)

main.o: main.c tabuleiro.h interface.h
	$(CC) $(CFLAGS) -c main.c

tabuleiro.o: tabuleiro.c tabuleiro.h
	$(CC) $(CFLAGS) -c tabuleiro.c

interface.o: interface.c interface.h tabuleiro.h
	$(CC) $(CFLAGS) -c interface.c

clean:
	rm -f *.o minesweeper