# include <stdio.h> 
# include <string.h> 
   
int main( ) 
{ 
    FILE *fp;
    char c;
    int i;
	scanf("%d",&i);
    fp = fopen("line_no.c","r");
    while((c=fgetc(fp))!=EOF){
        
        if(c=='p')
       		{
       			c = fgetc(fp);
       			if(c=='r')
       			{
       				c = fgetc(fp);
       				if(c=='i')
       				{
       					c = fgetc(fp);
       					if(c=='n')
       					{
       						c = fgetc(fp);
       						if(c=='t')
			   				{
			   					c = fgetc(fp);
			   					if(c=='f')
				   				{
				   					printf("scanf");
				   				}
				   				else
				   				{
				   					printf("print%c",c);
				   				}
			   				}
			   				else
			   				{
			   					printf("prin%c",c);
			   				}
       					}
		   				else
		   				{
		   					printf("pri%c",c);
		   				}
       				}
       				else
       				{
       					printf("pr%c",c);
       				}
       			}
       			else
       			{
       				printf("p%c",c);
       			}
       	}

		else if(c=='s')
       	{
       		c = fgetc(fp);
       		if(c=='c')
       		{
       			c = fgetc(fp);
       			if(c=='a')
       			{
       				c = fgetc(fp);
       				if(c=='n')
       				{
						c = fgetc(fp);
						if(c=='f')
			   			{
							c=fgetc(fp);
							printf("printf%c",c);
						}
						else
						{
							printf("scan%c",c);
			 			}
					}	
			   		else
			   		{
						printf("sca%c",c);
			   		}
       			}
		   		else
		   		{
		   			printf("sc%c",c);
		   		}
			}
       		else
       		{
    			printf("s%c",c);
   			}
       	}
       	else
    	{
			printf("%c",c);
   		}
	}

    return 0;         
} 