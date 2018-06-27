#include<stdio.h>
int main()
{

int a[20]={0,1,1,1,1,1,1,1,1,1,1,1,1,1,1};
int *p=malloc(sizeof(a));
printf("%d",sizeof(p));
p = realloc(p,sizeof(a)*20);

printf("%d",sizeof(p));
 

}
