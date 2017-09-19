#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct Tuple{
  float root1;
  float root2;
} Tuple;

Tuple makePair(float a, float b){
  Tuple r = {a, b};
  return r;
}

Tuple calcQuad(int a, int b, float det){
  float root1 = (-b-sqrt(det))/(2.0*a);
  float root2 = (-b+sqrt(det))/(2.0*a);
  return makePair(root1,root2);
}

float determinant(int a, int b, int c){
  printf("Inside det: %d %d %d\n\n",a,b,c);
  float det = b*b-(4*a*c);
  return det;
}

int main(void){
   int a, b, c;
   int root1, root2;
   float det;

   printf("Input integer values for a, b, and c:\n");
   /* scanf will only successfully take positive/negative integer values
      floats and other longer numbers cause memory issues */
   scanf("%d %d %d", &a, &b, &c);
   printf("Inputs: a = %d, b = %d, c = %d\n\n",a,b,c);

   det = determinant(a,b,c);
   printf("Determinant: %0.3f\n\n",det);

   if(det >= 0){
      Tuple ans = calcQuad(a,b,det);
      printf("Quadratic Roots:\n");
      printf("Root 1: %0.3f\n",ans.root1);
      printf("Root 2: %0.3f\n",ans.root2);
   }
   else{
     printf("Quadratic has an imaginary answer\n\n");
   }

   return 0;
 }
