#include "gui.h"
#include "render.h"
#include <unistd.h>

int window_start() {
	int max_y, max_x;
	char text[] = "Hallo";
	
	initscr();
	noecho();						// dont print keyboard input
	curs_set(FALSE);				// hide cursor

	refresh();
	
	getmaxyx(stdscr, max_y, max_x);
	
	WINDOW *win_background =	newwin(max_y, max_x-1, 0, 1);
	WINDOW *win_text =			newwin(20, 40, (max_y/2)-10, (max_x/2)-20);
	
	// draw our borders
	draw_border(win_background);
	mvwprintw(win_background, max_y-1, 5, "|| Press <q> to exit ||");
	
	wrefresh(win_background);
	
	draw_text(win_text, text);
	wrefresh(win_text);

	getch();

	delwin(win_background);
	delwin(win_text);

	endwin();
	
	return 0;
}
