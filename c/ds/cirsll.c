#include <stdio.h>
#include <stdlib.h>

void io();
int deleteatend();

struct node 
{
	int info;
	struct node *link;
};

int i;
int j;
int n;

struct node *temp1;
struct node *head = NULL; 
struct node *temp;

int inputpos()
{ 
	printf ("enter position ");
	scanf ("%d", &i);
	return i;
}

void display()
{
	temp = head;
	printf ("\n");
	for (i = 0; temp->link != head; i++) {
		printf ("%d	", temp->info);
		temp = temp->link;
	}
	printf ("%d\n", temp->info);
}

int count()
{
	temp1 = head;
	for (j = 1; temp1->link != head; j++) {
		temp1 = temp1->link;
	}
	return j;
}

void createnode()
{
	temp = (struct node *) malloc (sizeof(struct node));  
	printf ("enter data  ");
	scanf ("%d", &temp->info);

}

void linking()
{

	temp->link = temp1->link;	
	temp1->link = temp;
	
}

int main(void)
{

	int create()
	{
		int n;
	
		printf ("enter no of nodes to create ");
		scanf ("%d", &n);
	
	    createnode();
		
		head = temp;
		temp1 = temp;

		for (i = 1; i < n; i++) {
			temp = (struct node *) malloc (sizeof(struct node));  
			temp1->link = temp;
			scanf ("%d", &temp->info);
			temp1 = temp1->link;
		}

		temp->link = head;
		display();
		return 0;
	}

	create();
	io();
	
	return 0;
}

int insertatbeg()
{
	createnode();

	i =	count();
	temp->link = head;
	head = temp;
	temp1->link = head;
	return 0;
}
int insertatend()
{
	i =	count();
	createnode();

	temp1 = head;
	for (;(i - 1) != 0; i--) {
		temp1 = temp1->link;
	}

	temp1->link = temp;
	temp->link = head;
	return 0;
}
int insertatpos(int i)
{

	if (i > count()) {
		printf ("please enter position within list\n");
		return 0;
	}

	if (i == 1) {
		insertatbeg();
		return 0;
	}

	createnode();
	temp1 = head;

	for (; (i-2) != 0; i--) {
		temp1 = temp1->link;
	}

	linking();
	return 0;
}
int insertbeforepos()
{
	inputpos();
	insertatpos(i - 1);
	return 0;
}
int insertafterpos()
{
	inputpos();
	insertatpos(i + 1);

	return 0;
}

int insertbeforenum()
{
	int c = count();

	printf ("Enter data in sll to insert data before it : ");
	scanf ("%d", &j);

	if (head->info == j) {

			insertatbeg();

		return 0; 
	}

	createnode();

	temp1 = head;

	for (; (j != (temp1->link->info)) && ((c - 2) != 0); c--) {
		temp1 = temp1->link;
	}

	linking();

	return 0;
}	
int insertafternum()
{
	printf ("Enter data in sll to insert data after it : ");
	scanf ("%d", &i);

	createnode();

	temp1 = head;

	for (; i != (temp1->info); ) {
		temp1 = temp1->link;
	}

	linking();

	return 0;
}	
int insertatmiddle()
{

	insertatpos((count())/2);
	
	return 0;
}

int insertatpenultimate()
{
	insertatpos(count() - 1);
	return 0;
}
int deleteatbeg()
{
	temp = head;
	
	temp = temp->link; 
	
	head = temp;

	i = count();

	temp1->link = head;

	free(temp1);
	deleteatend();
	return 0;
}
int deleteatend()
{
	i = count();
	
	temp1 = head;

	for (;(i - 2) != 0; i--) {
		temp1 = temp1->link;
	}
	temp1->link = head;
	
	return 0;
}
int deleteatpos(int i)
{

	temp1 = head;

	for (; (j-2) != 0; j--) {
		temp1 = temp1->link;
	}

	if (temp1 == head) {
		deleteatbeg();
		return 0;
	}

	if (temp1->link->link == head) {
		temp1->link = head;
		return 0;
	}

	temp1->link = temp1->link->link;
	return 0;
}
int deletebeforepos()
{
	inputpos();
	deleteatpos(i -1);
	return 0;
}
int deleteafterpos()
{
	inputpos();
	deleteatpos(i + 1);

	return 0;
}
int deletebeforenum()
{
	printf ("Enter data in sll to delete data before it : ");
	scanf ("%d", &i);

	temp1 = head;

	if (temp1->info == i) {
		deleteatend();
		return 0;
	}
	for (; i != (temp1->link->link->info); ) {
		temp1 = temp1->link;
	}

	temp1 = temp1->link;
	temp1->link = temp1->link->link;
	
	return 0;
}	
int deleteafternum()
{
	printf ("Enter data in sll to delete data after it : ");
	scanf ("%d", &i);

	temp1 = head;
	while (i != (temp1->info)){
		temp1 = temp1->link;
	}
	if ( temp1 -> link == head) {
		deleteatbeg();
		return 0;
	}

	temp1->link = temp1->link->link;
	
	return 0;
}	
int deleteatmiddle()
{
	deleteatpos(count() / 2);  

	return 0;
}

int deleteatpenultimate()
{
	deleteatpos(count() - 2);  
	
	return 0;
}
