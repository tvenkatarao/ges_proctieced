#include<stdio.h>
#include<stdlib.h>

void selection(int a[],int size)
{
	int i,j,min,temp;
	for(i=0;i<size-1;i++)
	{
		min = i;
		for(j=i+1;j<size;j++)
		{
			if(a[j]<a[min])
			{
				min = j;
			}
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
for(i=0;i<5;i++)
printf("%d\t",a[i]);
}

int main()
{
int a[5],i=0;//={3,7,4,9,5};
printf("data:");
for(i=0;i<5;i++)
scanf("%d",&a[i]);
selection(a,5);
return 0;
}
