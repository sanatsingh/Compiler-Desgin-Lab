#include<stdio.h>
#include<string.h>
char inp[30];
int i=0,e=0;
void S();
void A();
void B();
void C();
void D();

void S(){
    if(inp[i]=='a'){
        i++;
        A();
        B();
        C();
        D();
    }
    else e=1;
}
void A(){
    if(inp[i]=='a'){
        i++;
        A();
    }
    else if(inp[i]=='b') i++;
    else e=1;
}
void B(){
    if(inp[i]=='b'){
        i++;
        B();
    }
    else if(inp[i]=='c') i++;
    else e=1;
}
void C(){
    if(inp[i]=='c'){
        i++;
        C();
    }
    else if(inp[i]=='d') i++;
    else e=1;
}
void D(){
    if(inp[i]=='d'){
        i++;
        D();
    }
    else if(inp[i]=='e') i++;
    else e=1;
}

int main(){
    printf("Enter Expression : ");
    int k=0;
    while((inp[k++]=getchar())!='\n');
    inp[k-1]='$';
    S();
    if(inp[i]=='$' && e==0)printf("\nParsing Successful\n");

}