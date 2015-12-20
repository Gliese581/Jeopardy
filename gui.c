#include <ncurses.h>						/* ncurses.h includes stdio.h */  
#include <string.h>
#include "gui.h"

int window_start() {
	char mesg[]="Jeopardy";					/* message to be appeared on the screen */
	int row,col;							/* to store the number of rows and *
											 * the number of colums of the screen */
	initscr();								/* start the curses mode */
	getmaxyx(stdscr,row,col);				/* get the number of rows and columns */
	mvprintw(row/2,(col-strlen(mesg))/2,"%s",mesg);
											/* print the message at the center of the screen */
	mvprintw(row-1,0,"Press <q> to exit.\n");
	refresh();
	getch();
	endwin();
	
	return 0;
}
