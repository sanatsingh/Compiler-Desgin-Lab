%{
    int c=0,f=0;
%}
digit [0-9]

%%
{digit}+ c++;
{digit}*"."{digit}+ f++;
%%
int main(){
    yylex();
    printf("Integers = %d\n",c);
    printf("Floating numbers = %d\n",f);
    return 0;
}
int yywrap(){return 1;}