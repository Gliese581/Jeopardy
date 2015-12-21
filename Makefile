CC = gcc
CFLAGS = -I ./include -std=c99 -Wall -c
LFLAGS = -lncurses

OBJDIR = obj
SRCDIR = src

OBJ = $(addprefix $(OBJDIR)/, game.o gui.o)

all: game

game: $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o game

$(OBJDIR)/%.o: $(SRCDIR)/%.c 
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm obj/*.o game
	rmdir obj
