#include<stdio.h>
struct st
{

int a;
int b;

}y[4]={1,12,3,5,6,7,8,9};

int main()
{
struct st *x= 4;
int i;
for(i=0;i<4;i++)
{
x->a =x->b;
}

}
