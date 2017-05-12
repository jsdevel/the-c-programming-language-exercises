#include <stdio.h>

float ftoc(float fahr) {
  return (5.0/9.0) * (fahr-32.0);
}

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;

  fahr = lower;
  printf("%10s\t%10s\n", "Fahrenheit", "Celsius");
  while (fahr <= upper) {
    celsius = ftoc(fahr);;
    printf("%10.0f\t%10.1f\n", fahr, celsius);
    fahr = fahr + step;
  }
}
