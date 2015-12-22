#include "render.h"
#include <string.h>
#include <unistd.h>

void draw_text(WINDOW *screen, char *text) {
	for (int i = 0; i < strlen(text); i++) {
		char letter_array[3];
		get_letter_array(letter_array, text[i]);
		for (int j = 0; j < 3; j++) {
			mvwprintw(screen, j, i, "%c", letter_array[j]);
		}
	}
}

void get_letter_array(char *letter_array, char letter) {
	letter_array[0] = letter;
	letter_array[1] = letter;
	letter_array[2] = letter;
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
