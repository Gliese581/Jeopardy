CC = gcc

CFLAGS = -I ./lib -std=c99 -Wall -c -g
LFLAGS = -lncurses

SRCDIR = src
OBJDIR = obj

SRC = $(wildcard $(SRCDIR)/*.c)
OBJ = $(addprefix $(OBJDIR)/,$(notdir $(SRC:.c=.o)))

EXEC = jeopardy

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CC) $(OBJ) $(LFLAGS) -o $@
			
obj/%.o: $(SRCDIR)/%.c | $(OBJDIR)
	$(CC) $< -c $(CFLAGS) -o $@
			
obj:
	mkdir obj

clean:
	rm $(OBJ)
	rmdir $(OBJDIR)
	rm $(EXEC)


CCWIN = x86_64-w64-mingw32.static-gcc

CFLAGSWIN = -I ./lib -I/home/parzival/Programme/mxe/usr/x86_64-w64-mingw32.static/include/ncurses -std=c99 -Wall -c -g
LFLAGSWIN = -lncurses -L/home/parzival/Programme/mxe/usr/x86_64-w64-mingw32.static/lib

SRCDIR = src
OBJDIRWIN = objw32

SRC = $(wildcard $(SRCDIR)/*.c)
OBJWIN = $(addprefix $(OBJDIRWIN)/,$(notdir $(SRC:.c=.o)))

EXECWIN = jeopardy.exe

win32: $(EXECWIN)

$(EXECWIN): $(OBJWIN)
	$(CCWIN) $(OBJWIN) $(LFLAGSWIN) -o $@
			
objw32/%.o: $(SRCDIR)/%.c | $(OBJDIRWIN)
	$(CCWIN) $< -c $(CFLAGSWIN) -o $@
			
objw32:
	mkdir objw32

clean-win32:
	rm $(OBJWIN)
	rmdir $(OBJDIRWIN)
	rm $(EXECWIN)
