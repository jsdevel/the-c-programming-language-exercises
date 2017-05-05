#include <stdio.h>

int main()
{
  int c, nl, ns, nt;

  nl = ns = nt = 0;

  while ((c = getchar()) != EOF) {
    if (c == '\n') ++nl;
    if (c == '\t') ++nt;
    if (c == ' ') ++ns;
  }

  printf("spaces    tabs    newlines\n");
  printf("%6d    %4d    %8d\n", ns, nt, nl);
}
