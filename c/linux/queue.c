#include <stdio.h>

#define MAX 10

int enqueue();
int dequeue();
int display();
int isempty();
int isfull();

int size;
int i;
int n;
int queue[MAX];
static int front;
static int rear;

int main ( void )
{
	int choice;
	char ch;	
		
	front = rear = -1;
/*
	printf ("Enter number of elements to create Queue ");
	scanf ("%d", &size);
		
	printf ("enter elements into Queue ");
	for(i = 0; i < size; i++) {
		scanf ("%d", &queue[i]);
		rear = i;
	}

	display();
*/
	front++;
	do {

		printf ("\n	Menu \n1. enqueue\n2. dequeue\n3. dispaly queue contents\n4. check queue is empty\n5. check queue is full\n6. Exit\n");

		printf ("enter your choice ");
		scanf ("%d", &choice);

		switch(choice) {
		case 1 :
				enqueue();
				break;
		case 2 :
				dequeue();
				break;
		case 3 :
				display();
				break;
		case 4 :
				isempty();
				break;
		case 5 :
				isfull();
				break;
		case 6 :
				return 0;
		default:
				continue;
		
		}
	label :	printf ("\ndo you want to continue [y/n]");
			__fpurge(stdin);					//clearing stdin buf
			scanf ("%c", &ch); 

		if(ch == 'y') 
			continue;

		else if (ch == 'n') 
			return 0;
		
		else {
			printf ("Invalid option and try again\n");
			goto label;						//take input again
		}
	} while(1);

	return 0;
}	

int enqueue()
{
	if (isfull()) {
		printf ("queue is full and over flowed\n");
	} else {
		printf ("and you can proceed\n");
	label1: printf ("\nEnter no of elements to insert into queue ");
			scanf ("%d", &n);

		if (n + rear >= MAX) {
			printf ("\nyou have reached maximum size %d and you are at %d\n",MAX, rear+1); 
			goto label1;	
		}
		
		printf ("enter elements ");
		for ( i = 0; i < n ; i++) {  
			rear = rear + 1;
			scanf ("%d", &queue[rear]);			//reading elements into queue
		}
	}

	display();

	return 0;
}

int dequeue()
{	
	if (isempty()) {
		printf ("queue is empty and under flowed\n");
	} else {
		printf (" and you can proceed\nEnter no of elements to delete ");
		scanf ("%d", &n);

		for ( i = 0; i < n; i++) 
			front = front + 1;				//removing elements from queue
	}

	display();

	return 0;
}

int display()
{
	printf ("\nQueue contents ");

	for (i = front; i <= rear; i++) 
		printf ("%d ", queue[i]);
	
	printf ("\n");

	return 0;
}

int isempty()
{
	if ((front == -1) || (front >= MAX)) {
		printf ("queue is empty\n");
		return 1;
	} else 
		printf ("queue is not empty ");

	return 0;
}

int isfull()
{
	if ((front == 0) && (rear == (MAX - 1))) {
		printf ("queue is full\n");
		return 1;
	} else 
		printf ("queue is not full");

	return 0;
}
