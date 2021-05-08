#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

void exit (int status);
void perror (const char * msg);

FILE * fout ;

void function_1 (char * frst_str,char * scnd_str ) {
    if (frst_str[0] == '[') {
      for (int i = 0; i < 100; i++) scnd_str[i] = 0;
      for (int i = 1; i < strlen(frst_str); i++) {
        if (frst_str[i] !=']') {
          scnd_str[i - 1] = frst_str[i];
        }
        else break;
      }
    }
}

void function_2 (char * frst_str,char * scnd_str) {
  if (frst_str[0] != '[') {
    fprintf(fout,"%s.", scnd_str);
    int j = 0;
    while (frst_str[j] != '=') {
      j++;
    }
    for (int i = 0; i < j; i++) {
      fprintf(fout,"%c", frst_str[i]);
    }
    fprintf(fout,": ");
    for (int i = j + 1; i < strlen(frst_str); i++) {
      fprintf(fout,"%c", frst_str[i]);
    }
  }
}

int main (int argc, char * argv[])
{
  argc = 3;
  FILE * fin = fopen(argv[1],"r");
  fout = fopen(argv[2],"w");
  if (fin == NULL) {
    perror(argv[1]);
    exit(errno);
  }
  char frst_str[100];
  char scnd_str[100] = {};
  while (fgets(frst_str, 100, fin)) {
    function_1(frst_str,scnd_str);
    function_2(frst_str,scnd_str);
  }
  fclose(fin);
  fclose(fout);
  return 0;
}
