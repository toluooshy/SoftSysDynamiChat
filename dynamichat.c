/* tee.c
   Tolulope Oshinowo

   This program allows the user to enter input a string to be
   atored into the file specified by the '-a' append tag.
*/
#include "common.h"

int main(int argc, char *argv[])
{
  WINDOW *splashscreen;
  system("xdotool getactivewindow windowmove 100 0");
  system("echo -en \"\033]0;DynamiChat\a\"");
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

  system("clear");
  system("clear");

  char *filename = "";
  char *id = malloc(sizeof(char) * 1024);
  char *usr = malloc(sizeof(char) * 1024);
  char *opt = malloc(sizeof(char) * 1024);
  char input;
  char *str;
  char *message;
  char s[1024];
  char command[1024];
  FILE * doc;
  int totalchars;
  char chatroomcmd[1024] = "gnome-terminal -- /bin/sh -c './keyboard -i ";
  char xdotoolcmd[1024] = "xdotool windowactivate ";
  FILE *fp;
  char path[1024];

  printf(GF
    "\n\n\n\n\n\n"
    "                                              ENTER YOUR SESSION USERNAME:\n" WF
    "                           ┌─────────────────────────────────────────────────────────────────┐\n"
    "                           │                                                                 │\n"
    "                           └─────────────────────────────────────────────────────────────────┘\n"
  BF);
  gotoxy(30, 9);
  fgets(usr, 1024, stdin);

  system("clear");
  system("clear");

  printf(GF
    "\n\n\n\n\n\n"
    "                                                   ENTER CHATROOM ID:\n" WF
    "                           ┌─────────────────────────────────────────────────────────────────┐\n"
    "                           │                                                                 │\n"
    "                           └─────────────────────────────────────────────────────────────────┘\n"
  BF);
  gotoxy(30, 9);
  fgets(id, 1024, stdin);

  strcat(chatroomcmd, strtok(id,"\n"));
  strcat(chatroomcmd, " -u ");
  strcat(chatroomcmd, strtok(usr,"\n"));
  strcat(chatroomcmd, "'");


  char *new_window_val = getenv("IN_NEW_WINDOW");
  const char *user_arg = argc < 2 ? "" : argv[1];
  if (!new_window_val || new_window_val[0] != '1') {
    snprintf(cmd, sizeof(cmd), chatroomcmd, argv[0], user_arg);
    system(cmd);
    fp = popen("xdotool search --name \"DynamiChat Keyboard\"", "r");
    if (fp == NULL) {
      printf("Failed to run command\n" );
      exit(1);
    }
    while (fgets(path, sizeof(path), fp) != NULL) {
      printf("%s", path);
    }
    pclose(fp);
    system("clear");
    system("clear");
    strcat(xdotoolcmd, path);
    system(xdotoolcmd);
    system("xdotool getactivewindow windowmove 100 600");
  }
  printf(XF "\"%s\":\n", id);
  printf("\n");

  while (1) {
    char getquery[50];
    strcpy(getquery, "./GET ");
    strcat(getquery, id);
    system(getquery);
    int c;
    int d = 0;
    int val;
    int openbracket = '[';
    int closebracket = ']';
    int newline = '\n';

    //int val = atoi("[");
    doc = fopen(strtok(id,"\n"), "r");
    if(d > totalchars) {
      printf("\n");
    }
    if (doc) {
      while ((c = getc(doc)) != EOF) {
        d += 1;
        if(d > totalchars) {
          if (c == openbracket) {
            printf(GF "%c", c);
          }
          else if (c == closebracket) {
            printf("%c" XF, c);
          }
          else if (c == newline) {
            printf(XF "%c" XF, c);
          }
          else {
            printf("%c", c);
          }
        }
      }
      totalchars = d;
      fclose(doc);
      remove(id);
    }
  }
  return 0;
}
