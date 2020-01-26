#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){

    FILE *fp1, *fp2;
    fp1=fopen("f7.c","r");
    fp2=fopen("out.txt","w");

    char ch=' ', word[50];
    while(ch!=EOF){
        fscanf(fp1,"%s",word);
        if(!strcmp(word,"const")){
            while(ch!=';'){
                fputc(ch,fp2);
                ch=fgetc(fp1);
            }
        }
        ch=fgetc(fp1);
    }
    return 0;
}