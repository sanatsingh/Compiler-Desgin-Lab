%{
	
	int p = 0;
	int s = 0;
	
%}
chr [A-Za-z]
%%
{chr}+    {   if(strcmp(yytext, "printf")==0) 
                {fprintf(yyout, "%s", "scanf");p++;}
            else if(strcmp(yytext, "scanf")==0) 
                {fprintf(yyout, "%s", "printf");s++;}
            else
                fprintf(yyout, "%s", yytext);} 
. {fprintf(yyout, "%s", yytext);}
%%
int main()
{
	yyin = fopen("trial.c","r");
    yyout= fopen("output.c", "w");
    yylex();
    printf("%d %d",p,s);
	return 0;
}
int yywrap(){return 1;}