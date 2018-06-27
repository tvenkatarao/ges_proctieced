#include<stdio.h>
//#include<conio.h>
#include<stdlib.h>

void insertAtBeginning(int);
void display();
void removeSpecific(int);

struct Node
{
	int data;
	struct Node *next;
}*head = NULL;

void main()
{
	int choice,value,choice1,loc1,loc2;
	while(1){
mainMenu: printf("\n\n********* MENU ************");
	  printf("\n1. Insert\n2. Display\n3. Delete\n4. Exit\nEnter your choice: ");
	  scanf("%d",&choice);
	  switch(choice)
	  {
		  case 1: 	printf("Enter the value to be insert: ");
				scanf("%d",&value);
				while(1){
					printf("Where you want to insert: \n1. At Beginning\n2. At End\n3. Between\nEnter your choice: ");
					scanf("%d",&choice1);
					switch(choice1)
					{
						case 1: 	insertAtBeginning(value);
								break;
						default: 	printf("\nWrong Input!! Try again!!!\n\n");
								goto mainMenu;
					}
					goto subMenuEnd;
				}
subMenuEnd:
				break;
		  case 2: 	display();
				break;
		  case 3: 	printf("How do you want to Delete: \n1. From Beginning\n2. From End\n3. Spesific\nEnter your choice: ");
				scanf("%d",&choice1);
				switch(choice1)
				{
					case 3:      printf("Enter the value which you wanto delete: ");
						     scanf("%d",&loc2);
						     removeSpecific(loc2);
						     break;
					default: 	printf("\nWrong Input!! Try again!!!\n\n");
							goto mainMenu;
				}
				break;
		  case 4: 	exit(0);
		  default: printf("\nWrong input!!! Try again!!\n\n");
	  }
	}
}

void insertAtBeginning(int value)
{
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = value;
	if(head == NULL)
	{
		newNode->next = NULL;
		head = newNode;
	}
	else
	{
		newNode->next = head;
		head = newNode;
	}
	printf("\nOne node inserted!!!\n");
}

void removeSpecific(int delValue)
{
	struct Node *temp1 = head, *temp2;
	while(temp1->data != delValue)
	{
		if(temp1 -> next == NULL){
			printf("\nGiven node not found in the list!!!");break;
			//			goto functionEnd;
		}
		temp2 = temp1;
		temp1 = temp1 -> next;
	}
	temp2 -> next = temp1 -> next;
	free(temp1);
	printf("\nOne node deleted!!!\n\n");
	//functionEnd:
}
void display()
{
	if(head == NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		struct Node *temp = head;
		printf("\n\nList elements are - \n");
		while(temp->next != NULL)
		{
			printf("%d --->",temp->data);
			temp = temp->next;
		}
		printf("%d --->NULL",temp->data);
	}
}
