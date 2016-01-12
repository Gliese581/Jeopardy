#include "render.h"
#include <string.h>
#include <unistd.h>

char *JeopardyLogo[9] =
{
	"",
	"JJJJJJJ  EEEEEEE    OOO    PPPPPP      A     RRRRRR   DDDDD    Y     Y",
    "      J  E         O   O   P     P    A A    R     R  D    D    Y   Y ",
    "      J  E        O     O  P     P   A   A   R     R  D     D    Y Y  ",
    "      J  EEEEE    O     O  PPPPPP   AAAAAAA  RRRRRR   D     D     Y   ",
    "      J  E        O     O  P        A     A  R R      D     D     Y   ",
    "     J   E         O   O   P        A     A  R  R     D    D     Y    ",
    " JJJJ    EEEEEEE    OOO    P        A     A  R   R    DDDDD     Y     ",
    ""
};

void draw_logo(WINDOW *screen) {
    int i = 0;
	while (JeopardyLogo[i]) {
		mvwaddstr(screen, i, 1, JeopardyLogo[i]);
		wrefresh(screen);
		napms(200);
		i++;
	}
}
void draw_border(WINDOW *screen) {
	int x, y, i;
	getmaxyx(screen, y, x);
	
	// 4 corners
	mvwaddch(screen, 0, 0, ACS_ULCORNER);
	mvwaddch(screen, y - 1, 0, ACS_LLCORNER);
	mvwaddch(screen, 0, x - 1, ACS_URCORNER);
	mvwaddch(screen, y - 1, x - 1, ACS_LRCORNER);
	// sides
	for (i = 1; i < (y - 1); i++) {
		mvwaddch(screen, i, 0, ACS_VLINE);
		mvwaddch(screen, i, x - 1, ACS_VLINE);
	}
	// top and bottom
	for (i = 1; i < (x - 1); i++) {
		mvwaddch(screen, 0, i, ACS_HLINE);
		mvwaddch(screen, y - 1, i, ACS_HLINE);
	}
}
