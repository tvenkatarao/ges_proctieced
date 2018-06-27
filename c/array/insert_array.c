#include<stdio.h>
#include<stdlib.h>

int main()
{
	char *p;
	int *a,num,i,pos;
	int new_num;

	printf("enter the num value...\n");
	scanf("%d",&num);

	a = (int *) malloc (num *sizeof(int));

	if(a == NULL)
	{
		printf("Error! memory not allocated.");
		exit(0);
	}

	printf("enter the array elements : ");
	for(i=0;i<num;i++)
	{
		scanf("%d",a+i);
	}

	printf("entered elements:\n");
	for(i=0;i<num;i++)
		printf("%d ",a[i]);

	printf("\nenter the insert position...\n");
	scanf("%d",&pos);

	a = realloc(a,num+1);

	printf("enter the insert value...\n");
	scanf("%d",&new_num);
	for(i=num;i>=pos-1;i--) 
		a[i+1] = a[i];

	a[pos-1] = new_num;

	printf("after adding ...\n");
	for(i=0;i<=num;i++)
		printf("%d\t",a[i]);



}

