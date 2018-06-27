#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* fun(char *x)
{ 
char *y=x,c;
  int count=0;
 while(*y)
   {
    ++y;
    ++count;
    }
   y=x;
c=(char)count;

printf("%c\n",c);  

*++y=c;

//*++y=(char )4;  
*++y='\0';
printf("%s\n",x);
return x;
}



int main(void)
{
char* x=malloc(sizeof(char *));
//char *x;
strcpy(x,"AAAA");
fun(x);
return 0;
}
