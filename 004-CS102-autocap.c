#include <stdio.h>
#include <stdlib.h>

int main(void){

  char text[256];
  char capText[256];
  printf("What do you want capitalized?\n\t");
  //scanf("%s",text);
  scanf("%[^\n]s", text);
  printf("Input: %s\n", text);

  for(int i = 0; text[i] != 0 ; i++){
    // printf("%d\n", text[i]);
    if(text[i] >= 97 && text[i] <= 122){
      if(i == 0){ // first letter of first word
        // printf("This should only print once\n");
        capText[0] = text[0]-32;
      }
      else if(text[i-1] == 32){ // right after a space
        capText[i] = text[i]-32;
      }
      else { capText[i] = text[i]; }
    }
    else { capText[i] = text[i]; }
  }
  printf("Output: %s\n", capText);

  return 0;
}
