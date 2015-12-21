#include "render.h"

void draw_text(WINDOW *screen) {
	int x, y;
	getmaxyx(screen, y, x);

	for (int i = 0; i < (y - 1); i++) {
		mvwaddch(screen, 2, i, ACS_DIAMOND);
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
