# include <stdio.h> 
# include <string.h> 
   
int main( ) 
{ 
    FILE *fp;
    char c;

    fp = fopen("print_op.c","r");

    while((c=fgetc(fp))!=EOF){
        printf("%c\n",c);
    }            
     
    
    return 0;         
}