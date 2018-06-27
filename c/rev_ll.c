#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
	int data;
	struct node *next;

} ST;
static void reverse(struct node ** head_ref)
{

	struct node *prv  = NULL;
	struct node *current = *head_ref;
	struct node *next;

	while(current != NULL)
	{
		next = current->next;
		current->next = prv;
		prv = current ;
		current = next;
	}
	*head_ref = prv;
}

void push(struct node ** head_ref , int  new_data)
{
	struct node * new_node  = (struct node*) malloc(sizeof(struct node));


	new_node->data =new_data;
	new_node->next =(*head_ref);
	(*head_ref) = new_node;
}

void printlist(struct node *head)
{

	struct node *temp = head;
	while(temp != NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
}


int main()
{

	struct node *head = NULL;
	push (&head, 20);
	push (&head, 120);
	push (&head, 220);
	push (&head, 201);
	push (&head, 202);

	printf("gevin ll\n");
	printlist(head);
	reverse(&head);
	printf("revers ll \n");

	printlist(head);
	getchar();

}

