#include <stdio.h>
#include <ncurses.h>
#include <stdlib.h>

#define WIDTH 30
#define HEIGHT 10

int startx = 0;
int starty = 0;

char *choices[] = {
			"Chat 1",
			"Chat 2",
			"Chat 3",
			"Chat 4",
			"Exit",
		  };
int n_choices = sizeof(choices) / sizeof(char *);
void print_menu(WINDOW *menu_win, int highlight);

int main()
{
  WINDOW *menu_win;
  system("resize -s 30 80");
	int highlight = 1;
	int choice = 0;
	int c;

	initscr();
	clear();
	noecho();
	cbreak();	/* Line buffering disabled. pass on everything */
	startx = (80 - WIDTH) / 2;
	starty = (30 - HEIGHT) / 2;

	menu_win = newwin(HEIGHT, WIDTH, starty, startx);
	keypad(menu_win, TRUE);
    start_color();
  init_pair(1, COLOR_WHITE, COLOR_BLACK);
  init_pair(2, COLOR_BLUE, COLOR_WHITE);
  bkgd(COLOR_PAIR(2));
  wbkgd(menu_win, COLOR_PAIR(2));

  attron(COLOR_PAIR(1));
  mvprintw(1, 7, "                                                                ");
	mvprintw(2, 7, "  _____                             _  _____ _             _    ");
  mvprintw(3, 7, " |  __ \\_    _ ___  _____ ________ (_)/ ____| |__  _______| |_  ");
  mvprintw(4, 7, " | |  \\ \\\\  / | _ \\/  _  |  _   _ \\| | /    |  _ \\/  _  |_   _| ");
  mvprintw(5, 7, " | |__/ / \\/ / / \\ | |_| | / \\ / \\ | | \\____| / \\ | |_| | | |_  ");
  mvprintw(6, 7, " |_____/ \\  /|_| |_|__/\\_|_| |_| |_|_|\\_____|_| |_|__/\\_| |___| ");
  mvprintw(7, 7, "        _/ /                                                    ");
  mvprintw(8, 7, "        \\_/                                                     ");
  mvprintw(9, 7, "                                                                ");
  attroff(COLOR_PAIR(1));

	refresh();
  attron(COLOR_PAIR(2));
	print_menu(menu_win, highlight);
	while(1)
	{	c = wgetch(menu_win);
		switch(c)
		{	case KEY_UP:
				if(highlight == 1)
					highlight = n_choices;
				else
					--highlight;
				break;
			case KEY_DOWN:
				if(highlight == n_choices)
					highlight = 1;
				else
					++highlight;
				break;
			case 10:
				choice = highlight;
				break;
			default:
				mvprintw(24, 0, "Charcter pressed is = %3d Hopefully it can be printed as '%c'", c, c);
				refresh();
				break;
		}
		print_menu(menu_win, highlight);
		if(choice != 0)	/* User did a choice come out of the infinite loop */
			break;
	}
	mvprintw(23, 0, "You chose choice %d with choice string %s\n", choice, choices[choice - 1]);
  attroff(COLOR_PAIR(2));
	clrtoeol();
	refresh();
	endwin();
	return 0;
}


void print_menu(WINDOW *menu_win, int highlight)
{
	int x, y, i;
  start_color();
init_pair(3, COLOR_BLACK, COLOR_WHITE);
	x = 2;
	y = 2;

	box(menu_win, 0, 0);

	for(i = 0; i < n_choices; ++i)
	{	if(highlight == i + 1) /* High light the present choice */
		{	wattron(menu_win, COLOR_PAIR(3));
			mvwprintw(menu_win, y, x, "%s", choices[i]);
			wattroff(menu_win, COLOR_PAIR(3));
		}
		else
			mvwprintw(menu_win, y, x, "%s", choices[i]);
		++y;
	}
	wrefresh(menu_win);
}
