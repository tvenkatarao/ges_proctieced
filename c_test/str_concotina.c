#include<stdio.h>
#include<string.h>
//int (*funp)(char *,...);

void *str_fun(char *p,char *q,int len)
{
    int i=len,j;
//while(*p++);
ptintf("%d\n",i);
//printf("after concatination :%s\n",*p);
    for(j=0;*(q+j)!=0;j++)
//    for(;q!='\0';q++)
    {
//        p[i++]=*q;
       *(p+i)=*(q+j);
i++;
    }
    p[i]='\0';

printf("after concatination :%s\n",*p);
    return 0;
}

int main()
{

    char s1[20],s2[20];
    printf("enter the string one:");
    scanf("%[^\n]",s1);

    printf("\nenter the string TWO:");
    scanf("%s",s2);

int len=strlen(s1);
printf("%d\n",len);
str_fun(s1,s2,len);
    //funp=str_fun;
   // funp(s1,s2, len);
printf("after concatination :%s\n",s1);

    return 0;

}
