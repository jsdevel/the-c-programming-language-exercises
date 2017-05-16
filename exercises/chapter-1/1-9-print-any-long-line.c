#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 20

char *initialize();
// glibc defines getline on fedora linux.
int _getline(char **line, int size);

int main()
{
  int len = 0, max = 0;
  char *line = NULL;
  char *longestline = NULL;

  while (1) {
    len = _getline(&line, INITIAL_SIZE);

    if (len == EOF) {
      break;
    }

    if (len > max) {
      if (longestline != NULL) {
        free(longestline);
      }
      longestline = line;
      max = len;
    }
  }

  if (max > 0) {
    printf("%s", longestline);
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
