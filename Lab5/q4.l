%{
	int lines = 1;
	
%}
chr [A-Za-z]
%%
[\n] {  lines++;
        fprintf(yyout, "%s%d%s", "\n",lines," ");
     }
. {fprintf(yyout, "%s", yytext);}
%%
int main()
{
	yyin = fopen("trial.c","r");
    yyout= fopen("output2.c", "w");
    fprintf(yyout, "%s","1 ");
    yylex();
	return 0;
}
int yywrap(){return 1;}