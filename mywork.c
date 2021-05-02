#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
  FILE * fin  = fopen("my.ini", "r");   
  FILE * fout = fopen("my.cfg", "w"); 
  char str_1[100];
  char str_2[100];
  char str_3[100];
  char str_4[100];
  char str_5[100];
  char str_6[100];
  char k[1]={};
  fgets (str_1, 100, fin);
  fgets (str_2, 100, fin);
  fgets (str_3, 100, fin);
  fgets (str_4, 100, fin);
  fgets (str_5, 100, fin);
  fgets (str_6, 100, fin);
  memmove (str_1, str_1+1, strlen (str_1+1) + 1);
  memmove (&str_1[strlen(str_1)-2], k, 1);
  fprintf (fout,"%s.", str_1);
  int j = 0;
  while (str_2[j] != '=') {
    j++;
  }
  for (int i = 0; i < j; i++) {
    fprintf(fout,"%c", str_2[i]);
  }
  fprintf(fout,":");
  for (int i = j + 1; i < strlen(str_2); i++) {
    fprintf(fout,"%c", str_2[i]);
  }
  fprintf (fout,"%s.", str_1);
  int s = 0;
  while (str_3[s] != '=') {
    s++;
  }
  for (int i = 0; i < s; i++) {
    fprintf(fout,"%c", str_3[i]);
  }
  fprintf(fout,":");
  for (int i = s + 1; i < strlen(str_3); i++) {
    fprintf(fout,"%c", str_3[i]);
  }

  memmove (str_4, str_4+1, strlen (str_4+1) + 1);
  memmove (&str_4[strlen(str_4)-2], k, 1);
  fprintf (fout,"%s.", str_4);
  int p = 0;
  while (str_5[p] != '=') {
    p++;
  }
  for (int i = 0; i < p; i++) {
    fprintf(fout,"%c", str_5[i]);
  }
  fprintf(fout,":");
  for (int i = p + 1; i < strlen(str_5); i++) {
    fprintf(fout,"%c", str_5[i]);
  }

  fprintf (fout,"%s.", str_4);
  int m = 0;
  while (str_6[m] != '=') {
    m++;
  }
  for (int i = 0; i < m; i++) {
    fprintf(fout,"%c", str_6[i]);
  }
  fprintf(fout,":");
  for (int i = m + 1; i < strlen(str_6); i++) {
    fprintf(fout,"%c", str_6[i]);
  }
  fclose(fin);               
  fclose(fout);
  return 0;
}
    


