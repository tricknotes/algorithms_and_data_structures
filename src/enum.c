#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *arg[]) {
  enum signal { blue, yellow, red };
  enum signal a;

  a = red; // ok
  a = 4; // Compiled successfully! Oops...

  printf("signal: %d\n", a); // => 4

  return 0;
};
