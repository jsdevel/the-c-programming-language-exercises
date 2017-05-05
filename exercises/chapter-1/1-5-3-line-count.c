#include <stdio.h>

/*
 * counts newline characters
int main()
{
  int c, nl;

  nl = 0;

  while ((c = getchar()) != EOF)
    if (c == '\n') ++nl;

  printf("%1d\n", nl);
}
*/

/*
 * counts newline, tabs, and spaces.
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
 */


/*
 * converts consecutive spaces to a single space
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
 */

int main()
{
  int c;
  while ((c = getchar()) != EOF) {
    if (c == '\b') putchar('\\') && putchar('b');
    else if (c == '\t') putchar('\\') && putchar('t');
    else if (c == '\\') putchar('\\') && putchar('\\');
    else putchar(c);
  }
}
