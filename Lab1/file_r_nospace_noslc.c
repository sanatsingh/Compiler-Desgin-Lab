# include <stdio.h> 
# include <string.h> 
   
int main( ) 
{ 
    FILE *fp;
    char c;
    fp = fopen("test.txt","r");
    char d;
    while((c=fgetc(fp))!=EOF){
        if((int)c==34){
            printf("%c",c);
            while(1){
                c=fgetc(fp);
                if((int)c==34){
                    printf("%c",c);
                    break;
                }
                printf("%c",c);  
            }
        }
        else if((int)c==39){
            printf("%c",c);
            while(1){
                c=fgetc(fp);
                if((int)c==39){
                    printf("%c",c);
                    break;
                }
                printf("%c",c);  
            }
        }   
        else if(c=='/'){
            if((c=fgetc(fp))=='/'){
                while(c=fgetc(fp)!='\n');
                printf("%c",c);
            }
            else if(c=='*'){
                while((c=fgetc(fp))!='*' || (d=fgetc(fp))!='/');
            }
            else{
                printf("/%c",c);
            }
        }
        else if(c!=' ')printf("%c",c);
           
    } 
    
    return 0;         
} 