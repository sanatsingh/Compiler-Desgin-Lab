#include<stdio.h>
#include<string.h>
char inp[100];
int i=0,e=0;
void E();
void Eprime();
void T();
void Tprime();
void F();

void E(){
        T();
        Eprime();
}
void T(){
        F();
        Tprime();
}
void Eprime(){
        if(inp[i]=='+'){
            i++;
            T();
            Eprime();
        }
}
void Tprime(){
    if(inp[i]=='*'){
        i++;
        F();
        Tprime();
    }
}
void F(){
    if(inp[i]>='A' && inp[i]<='z')i++;
    else e=1;
}

int main(){
    printf("Enter Expression : ");
    int k=0;
    while((inp[k++]=getchar())!='\n');
    inp[k-1]='$';
    E();
    if(inp[i]=='$' && e==0)printf("\nParsing Successful\n");

}