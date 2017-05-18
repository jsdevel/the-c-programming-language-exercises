#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INITIAL_SIZE 20
#define NON_SPACE_CHARACTERS 33

char *initialize();
// glibc defines getline on fedora linux.
int _getline(char **line, int size);
int trim(char **line);

int main()
{
  int len = 0;
  char *line = NULL;

  while (1) {
    len = _getline(&line, INITIAL_SIZE);

    if (len == EOF) {
      break;
    }

    // printf("len: %d\n", len);

    if (len > 0) {
      len = trim(&line);
      // printf("len after trim: %d\n", len);
    }

    if (len) {
      printf("%s\n", line);
    }

    if (line != NULL) {
      free(line);
      line = NULL;
    }
  }

  return 0;
}

char *initialize() {
  return malloc(INITIAL_SIZE);
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

  char * nline;

  if (*line == NULL) {
    nline = initialize();
  } else {
    nline = *line;
  }
  nline[0] = '\0';

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

int trim(char **line) {
  char *string = *line;
  int firstc = 0, lastc = 0, len = strlen(string);

  if (!len) {
    return 0;
  }

  for (int i = 0; i < len; ++i) {
    if (string[i] >= NON_SPACE_CHARACTERS) {
      firstc = i;
      break;
    }
  }

  for (int i = len; i > 0; --i) {
    if (string[i - 1] >= NON_SPACE_CHARACTERS) {
        lastc = i - 1;
        break;
    }
  }

  int j = 0;
  for (int i = firstc; i <= lastc; ++i) {
    string[j] = string[i];
    ++j;
  }
  string[j] = '\0';

  return j;
}
