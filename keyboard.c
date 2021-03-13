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
  char *num;
  char input;
  char *str;
  char *message;
  char s[1024];
  FILE * doc;
  int totalchars;
  int i =1;

  while ((input = getopt(argc, argv, "a:")) != EOF) {
    switch (input) {
    case 'a':
      num = optarg;
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
    printf(GF "[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[[     DynamiChat     ]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]]" XF);
    printf("\n");

    printf(BF "SEND:\n" XF);
    fgets(message, 1024, stdin);

    if (strcmp(strtok(message,"\n"), "") != 0) {
      doc = fopen(num, "a+");
      fprintf(doc, "%s", hostname);
      fprintf(doc, "[");
      fprintf(doc, "%s", datetime);
      fprintf(doc, "]:\n");
      fprintf(doc, "%s", message);
      fprintf(doc, "\n");
      fprintf(doc, "\n");
      fclose(doc);
    }
  }
  return 0;
}
