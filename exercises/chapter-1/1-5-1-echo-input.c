#include <stdio.h>

int main()
{
  int c;

  printf("EOF: %i\n", EOF);
  while ((c = getchar())) {
    printf("c: %i\n", c);
    if (c == EOF) {
      break;
    }
    if (c == '\n') {
      continue;
    }
    putchar(c)
    && putchar('\n');
  }
}
