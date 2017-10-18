#include <stdio.h>
#include <string.h>
#define AMT 256
int main(int argc, char *argv[]){
	FILE *nameoffile;
	char input[AMT];
	int length;
	if(argc != 2){
		printf("Not enough arguments usage filestuff filename\n");
		return 1;
	}
	if((nameoffile=fopen(argv[1],"r"))==NULL){
		printf("Can't open %s\n",argv[1]);
		return 1;
	}
	while(fgets(input,sizeof(input),nameoffile) != NULL){
		length=strlen(input);
		for(int i = 0; i < length-1; i++){
			if(input[i] == 32 && input[++i] == 9){
				printf(";");
			}
			else{
				printf("%c",input[i]);
			}
		}
		printf("\n");
	}
}
