#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0
#define BACKSPACE '\b'
#define TAB '\t'
#define CARRIAGE_RETURN '\r'
#define NEWLINE '\n'
#define SPACE " "
#define WHITE_SQUARE "\u25a1"
#define ASCII_LAST_CHAR 255

void printhhistogram(int histogram[]) {
  printf("Horizontal character count histogram\n\n");
  for (int i = 0; i < ASCII_LAST_CHAR; ++i) {
    int len = histogram[i];

    if (!len) {
      continue;
    }


    char escape = ' ';
    char character = i;

    if (i < ' ') {
      if (i == TAB) escape = '\\', character = 't';
      else if (i == CARRIAGE_RETURN) escape = '\\', character = 'r';
      else if (i == NEWLINE) escape = '\\', character = 'n';
      else if (i == BACKSPACE) escape = '\\', character = 'b';
      else character = ' ';
    }
    printf("%c%c| ", escape, character);

    for (int j = 0; j < len ; ++j) {
      printf(WHITE_SQUARE);
      printf(SPACE);
    }

    printf("\n");
  }
}

void printvhistogram(int histogram[]) {
  printf("Vertical character count histogram\n\n");

  int highestcc = 0;

  for (int i = 0; i < ASCII_LAST_CHAR; ++i) {
    if (histogram[i] > highestcc) {
      highestcc = histogram[i];
    }
  }

  for (int j = highestcc; j > 0; --j) {
    for (int i = 0; i < ASCII_LAST_CHAR; ++i) {
      if (!histogram[i]) {
        continue;
      }

      if (histogram[i] >= j) {
        printf(SPACE);
        printf(SPACE);
        printf(WHITE_SQUARE);
      } else {
        printf(SPACE);
        printf(SPACE);
        printf(SPACE);
      }
    }
    printf("\n");
  }

  for (int i = 0; i < ASCII_LAST_CHAR; ++i) {
    if (histogram[i]) {
      char escape = ' ';
      char character = i;

      if (i < ' ') {
        if (i == TAB) escape = '\\', character = 't';
        else if (i == CARRIAGE_RETURN) escape = '\\', character = 'r';
        else if (i == NEWLINE) escape = '\\', character = 'n';
        else if (i == BACKSPACE) escape = '\\', character = 'b';
        else character = ' ';
      }
      printf("%c%c%c", ' ', escape, character);
    }
  }

  printf("\n");
}

int main() {
  char c;
  int histogram[ASCII_LAST_CHAR];

  for (int i = 0; i < ASCII_LAST_CHAR; ++i) histogram[i] = 0;

  while ((c = getchar()) != EOF) {
    ++histogram[(int)c];
  }

  printf("\n");
  printhhistogram(histogram);
  printf("\n");
  printvhistogram(histogram);
}
