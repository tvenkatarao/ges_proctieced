#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node *next;

};

void insert(struct Node** head_ref, int new_data)
{
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
	new_node->data =  new_data;
	new_node->next = (*head_ref);
	(*head_ref) = new_node;
}

void deleteNode(struct Node **head_ref , int position)
{
	if(*head_ref == NULL)
		return ;	
	struct Node* temp =*head_ref;

	if(position == 0)
	{
		*head_ref = temp->next;
		free(temp);
		return ;
	}
int i=0;
	for( i; (temp!=NULL) && (i<position-1);i++)
		temp = temp->next;

	if(temp == NULL || temp->next == NULL)
		return ;
	struct Node *next = temp->next->next;

	free(temp->next);
		temp->next = next;
}

void printlist(struct Node *node)
{
	while(node != NULL)
	{
		printf(" %d ",node->data);
		node = node->next;
	}

}

int main()
{
	struct Node * head = NULL;
	insert(&head,7);
	insert(&head,77);
	insert(&head,777);
	insert(&head,7777);
	insert(&head,77777);
	insert(&head,77777);
	insert(&head,7777);
	insert(&head,777);
	insert(&head,77);
	insert(&head,7);

	puts("created linked list: ");
	printlist(head);
int del;
printf("enter the delete link : ");
scanf("%d",&del);
	deleteNode(&head,del);
	puts("\nlinked list after deletion at position 4:");
	printlist(head);
	return 0;

}

