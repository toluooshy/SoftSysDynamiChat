#include <form.h>

char cmd[1024];


int main(int argc, char *argv[])
{
	system("resize -s 30 80");
	FIELD *field[3];
	FORM  *my_form;
	int ch;

	/* Initialize curses */
	initscr();
	start_color();
	cbreak();
	noecho();
	keypad(stdscr, TRUE);
	curs_set(0);

	/* Initialize few color pairs */
	init_pair(1, COLOR_WHITE, COLOR_BLACK);
	init_pair(2, COLOR_BLUE, COLOR_WHITE);
	init_pair(3, COLOR_WHITE, COLOR_BLUE);

	/* Initialize the fields */
	field[0] = new_field(1, 20, 18, 38, 0, 0);
	field[1] = new_field(1, 20, 19, 38, 0, 0);
	field[2] = NULL;

	/* Set field options */
	set_field_back(field[0], A_UNDERLINE);/* and white foreground (characters */
						/* are printed in white 	*/
	field_opts_off(field[0], O_AUTOSKIP);  	/* Don't go to next field when this */
						/* Field is filled up 		*/
	set_field_back(field[1], A_UNDERLINE);
	field_opts_off(field[1], O_AUTOSKIP);

	/* Create the form and post it */
	my_form = new_form(field);
	post_form(my_form);

	bkgd(COLOR_PAIR(2));
  //wbkgd(menu_win, COLOR_PAIR(2));

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

	set_current_field(my_form, field[0]); /* Set focus to the colored field */
	attron(COLOR_PAIR(3));
	mvprintw(18, 19, "Chatroom Address:");
	mvprintw(19, 19, "Chatroom Keycode:");
	attroff(COLOR_PAIR(3));
	refresh();

	/* Loop through to get user requests */
	while((ch = getch()) != KEY_F(1))
	{	switch(ch)
		{
			case KEY_DOWN:
				/* Go to next field */
				form_driver(my_form, REQ_NEXT_FIELD);
				/* Go to the end of the present buffer */
				/* Leaves nicely at the last character */
				form_driver(my_form, REQ_END_LINE);
				break;
			case KEY_UP:
				/* Go to previous field */
				form_driver(my_form, REQ_PREV_FIELD);
				form_driver(my_form, REQ_END_LINE);
				break;
			case 10:
				mvprintw(25, 32, "enter pressed");
				/*
				char *new_window_val = getenv("IN_NEW_WINDOW");
			    const char *user_arg = argc < 2 ? "" : argv[1];
			    if (!new_window_val || new_window_val[0] != '1') {
			        snprintf(cmd, sizeof(cmd), "gnome-terminal -- sh -c './gui; exec bash'", argv[0], user_arg);
			        system(cmd);
			    }*/
				break;
			case KEY_BACKSPACE:
			case 127:
				form_driver(my_form, REQ_DEL_PREV);
				break;
			default:
				/* If this is a normal character, it gets */
				/* Printed				  */
				form_driver(my_form, ch);
				break;
		}
	}

	/* Un post form and free the memory */
	unpost_form(my_form);
	free_form(my_form);
	free_field(field[0]);
	free_field(field[1]);

	endwin();
	return 0;
}
