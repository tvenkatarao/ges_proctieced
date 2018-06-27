#include<stdio.h>
#include<stdlib.h>
/*struct data
{
int val;
//char ch;
}*dp=NULL;
*/

struct Node
{
int val;
	struct Node *next;
}*front = NULL,*rear = NULL;
void insert(int );
void delete();
void display();

void main()
{
	int choice, value;
	printf("\n:: Queue Implementation using Linked List ::\n");
	while(1){
		printf("\n****** MENU ******\n");
		printf("1. Insert\n2. Delete\n3. Display\n4. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: printf("Enter the value to be insert: ");
				scanf("%d", &value);
				insert(value);
				break;
			case 2: delete(); break;
			case 3: display(); break;
			case 4: exit(0);
			default: printf("\nWrong selection!!! Please try again!!!\n");
		}
	}
}
void insert(int data)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->val = data;
	newNode -> next = NULL;
	if(rear == NULL)
		front = rear = newNode;
	else{
		rear -> next = newNode;
		rear = newNode;
	}
	printf("\nInsertion is Success!!!\n");
}
void delete()
{
	if(front == NULL)
   {
       front = rear= NULL;
		printf("\nQueue is Empty!!!\n");
   }
	else{
		struct Node *temp = front;
		front = front -> next;
		printf("\nDeleted element: %d\n", temp->val);
      temp->next = NULL; //V.V.Imp step
		free(temp);
	}
}
void display()
{
	if(front == NULL)
		printf("\nQueue is Empty!!!\n");
	else{
		struct Node *temp = front;
		while(temp->next != NULL){
			printf("%d--->",temp->val);
			temp = temp -> next;
		}
		printf("%d--->NULL\n",temp->val);
	}
} 
