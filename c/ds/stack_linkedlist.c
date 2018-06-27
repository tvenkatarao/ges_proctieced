#include<stdio.h>
#include<stdlib.h>
typedef struct node 
{

	int data;
	struct node *next;

}ST;

int empty(struct node *head)
{

	return head == NULL ?1:0;

}
ST* push(struct node *head,int data)
{
	ST* new = (ST*)malloc(sizeof(ST*));
	if(new == NULL)
	{
		exit(0);
	}
	new->data =data;
	new->next = head;
	head = new;
	return head;
}

struct node* pop(struct node *head,int *ndata)
{
	ST* new = head;
	*ndata = head->data;
	head = head->next;
	free(new);
	return head;
}
/*void init(struct node *p)
{

	head = null;

}*/
void display(struct node *head)
{
	ST* current;
	current = head;
	if(current != NULL)
	{
		printf("stack: ");
		do{
			printf("%d ",current->data);
			current = current->data;
		}while(current != NULL);
		printf("\n");
	}
	else
	{
		printf("the stack is empty\n");
	}

}


int main()
{
	struct node* head = NULL;
	int size, element;
	int counter = 0;

	printf("Enter the number of stack elements:");
	scanf("%d",&size);

	printf("--- Push elements into the linked stack ---\n");

//	init(head);

	while(counter < size)
	{

		printf("Enter a number to push into the stack:");
		scanf("%d",&element);
		head = push(head,element);
		display(head);
		counter++;
	}

	printf("--- Pop elements from the linked stack --- \n");
	while(empty(head) == 0)
	{
		head = pop(head,&element);
		printf("Pop %d from stack\n",element);
		display(head);
	}

	return 0;



}
