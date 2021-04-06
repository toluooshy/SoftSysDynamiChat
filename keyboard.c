/* tee.c
   Tolulope Oshinowo

   This program allows the user to enter input a string to be
   atored into the file specified by the '-a' append tag.
*/
#include "common.h"

void getdatetime(){
  time_t t = time(NULL);
  struct tm *tm = gmtime(&t);
  datetime = strtok(asctime(tm),"\n");
}

int main(int argc, char *argv[])
{
  system("echo -en \"\033]0;DynamiChat Keyboard\a\"");
  system("resize -s 10 120");
  system("clear");
  system("clear");
  char hostname[1024];
  gethostname(hostname, 1024);
  getdatetime();

  char *filename = "";
  char *id;
  char *usr;
  char input;
  char *str;
  char *message;
  char s[1024];
  FILE * doc;
  int totalchars;
  int i =1;

  while ((input = getopt(argc, argv, "i:u:")) != EOF) {
    switch (input) {
    case 'i':
      id = optarg;
      break;
    case 'u':
      usr = optarg;
      break;
    default:
      fprintf(stderr, "Unknown option: '%s'\n", optarg);
      return 1;
    }
  }
  while(1) {
    getdatetime();
    system("clear");
    system("clear");
    printf("\n");
    printf(GF "                                 ╭──────────────────────────────────────────────────────╮\n");
    printf(GF "                                 │                     :" WF "DynamiChat" GF ":                     │\n");
    printf(GF "                                 ╰──────────────────────────────────────────────────────╯\n");
    printf("\n");

    printf(WF "┌──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┐\n");
    printf(WF "│                                                                                                                      │\n");
    printf(WF "│                                                                                                                      │\n");
    printf(WF "│                                                                                                                      │\n");
    printf(WF "└──────────────────────────────────────────────────────────────────────────────────────────────────────────────────────┘\n");
    printf(BF "                                                                                                            SEND (enter)");
    gotoxy(2, 6);
    fgets(message, 1024, stdin);
    char postquery[50];

    if (strcmp(strtok(message,"\n"), "") != 0) {
      doc = fopen(id, "a+");
      fprintf(doc, "%s", usr);
      fprintf(doc, "[");
      fprintf(doc, "%s", datetime);
      fprintf(doc, "]:\n");
      fprintf(doc, "%s", message);
      fprintf(doc, "\n");
      fprintf(doc, "\n");
      fclose(doc);

      strcpy(postquery, "./POST ");
      strcat(postquery, id);
      strcat(postquery, " \"");
      strcat(postquery, usr);
      strcat(postquery, "\" \"");
      strcat(postquery, datetime);
      strcat(postquery, "\" \"");
      strcat(postquery, message);
      strcat(postquery, "\"");
      system(postquery);
    }
  }
  return 0;
}
