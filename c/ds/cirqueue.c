#include <stdio.h>
#define MAX 5

int enqueue();
int dequeue();
int display();
int isempty();
int isfull();

int i;
int n;
int queue[MAX];
static int front;
static int rear;
int len;

int sizeque(int n)
{
	if (front > rear) {

		len = (MAX - front + rear + 1);

	} else {

		len = rear - front + 1;
	}
	
	if ( (len + n) > MAX ) {

		printf ("you have reached maximum limit ");
		return 0;
	}

	printf ("size of circular queue %d\n", len);
	return len;
}

int main()
{
	int choice;
	char ch;	
		
	front = rear = -1;

	label1 :printf ("Enter number of elements to create circular Queue ");
			scanf ("%d", &n);
			if (n <= MAX) {	
				printf ("enter elements into circular queue ");
				for(i = 0; i < n; i++) {
					scanf ("%d", &queue[i]);
					rear = i;
				}
			front++;
			display();
			} else {
				printf ("MAximum limit has reached try again and maximum size of cirqueue is %d\n", MAX);
				goto label1;
			}

	printf ("\ncircular queue has created and maximum of %d elements and now it occupied %d elements \n	Menu \n",MAX, n);
	printf ("1. enqueue\n2. dequeue\n3. dispaly queue contents\n");
	printf ("4. check queue is empty\n5. check queue is full\n6. current size of circular queue\n");
		
	do {
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
				sizeque(n);
				break;
		}
	label :	printf ("\ndo you want to continue [y/n] ");
			getchar();
			scanf ("%c", &ch); 

		if(ch == 'y') 
			continue;

		else if (ch == 'n') 
			return 0;
		
		else {
			printf ("Invalid option and try again\n");
			goto label;
		}
	} while(1);
	return 0;
}	
int enqueue()
{
	int l;

	if(isfull()) {
		printf ("queue is full and over flowed\n");
	}
	else {

		printf (" and you can proceed\nEnter no of elements to insert into queue ");
		scanf ("%d", &n);
	
		l = sizeque(n);

		if (l == 0 )
			return 0;

		printf ("enter elements ");
			for (i = 0; i < n; i++ ) {
				if (rear == MAX -1 )
					rear = 0;
				else
					rear = rear + 1;
			
				scanf ("%d", &queue[rear]);
			}
	}
	display();
	return 0;
}
int dequeue()
{
	
	if(isempty()) {
		printf ("queue is empty and under flowed\n");
	}
	else {
		printf (" and you can proceed\nEnter no of elements to delete ");
		scanf ("%d", &n);

		for ( i = 0; i < n; i++) {  
			front = front + 1;	
			if (front == MAX -1 )
				front = 0;
		}
	}
	display();
return 0;
}
int display()
{
	int size;

	printf ("\ncircular queue contents ");
	
	if (front < rear ) {
		for (i = front; i <= rear; i++) {
			printf ("%d ", queue[i]);
		}
	}
	else {
		size = (MAX - front + rear + 1);
		for (i = front; size != 0 ; size--, i++) {
			printf ("%d ", queue[i]);
			if (i == MAX - 1) {
				i = 0;
			}
		}
	}
	printf ("\n");
return 0;
}
int isempty()
{
	if ((front - rear) == 0) {
		printf ("queue is empty\n");
		return 1;
	}
	else {
		printf ("queue is not empty ");
	}
return 0;
}
int isfull()
{
	if (((front - rear) == 1)) {// || ((front + rear + 1) == MAX)) {
		printf ("queue is full\n");
		return 1;
	}
	else {
		printf ("queue is not full");
	}
return 0;
}
