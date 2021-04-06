#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

int main()
{
	WINDOW *splashscreen;
	system("resize -s 22 120");
	initscr();
	splashscreen = newwin(10, 30, 25, 10);
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_BLUE);
  init_pair(2, COLOR_BLACK, COLOR_BLACK);
	init_pair(3, COLOR_GREEN, COLOR_BLACK);
	init_pair(4, COLOR_WHITE, COLOR_BLACK);
  bkgd(COLOR_PAIR(2));
	attron(COLOR_PAIR(1));
	mvprintw(1, 28, "                                                                ");
	mvprintw(2, 28, "  _____                             _  _____ _             _    ");
  mvprintw(3, 28, " |  __ \\_    _ ___  _____ ________ (_)/ ____| |__  _______| |_  ");
  mvprintw(4, 28, " | |  \\ \\\\  / | _ \\/  _  |  _   _ \\| | /    |  _ \\/  _  |_   _| ");
  mvprintw(5, 28, " | |__/ / \\/ / / \\ | |_| | / \\ / \\ | | \\____| / \\ | |_| | | |_  ");
  mvprintw(6, 28, " |_____/ \\  /|_| |_|__/\\_|_| |_| |_|_|\\_____|_| |_|__/\\_| |___| ");
  mvprintw(7, 28, "        _/ /                                                    ");
  mvprintw(8, 28, "        \\_/                                                     ");
  mvprintw(9, 28, "                                                                ");
	attroff(COLOR_PAIR(1));
	attron(COLOR_PAIR(3));
	mvprintw(10, 28, "                  Secure communications, all from your terminal.");
	attroff(COLOR_PAIR(3));
	attron(A_BLINK);
	attron(COLOR_PAIR(4));
	mvprintw(13, 28, "                  (press any key to continue)                  ");
	attroff(COLOR_PAIR(4));
	attroff(A_BLINK);
	refresh();
	getch();
	endwin();
	return 0;
}
