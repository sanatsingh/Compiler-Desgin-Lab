%{
    int c=0,f=0;
%}
digit [0-9]
sign [+-]
%%
[\n] {}
{sign}*{digit}+ c++;
{sign}*{digit}*"."{digit}+ f++;
. {}
%%
int main(){
    yyin = fopen("trial.c","r");
    yylex();
    printf("Integers = %d\n",c);
    printf("Floating numbers = %d\n",f);
    return 0;
}
int yywrap(){return 1;}