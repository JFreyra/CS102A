#include <stdio.h>
#include <math.h>
#include <limits.h>
#include <stdlib.h>
#include <string.h>

unsigned long factorial(int elem){
  printf("\n###DEBUG: Entered###\n\n");
  if(elem == 1 || elem == 0){ return 1; }
  else{ return elem*factorial(elem-1); }
}

int main(int argc, char *argv[]){
  float rad = atof(argv[2]);

  // Input testing
  if(argc != 3){
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);
    printf("Not enough arguments\n");
    return 1;
  }
  if(strcmp(argv[1],"sin") && strcmp(argv[1],"cos")){
    printf("%s\n",argv[1]);
    printf("First argument must be \"sin\" or \"cos\"\n");
    return 1;
  }
  if(strcmp(argv[2],"0") && !rad){
    printf("Second argument must be a float\n");
    return 1;
  }

  // Variable declarations/instantiations
  float ans = 0;
  float num = 0;
  unsigned long fact = 0;
  int isSin = !strcmp(argv[1],"sin");
  int isCos = !strcmp(argv[1],"cos");
  // printf("%s\n",argv[1]);
  // printf("%d\n",!strcmp(argv[1],"sin"));
  // printf("%f\n",((2.0/3)*INT_MAX));

  // Taylor Series for sin and cos
  if(isSin || isCos){
    for(int i = 0;
        i < 10                  &&
        num < ((2.0/3)*INT_MAX) &&
        fact < ((2.0/3)*INT_MAX);
        i++){
      if(isSin){
        num = pow(rad,2*i+1);
        fact = factorial(2*i+1);
      }
      if(isCos){
        num = pow(rad,2*i);
        fact = factorial(2*i);
      }
      ans += pow(-1,i)*(num/fact);
      // printf("leading: %.4f\n",pow(-1,i));
      // printf("num: %.4f\n",num);
      // printf("denom: %lu\n",fact);
      // printf("index: %d\n",i);
      // printf("ans: %f\n\n",ans);
    }
  }
  else{
    printf("Something went wrong\n");
    return 1;
  }
  printf("%s of %.4f is: %.4f\n",argv[1],rad,ans);
  /*
  printf("strcmp: %d\n",strcmp(argv[2],"0"));
  printf("rad: %f\n",rad);
  */
  return 0;
}
