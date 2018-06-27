#include<stdio.h>
#define f(x,y) x#y
#define g(x) #x
#define h(x) g(y)

int main()
{

printf("%s",h(f(2,3)));
printf("%s",g(f(2,3)));

}
