#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	int data;
	struct st *next;
}ST ;
void add_sort(ST **);
void print(ST *);
int c;

int main()
{
	char ch;
	ST *hptr = NULL;
	do{
		c++;
		add_sort(&hptr);
		printf("do u want another node Y/N \n");
		scanf("%c ",&ch);
	}while((ch =='y') || (ch=='Y'));
	print(hptr);

}

void add_sort(ST **ptr)
{
	ST *new = (ST *)malloc(sizeof(ST));
	printf("enter the data\n");
	scanf("%d",&new->data);
	if((*ptr == 0)||(new->data < (*ptr)->data))
	{
		new->next = *ptr;
		*ptr = new;
	} 
	else
	{
		ST * last = *ptr;
		while((last->next) && (last->next->data) < new->data)
			last = last->next;

		new->next = last->next;
		last->next = new;
	}
}

void print(ST *ptr)
{
	while(ptr)
	{
		printf("%d\n",ptr->data);
		ptr = ptr->next;
	}

}



