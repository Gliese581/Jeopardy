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
		i++;
	}
}
void draw_border(WINDOW *screen) {
	wborder(screen, ACS_VLINE, ACS_VLINE, ACS_HLINE, ACS_HLINE, ACS_ULCORNER, ACS_URCORNER, ACS_LLCORNER, ACS_LRCORNER);
}
