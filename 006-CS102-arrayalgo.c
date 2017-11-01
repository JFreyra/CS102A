#include <stdio.h>
#include <string.h>
#define AMT 256

int main(int argc, char *argv[])
        {
        FILE *nameoffile;
        char input[AMT];
        int length, col, i, field1,field2;
        col=0;
        if(argc != 2)
                {
                printf("Not enough arguments usage filestuff filename\n");
                return 1;
                }
        if((nameoffile=fopen(argv[1],"r"))==NULL)
                {
                printf("Can't open %s\n",argv[1]);
                return 1;
                }
        printf("Enter the lower bound of field numbers you want to look at.\n");
        scanf("%d", &field1);
        printf("Enter the upper bound of field mumbers you want to look at.\n");
        scanf("%d", &field2);
        while(fgets(input,sizeof(input),nameoffile) != NULL)
                //printf("this is a line\n");
                {
                length=strlen(input);
                for(i=0; i< length; i++)
                        {
                        if(input[i]==';')
                                {
                                printf(",");
                                continue;
                                }
                        if(col>=field1 && col<=field2)
                                {
                                printf("%c",input[i]);
                                }
                        if(input[i]=='\n')
                                {
                                printf("\n");
                                col=0;
                                }
                        }
                }
