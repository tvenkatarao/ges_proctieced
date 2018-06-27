#include<stdio.h>
struct st 
{
int num;
char ch;
long double dl;

}t;
struct st2
{
//static int n;
char c;
long double ld;
}t2;

int main()
{

printf("size of st2:%u\n",sizeof(struct st2));
printf("size of st :%u\n",sizeof(struct st));
printf("size of st2:%u\n",&t2);
printf("size of st :%u\n",&t);
return 0;
}
