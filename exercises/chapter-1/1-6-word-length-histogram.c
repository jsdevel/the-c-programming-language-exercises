#include <stdio.h>
#include <stdlib.h>

#define IN 1
#define OUT 0
#define SPACE " "
#define WHITE_SQUARE "\u25a1"

void printhhistogram(int maxwordlength, int histogram[]) {
  printf("Horizontal word count histogram\n\n");
  for (int i = 1; i < maxwordlength; ++i) {
    int len = histogram[i];

    if (!len) {
      continue;
    }

    printf("%2d| ", i);

    for (int j = 0; j < len ; ++j) {
      printf(WHITE_SQUARE);
      printf(SPACE);
    }

    printf("\n");
  }
}

void printvhistogram(int maxwordlength, int histogram[]) {
  printf("Vertical word count histogram\n\n");

  int highestwc = 0;

  for (int i = 1; i < maxwordlength; ++i) {
    if (histogram[i] > highestwc) {
      highestwc = histogram[i];
    }
  }

  for (int j = highestwc; j > 0; --j) {
    for (int i = 1; i < maxwordlength; ++i) {
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

  for (int i = 1; i < maxwordlength; ++i) {
    if (histogram[i]) {
      printf("%3d", i);
    }
  }

  printf("\n");
}

int main() {
  char c;
  int maxwordlength = 50, inword = OUT, wl = 0, maxwordlengthexceeded = 0;
  int histogram[maxwordlength];

  for (int i = 0; i < maxwordlength; ++i) histogram[i] = 0;

  while (1) {
    c = getchar();
    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      inword = IN;
      ++wl;

      if (wl >= maxwordlength) {
        maxwordlengthexceeded = 1;
        break;
      }
    } else if (c != EOF) {
      if (inword) {
        ++histogram[wl];
        wl = 0;
        inword = OUT;
      }
    }

    if (c == EOF) {
      if (inword) {
        printf("\n");
        ++histogram[wl];
        wl = 0;
        inword = OUT;
      }
      break;
    }
  }

  if (maxwordlengthexceeded) {
    fprintf(stderr, "Max character count (%d) exceeded in word!  Press [Enter] to proceed.\n", wl);
    return 1;
  }

  printf("\n");
  printhhistogram(maxwordlength, histogram);
  printf("\n");
  printvhistogram(maxwordlength, histogram);
}
