#include<stdio.h>
 
/*Function to find minimum of x and y*/
int min(int x, int y)
{
      return y ^ ((x ^ y) & -(x < y));
}
 
/*Function to find maximum of x and y*/
int max(int x, int y)
{
      return x ^ ((x ^ y) & -(x < y));
}

int main()
{
    int n1,n2;
    printf("enter the numbers n1 n2\n");
    scanf("%d %d",&n1,&n2);
printf("max = %d\n",max(n1,n2));
printf("min = %d\n",min(n1,n2));

return 0;
}
