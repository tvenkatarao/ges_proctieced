// palindrom linked list


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertAtEnd();
void display();
void delete_pos();
struct Node
{
	char str[10];
	struct Node *next;
}*head = NULL;

void main()
{
	int choice,choice1,loc1,loc2;
   char str[10];
	while(1){
mainMenu: printf("\n\n********* MENU ************");
	printf("\n1. Insert\n2. Display\n3.exit\n4)delete\nEnter your choice: ");
	  scanf("%d",&choice);
	  switch(choice)
	  {
						case 1: insertAtEnd();
								break;
		            case 2: 	display();
				               break;
                  case 4:delete_pos();
                         break;
		  case 3: 	exit(0);
		  default: printf("\nWrong input!!! Try again!!\n\n");
	  }
goto mainMenu;
	}
}


void insertAtEnd()
{
 
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
   
  
   printf("Enter the string to be insert: ");
				scanf("%s",newNode->str);

	newNode->next = NULL;
	if(head == NULL)
		head = newNode;
	else
	{
		struct Node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	printf("\nOne node inserted!!!\n");
}

void delete_pos()
{
    int pos = 2,count=1;
    while(head != NULL)
    {

        count++;
        if(count == pos)
        {
            head->next = head->next->next;

        }
        head =head->next;

    }

    display();

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
		while(temp!= NULL)
		{
			printf("%s --->",temp->str);
			temp = temp->next;
		}
		printf(" NULL\n");
	}

}
