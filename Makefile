CC = gcc
CFLAGS = -std=c99 -Wall -c
LFLAGS = -lncurses

OBJDIR = obj

OBJ = $(addprefix $(OBJDIR)/, game.o gui.o)

all: game

game: $(OBJ)
	$(CC) $(LFLAGS) $(OBJ) -o game

$(OBJDIR)/%.o: %.c 
	@mkdir -p $(@D)
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	rm obj/*.o game
	rmdir obj
