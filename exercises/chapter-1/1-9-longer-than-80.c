#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 20
#define MINIMUM_LINE_LENGTH 80

char *initialize();
// glibc defines getline on fedora linux.
int _getline(char **line, int size);

int main()
{
  int len = 0;
  char *line = NULL;

  while (1) {
    len = _getline(&line, INITIAL_SIZE);

    if (len == EOF) {
      break;
    }

    if (len > MINIMUM_LINE_LENGTH) {
      printf("%s", line);
    }
  }

  return 0;
}

char *initialize() {
  return (char*)malloc(INITIAL_SIZE);
}

int handlememincrease(int proposedsize, int actualsize, char **line)
{
  if (proposedsize > actualsize) {
    actualsize *= 2;
    char* newline = realloc(*line, actualsize);
    if (newline == NULL) {
      fprintf(stderr, "Out of Memory\n");
      exit(1);
    }
    *line = newline;
  }
  return actualsize;
}

int _getline(char **line, int size)
{
  int c, i;

  char * nline = initialize();

  c = getchar();

  if (c == EOF) {
    return EOF;
  }

  for (i=0; c != EOF && c!='\n'; ++i) {
    size = handlememincrease(i, size, &nline);
    nline[i] = c;
    c = getchar();
  }

  if (c == '\n') {
    nline[i] = c;
    ++i;
  }
  handlememincrease(i, size, &nline);
  nline[i] = '\0';

  *line = nline;
  return i;
}
