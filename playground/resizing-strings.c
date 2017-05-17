#include <stdlib.h>
#include <stdio.h>
#include <strings.h>

int main(void) {
  char *string = "abcdefghijklmnopqrstuvwxyz";
  ++string;
  printf("%s\n", string);
  --string;
  printf("%s\n", string);
}
