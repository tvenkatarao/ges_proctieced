#include<stdio.h>
int main()
{
	int a[5];
	int i,j,key;
	printf("enter the array elements...\n");
	for(i=0;i<5;i++)
	scanf("%d",&a[i]);

	for(i=0;i<5;i++)
printf("%d\t",a[i]);


	for(i=1;i<=5;i++)
	{
		key = a[i];
		j = i-1;
		while(j>=0 && key < a[j])
		{
			a[j+1] = a[j];
			j--;
		}
		a[j+1] = key;
	}
	for(i=0;i<5;i++)
printf("%d\n",a[i]);
return 0;
}
