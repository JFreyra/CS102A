/* Include Statements */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* Defines Tuple
   Used for return of helper function calcQuad */
typedef struct Tuple{
  float root1;
  float root2;
} Tuple;

/* Creates and returns instance of Tuple (a,b) */
Tuple makePair(float a, float b){
  Tuple r = {a, b};
  return r;
}

/* Calculates roots of quadratic using a, b, and det */
Tuple calcQuad(int a, int b, float det){
  float root1 = (-b-sqrt(det))/(2.0*a);
  float root2 = (-b+sqrt(det))/(2.0*a);
  return makePair(root1,root2);
}

/* Calculates determinant of a, b, and c of equation: ax^2+bx+c */
float determinant(int a, int b, int c){
  printf("Inside det: %d %d %d\n\n",a,b,c);
  float det = b*b-(4*a*c);
  return det;
}

int main(void){

   /* Define variables */
   int a, b, c;         // a,b,c of ax^2+bx+c = 0
   int root1, root2;    // root1 and root2 of calculated roots
   float det;           // determinant of a,b,c

   /* Basic input requests
      note: cannot take data types other than int; float, double, long break code */
   printf("Input integer values for a, b, and c:\n");
   /* scanf will only successfully take positive/negative integer values
      floats and other longer numbers cause memory issues */
   scanf("%d %d %d", &a, &b, &c);
   printf("Inputs: a = %d, b = %d, c = %d\n\n",a,b,c);
   if(a == 0){
     printf("a cannot be 0\n");
     return 0;
   }

   /* Assigns determinant of given values to det */
   det = determinant(a,b,c);
   printf("Determinant: %0.3f\n\n",det);

   /* Catch if det < 0 quadratic does not have a real answer */
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
