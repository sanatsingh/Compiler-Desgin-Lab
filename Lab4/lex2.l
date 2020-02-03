%{
    int c=0, v=0, n=0;
%}
%%
[aeiouAEIOU] { v++; }
[A-Za-z] { c++; }
[0-9] { n++; }
%%
int main(){
    yylex();
    printf("Consonants = %d\n",c);
    printf("Vowels = %d\n",v);
    printf("Digits = %d\n",n);
    printf("Total = %d\n",c+v+n);
    return 0;
}
int yywrap(){return 1;}