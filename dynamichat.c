/* tee.c
   Tolulope Oshinowo

   This program allows the user to enter input a string to be
   atored into the file specified by the '-a' append tag.
*/
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <time.h>
#include <assert.h>

#define KF   "\x1B[30m"
#define RF   "\x1B[31m"
#define GF   "\x1B[32m"
#define YF   "\x1B[33m"
#define BF   "\x1B[34m"
#define MF   "\x1B[35m"
#define CF   "\x1B[36m"
#define WF   "\x1B[37m"
#define XF   "\x1B[39m"

char *datetime;
char cmd[1024];

int main(int argc, char *argv[])
{
  system("xdotool getactivewindow windowmove 100 0");
  system("echo -en \"\033]0;DynamiChat\a\"");
  system("resize -s 22 120");
  system("clear");
  system("clear");
  char hostname[1024];
  gethostname(hostname, 1024);

  char *filename = "";
  char *num = malloc(sizeof(char) * 1024);
  char *opt = malloc(sizeof(char) * 1024);
  char input;
  char *str;
  char *message;
  char s[1024];
  char command[1024];
  FILE * doc;
  int totalchars;
  char chatroomcmd[1024] = "gnome-terminal -- /bin/sh -c './keyboard -a ";
  char xdotoolcmd[1024] = "xdotool windowactivate ";
  FILE *fp;
  char path[1024];

  printf(GF "ENTER CHATROOM ID:\n" BF);
  fgets(num, 1024, stdin);

  strcat(chatroomcmd, strtok(num,"\n"));
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
  printf(XF "\"%s\":\n", num);
  printf("\n");

  while (1) {
    int c;
    int d = 0;
    int val;
    int openbracket = '[';
    int closebracket = ']';
    int newline = '\n';

    //int val = atoi("[");
    doc = fopen(strtok(num,"\n"), "r");
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
    }
  }
  return 0;
}
