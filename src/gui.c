#include "gui.h"
#include "render.h"
#include <unistd.h>


int window_start() {
	int max_y, max_x;
	
	initscr();
	start_color();
	clear();
	refresh();
	
	init_color(COLOR_LOGO, 1000, 500, 1000);
	init_pair(1, COLOR_LOGO, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	
	noecho();						// dont print keyboard input
	curs_set(FALSE);				// hide cursor

	getmaxyx(stdscr, max_y, max_x);
	
	WINDOW *win_background	= newwin(max_y, max_x-1, 0, 1);
	WINDOW *win_logo		= newwin(9, 72, (max_y/2)-4, (max_x/2)-36);
	
	// draw our borders
	draw_border(win_background);
	mvwaddstr(win_background, max_y-1, 5, "|| Press <q> to exit||");
	wrefresh(win_background);
	
	wattrset(win_logo, A_ALTCHARSET | COLOR_PAIR(1));
	draw_logo(win_logo);

	while (getch() != 'q') { }
	
	delwin(win_background);
	delwin(win_logo);

	endwin();
	
	return 0;
}
