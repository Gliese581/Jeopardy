CC = g++

CFLAGS = -std=c++1y -Wpedantic -Werror -Wextra -Wall -Wconversion -I ./lib -w
LFLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf -lSDL2_mixer


SRCDIR = src
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.cpp)
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.cpp=.o)))

EXEC = jeopardy

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $@
					
obj/%.o: $(SRCDIR)/%.cpp | $(OBJDIR)
	$(CC) $< -c $(CFLAGS) -o $@
					
obj:
	mkdir obj

clean:
	rm $(OBJ)
	rmdir $(OBJDIR)
	rm $(EXEC)
