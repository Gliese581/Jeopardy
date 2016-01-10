CC = gcc

CFLAGS = -I ./lib -std=c99 -Wall -c -g
LFLAGS = -lncurses

OS = $(shell uname)

SRCDIR = src
OBJDIR = obj
SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))

ifeq ($(findstring Linux,$(OS)),Linux)
	EXEC = jeopardy
endif

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $@
			
obj/%.o: src/%.c | obj
	$(CC) $< -c $(CFLAGS) -o $@
			
obj:
	mkdir obj

clean:
	rm $(OBJ)
	rmdir $(OBJDIR)
	rm $(EXEC)
