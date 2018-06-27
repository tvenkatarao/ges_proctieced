#include<stdio.h>
#include<stdlib.h>


typedef struct st
{
	struct st *prev;
	int data;
	struct st *next;
}ST; 

void insert_node(ST **hptr)
{

	ST *new = (ST *) malloc(sizeof(ST));
	printf("enter the data :\n");
	scanf("%d",&new->data);

	if(*hptr == NULL)
	{
		new->prev = NULL;
		new->next  = NULL;

	}
	else
	{
		new->prev = NULL;
		new->next = *hptr;
		(*hptr)->prev = new;
	}
	*hptr = new;


	/*
	   else
	   {
	   (*hptr)->prev = new;
	   new -> next = (*hptr);
	   (*hptr) = new;

	   }*/
}

void delete(ST **ptr, int n)
{
	ST *temp;
	if(*ptr == NULL)
	{
		printf("linked list is empty:\n");
		return ;
	}
	if(n == (*ptr)->data)
	{
		temp = *ptr;
		*ptr = (*ptr)->next;
		if(*ptr)
			(*ptr)->prev = NULL;

		free(temp);
		temp =NULL;
		return;
	}
	else {
		temp =(*ptr)->next;
		while((temp) && (n != temp->data))
			temp = temp->next;

		if(temp == NULL)
		{
			printf("number is not found ..\n");
			return;
		}

		temp->prev->next = temp->next;
		if(temp->next != NULL)
			temp->next->prev = temp->prev;

		free(temp);
		temp = NULL;
		return;
	}
}





void print(ST **ptr)
{

while(*ptr)
{
printf("%d\n",(*ptr)->data);
(*ptr) = (*ptr)->next;
}

}
static int x=0; 
int main()
{
	ST *hptr = NULL;
int num;
	char ch;
	do{

		insert_node(&hptr);
x++;
	printf("enter the 'ch' value :\n");
	scanf(" %c",&ch);

	}while((ch=='y') || (ch=='Y'));
print(&hptr);

printf("enter the delete node number:");
scanf("%d",&num);

delete(&hptr,num);
print(&hptr);
return 0; 
}
