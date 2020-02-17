#include<stdio.h>
#include<string.h>
char inp[30];
int i=0,e=0;
void S();
void A();

void S(){
    if(inp[i]=='c'){
        i++;
        A();
        if(inp[i]=='d')i++;
    }
    else e=1;
}

void A(){
    if(inp[i]=='a'){
        i++;
        if(inp[i]=='b')i++;
    }
    else e=1;
}

int main(){
    printf("Enter Expression : ");
    int k=0;
    while((inp[k++]=getchar())!='\n');
    inp[k-1]='$';
    S();
    if(inp[i]=='$'&& e==0)printf("\nParsing Successful\n");

}