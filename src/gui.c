#include "gui.h"
#include "render.h"

int window_start() {
	int max_y, max_x;
	
	initscr();
	noecho();						// dont print keyboard input
	curs_set(FALSE);				// hide cursor

	refresh();
	
	getmaxyx(stdscr, max_y, max_x);
	
	WINDOW *background =	newwin(max_y, max_x-1, 0, 1);
	WINDOW *text =			newwin(20, 40, (max_y/2)-10, (max_x/2)-20);
	
	// draw our borders
	draw_border(background);
	mvwprintw(background, max_y-1, 5, "|| Press <q> to exit ||");
	draw_text(text);

	wrefresh(background);
	wrefresh(text);

	getch();

	delwin(background);
	delwin(text);

	endwin();
	
	return 0;
}
