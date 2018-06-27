#include <stdio.h>
#define MAX 20

int push();
int pop();
int display();
int isempty();
int isfull();

int size;
int stack[MAX];
int i;
int n;
static int top = -1;

int main (void)
{
	int choice;
	char ch;	
		
	do {
		printf ("\n	Menu \n");
		printf ("1. Push\n");
		printf ("2. Pop\n");
		printf ("3. dispaly stack contents\n");
		printf ("4. check stack is empty\n");
		printf ("5. check stack is full\n");
		printf ("6. Exit\n");
		
			printf ("enter your choice ");
			scanf ("%d", &choice);

			switch(choice) {
			case 1 :
					push();
					break;
			case 2 :
					pop();
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
			__fpurge(stdin);						//clearing stdin buf		
			scanf ("%c", &ch); 

			if(ch == 'y') 
				continue;
			else if (ch == 'n') {
				return 0;
			}
			else {
				printf ("Invalid option and try again");
				goto label;						//take input again
			}
	}while(1);

	return 0;
}	
int push()
{

	if (isfull()){
			printf ("stack is full \n");
	} else {
		printf (" and you can proceed \n\nenter number of elements you want to push into stack ");
		scanf ("%d", &n);
	
		printf ("enter elements to push into stack ");
		for(i = 0; i < n; i++) {
			scanf ("%d", &stack[++top]);					//storing into stack
		}
		display();
	}
	return 0;
}
int pop()
{
	if(isempty()){
		printf ("stack is empty\n");
	}
	else {
		printf (" and you can proceed \n\nenter number of elements you want to pop from stack ");
		scanf ("%d", &n);
	
		for(i = 0; i < n; i++) {
			if (stack[i] != '\0')
				top--;							//removing elements
		}
	display();
	}
	return 0;
}
int display()
{
	printf ("Stack contents ");

	for(i = 0; i <= top; i++) 
		printf ("%d ", stack[i]);
	
	printf ("\n");
	return 0;
}
int isempty()
{
	if (top <= -1) {
		printf ("stack is empty\n");
		return 1;
	}
	else {
		printf ("stack is not empty");
	}
	return 0;
}
int isfull()
{
	if (top == MAX - 1) {
		printf ("stack is full\n");
		return 1;
	}
	else {
		printf ("stack is not full");
		return 0;
	}
}
