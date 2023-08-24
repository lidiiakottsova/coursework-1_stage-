#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <errno.h>

FILE * fout ;

char * find_group(const char * str) {
	if (str[0] != '[')
		return NULL; 
  char * group = 0;
  char * s = strchr(str, ']');
  int n = s - str - 1;
  group = strdup(str + 1);
  group[n] = '\0';
  return group;
} 

void function_2 (const char * inistr, const char * group) {
  if (inistr[0] == '[') 
	  return;
  char * str = strdup(inistr);

  fprintf(fout, "%s.", group);

  char * s = strchr(str,'=');
  s[0] = '\0';
  s += 1;
  fprintf(fout,"%s: %s", str, s);
  free(str);
}

int main (int argc, char * argv[])
{
  if (argc < 3) {
    fprintf(stderr,"USAGE: %s FILEFROM FILETO\nConvert FILEFROM in ini format to cfg dotted format\n", argv[0]);
    return 1;
  }
  FILE * fin = fopen(argv[1], "r");
  ssize_t read;
  size_t len = 0;
  if (fin == NULL) {
    perror(argv[1]);
    exit(errno);
  }
  fout = fopen(argv[2], "w");
  if (fout == NULL) {
    perror(argv[2]);
    fclose(fin);
    exit(errno);
  }
  char * frst_str = NULL;
  char * group = 0 ;
  while ((read = getline(&frst_str , &len , fin)) != -1) {
	  char * gr = find_group(frst_str);
	  if (gr != NULL) {
      free(group);
		  group = gr;
	  }
    function_2(frst_str, group);
  }
  if (frst_str)
    free(frst_str);
  free(group);  
  fclose(fin);
  fclose(fout);
  return 0;
}
