%{
	
	int ch = 0;
	int words = 0;
	int lines = 0;
	
%}
chr [A-Za-z]
%%
[\n] {lines++;}
{chr}*  {words++;}
. {ch++;}
%%
int main()
{
	yyin = fopen("trial.c","r");
	yylex();
	printf("\nNo. of chars %d\n",ch);
	printf("\nNo. of words %d\n",words);
	printf("\nNo. of lines %d\n",lines);
	
	return 0;
}
int yywrap(){return 1;}