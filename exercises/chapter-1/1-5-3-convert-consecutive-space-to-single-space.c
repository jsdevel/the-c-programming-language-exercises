#include <stdio.h>

int main()
{
  int c, hasSpace;

  hasSpace = 0;

  while ((c = getchar()) != EOF) {
    if (c == ' ') {
      hasSpace = 1;
    } else {
      if (hasSpace) {
        hasSpace = 0;
        putchar(' ');
      }
      putchar(c);
    }
  }
}
