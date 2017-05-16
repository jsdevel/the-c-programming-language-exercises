#include <stdlib.h>
#include <stdio.h>

int main(void) {
  char *string = malloc(2);
  char **pstring = &string;
  string[3] = 'c';
  *(string + 4) = 'd';

  printf("%c\n", string[3]);
  printf("%c\n", (*pstring)[3]);
  printf("%c\n", (*pstring)[4]);
  printf("%c\n", string[4]);
}
