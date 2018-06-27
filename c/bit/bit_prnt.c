#include<stdio.h>

void f (int n)
{ 
int i;
  if (n <=1)  {
   printf ("%d", n);
  }
  else {
   f (n/2);
   printf ("%d", n%2);
  }
}
int main()
{
int num=173;
f(173);

printf("\n");
return 0;


}
