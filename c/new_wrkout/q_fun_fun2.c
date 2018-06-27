#include<stdio.h>
int fun1(int ,int);
int fun2(int*);
int fun3(int* ,int*);

int main()
{
int max=12,min=6;
max = fun1((fun2(&max),(fun3(&min,&max))));
printf("%d %d\n",max,min);

}
int fun1(int p,int q)
{
return p*q;

}
int fun2(int *q)
{
return q;

}
int fun3(int *p,int *q)
{
return ++q;

}
