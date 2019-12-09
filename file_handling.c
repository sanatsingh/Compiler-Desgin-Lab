# include <stdio.h> 
# include <string.h> 
   
int main( ) 
{ 
    FILE *fp; 

    char buff[100];
    int i=0;
    while((buff[i++]=getchar())!='\n');
    buff[i]='\0';

    fp = fopen("test.txt", "w") ; 
    if ( fp == NULL ) 
    { 
        printf( "GfgTest.c file failed to open." ) ; 
    } 
    else
    { 
          
        printf("The file is now opened.\n") ; 

        if ( strlen (  buff  ) > 0 ) 
        { 

            fputs(buff, fp) ;    
            fputs("\n", fp) ; 
        } 

        fclose(fp) ; 
          
        printf("Successfully written in file test.txt\n"); 
        printf("The file is now closed.") ; 
    }

    fp = fopen("test.txt","r");
    printf("\n\nFile contents :-\n");
    
    while(fgets(buff,100,fp)!=NULL){
        printf("%s",buff);
    }  
    return 0;         
} 