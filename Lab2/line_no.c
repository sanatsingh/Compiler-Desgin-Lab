# include <stdio.h> 
# include <string.h> 
   
int main( ) 
{ 
    FILE *fp;
    char c;
    int i=1;
    fp = fopen("line_no.c","r");
    printf("%d ",i);
    while((c=fgetc(fp))!=EOF){
        printf("%c",c);
        if(c=='\n'){
            printf("%d ",++i);
        }  
    } 
    
    return 0;         
} 