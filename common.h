#include <stdio.h>
#include <stdlib.h>
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
