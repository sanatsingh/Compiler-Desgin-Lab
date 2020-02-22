// By Shubham Kumar, 1705072 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char s[10];
    printf("\nenter string:. ");
    scanf("%s",s);
  	int a = 0;
  	int count = 0;
    int index = 0;
    char ch = s[0];
    printf("%s",s);
    
    // Integer
    // for(int i=0;i<10;i++)
    // {
    // 	if(s[i]=='+' || s[i] == '-')
    // 	{
    // 		while(s[++i]>='0' && s[++i]<='9' )
    // 		{
    // 			a =1;
    // 		}
    // 	}
    // 	else if (s[i]>='0' && s[i]<='9')
    // 	{
    // 		a = 1;
    // 	}
    // }
    // if(s[0]>='a' && s[0] <= 'z')
    // 	{
    // 		a =0;
    		
    // 	}
    // if(a==1 )
    // {
    // 	printf("\nSatisfy\n");
    // }
    // else
    // {
    // 	printf("\nDo not satisfy\n");	
    // }
    // a =0;


    
    // identifier
    for(int i=0;i<10;i++)
    {
    	if(s[i]>='a' && s[i] <= 'z')
    	{
    		while(s[i]>='a' && s[i]<='z' )
    		{
    			a =1;
    			while(s[i]>='0' && s[i]<='9' )
    			{
    				a = 1;
    				i++;
    			}
    			i++;
    		}
    	}

    }
   
    if(a==1 )
    {
    	printf("\nSatisfy\n");
    }
    else
    {
    	printf("\nDo not satisfy\n");	
    }

    return 0;
}
