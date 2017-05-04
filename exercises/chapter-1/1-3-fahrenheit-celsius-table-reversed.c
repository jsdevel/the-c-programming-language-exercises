#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP  20

int main()
{
  float fahr;

  printf("%10s\t%10s\n", "Fahrenheit", "Celsius");
  for (fahr = UPPER; fahr >= LOWER; fahr = fahr - STEP)
    printf("%10.0f\t%10.1f\n", fahr, (5.0/9.0)*(fahr-32));
}
