CC = gcc
CFLAGS = -std=c99 -Wall -c
LFLAGS = -lncurses

all: game

game: game.o gui.o
	$(CC) $(LFLAGS) game.o gui.o -o game

game.o: game.c
	$(CC) $(CFLAGS) game.c

gui.o: gui.c
	$(CC) $(CFLAGS) gui.c

clean:
	rm *.o game
