#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){

  // printf("Format input as: <sin/cos> <angle in radians>\n");

  char oper[4];
  strcpy(oper,argv[1]); // only need to know if it is sin or cos
  float rad = atof(argv[2]);

  if(argc != 3){
    printf("%s\n",argv[1]);
    printf("%s\n",argv[2]);
    printf("Not enough arguments\n");
    return 1;
  }
  if(strcmp(argv[1],"sin") && strcmp(argv[1],"cos")){
    printf("%s\n",oper);
    printf("First argument must be \"sin\" or \"cos\"\n");
    return 1;
  }
  if(strcmp(argv[2],"0") && !rad){
    printf("Second argument must be a float\n");
    return 1;
  }

}
