#include<stdio.h>
#include<stdlib.h>
struct stud
{
	int roll;
};

struct st
{

	struct stud *dptr ;

} *ST[5];


int addfun()
{
	int i=0;	
	struct stud *ptr[5];
	printf("Enter the Student Details : ");
	for(i=0;i<5;i++)
	{
		printf("\nEnter the Roll Number : ");
		ptr[i]roll = i+2;
		printf("\nthe Roll Number : ");
		ST[i]->dptr = ptr[i];
		printf("\nthe Roll Number : ");
//		free(ptr);
	}
}

void printfun(void)
{
	int i=0;
	for(i=0;i<5;i++)
	{
		printf("\nthe Roll Number : ");
		printf("%d",ST[i]->dptr->roll);
	}




}


int main()
{
	printf("\nStudent Details are : ");
	addfun();
	printfun();

	return(0);
}
