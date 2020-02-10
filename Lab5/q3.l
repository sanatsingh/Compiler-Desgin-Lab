%{
	
	int ch = 0;
	int words = 0;
	int lines = 0;
	
%}
chr [A-Za-z]
%%
{chr}+    {   if(strcmp(yytext, "printf")==0) 
                fprintf(yyout, "%s", "scanf");
            else if(strcmp(yytext, "scanf")==0) 
                fprintf(yyout, "%s", "printf");
            else
                fprintf(yyout, "%s", yytext);} 
. {fprintf(yyout, "%s", yytext);}
%%
int main()
{
	yyin = fopen("trial.c","r");
    yyout= fopen("output.c", "w");
    yylex();
	return 0;
}
int yywrap(){return 1;}