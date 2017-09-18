#include <stdio.h>
#include <stdlib.h>
/* this is a comment */
/* print fahrenheit celsius table
         for fahr = 0, 20, ... , 300
         print celsius = x, y, ... , z */
int ver1(void){
  int fahr;                   // variable
  float celsius;              // variable
  int lower, upper, step;     // constants
  lower = 0;
  upper = 300;
  step = 20;
  fahr = lower;
  printf("fahr:\tcelsius\n");
  while(fahr <= upper){
    celsius = (5.0*(fahr-32))/9.0;
    // string formatting '%d' represents integer
    printf("%d\t%0.2f\n", fahr, celsius);
    fahr += step;
  }
  return 0;
}

int ver2(void){
  int fahr;
  for(fahr = 0; fahr <= 300; fahr += 20){
    printf("%d\t%0.2f\n", fahr, (5.0*(fahr-32))/9.0);
  }
  return 0;
}

int main(void){
  ver2();
  return 0;
}
