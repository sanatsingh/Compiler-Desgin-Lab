#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    FILE *fp;
    
    char file[10];
    printf("\nEnter the file to be read\n");
    scanf("%s",file);
    
    char data[50];
    char ch;
    int read=0;
    int n;

    
    //open existing file in r attribute
    fp = fopen(file,"r");
    
    //if the file does not exist
    if(fp == NULL)
    {
        printf("\nFile failed to open\n");        
    }
    else
    {
        printf("\nFile opened\n");
        while((ch=fgetc(fp))!= EOF)
        {
            if((int)ch==34)
            {
            	printf("%c",ch);
            	while(1)
            	{
            		ch = fgetc(fp);
            		if((int)ch==34)
            		{
            			printf("%c",ch);
            			break;
            		}
            		printf("%c",ch);
            	}
            }
            if((int)ch==39)
            {
            printf("%c",ch);
            	while(1)
            	{
            		ch = fgetc(fp);
            		if((int)ch==39)
            		{
            			printf("%c",ch);
            			break;
            		}
            		printf("%c",ch);
            	}
            }
        }
        fclose(fp);
        //printf("\nData read\n");
        //printf("\nFile closed\n");        
    }
    return 0;
}
