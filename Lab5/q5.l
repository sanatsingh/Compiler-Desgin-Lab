%{
	int i=0,k=0,c=0,o=0;
	FILE *identifier, *key, *constants, *operator;
%}
%%
[+-/*%^=] o++;
"int"|"struct"|"break"|"long"|"enum"|"double"|"void"|"include"|"return" k++;
"const" c++;
([A-Za-z_])([A-Za-z0-9_])* i++;
%%
int main()
{
	yyin = fopen("trial2.c","r");
	identifier = fopen("identifier.c","w");
	key = fopen("key.c","w");
	constants = fopen("constants.c","w");
	operator = fopen("operator.c","w");
	yylex();
	fprintf(identifier,"%d",i);
	fprintf(key,"%d",k);
	fprintf(constants,"%d",c);
	fprintf(operator,"%d",o);
	return 0;
}
int yywrap()
{
	return 1;
}
