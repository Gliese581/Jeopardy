#include "gui.h"
#include "render.h"
#include <unistd.h>


int window_start() {
	int max_y, max_x;
	
	initscr();
	noecho();						// dont print keyboard input
	curs_set(FALSE);				// hide cursor

	refresh();
	
	getmaxyx(stdscr, max_y, max_x);
	
	WINDOW *win_background	= newwin(max_y, max_x-1, 0, 1);
	WINDOW *win_logo		= newwin(9, 72, (max_y/2)-4, (max_x/2)-36);
	
	// draw our borders
	draw_border(win_background);
	mvwprintw(win_background, max_y-1, 5, "|| Press <q> to exit ||");
	
	wrefresh(win_background);
	
	//draw_logo(win_text);
	//wrefresh(win_text);

	int n = 0;
	while(n < 10) {
		draw_border(win_logo);
		draw_logo(win_logo);
		napms(1000);
		wclear(win_logo);
		n++;
		getch();
	}

	delwin(win_background);
	delwin(win_logo);

	endwin();
	
	return 0;
}
