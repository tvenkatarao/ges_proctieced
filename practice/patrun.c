#include<stdio.h>

//int k;
//static int k;

main()
{
int i,j;
for (i=0;i<5;i++)
{
for (j=0;j<5;j++)
{
if(i<=2)
{
if (j<=i || i>=4-j )
printf(" *");
else
printf("  ");
}

else 
{
//if (i<=j || i<=4-j)
if (j>=i || i<=4-j)
printf(" *");
else
printf("  ");

}
}
printf("\n");
}
printf("\n");
}

