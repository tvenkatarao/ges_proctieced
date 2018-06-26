#include<stdio.h>
main()
{

int m[3][3]={1,2,3,4,5,6,7,8,9};
int a[3][3]={0,0,},i,j;

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%d",m[i][j]);
}
printf("\n");
}

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
a[i][j]=m[2-j][i];

}
}

for(i=0;i<3;i++)
{
for(j=0;j<3;j++)
{
printf("%d",a[i][j]);
}
printf("\n");
}

}
