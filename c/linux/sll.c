#include <stdio.h>
#include <stdlib.h>

void io();
extern int inputpos();

struct node 
{
	int info;
	struct node *link;
};

int i;
int n;

struct node *temp1;
struct node *head = NULL; 
struct node *temp;

void display()
{
	temp = head;
	printf ("\n");
	while(temp->link != NULL) {
		printf ("%d	", temp->info);
		temp = temp->link;
	}
	printf ("%d\n", temp->info);
}

int inputpos()
{ 
	printf ("enter position ");
	scanf ("%d", &i);
	return i;
}

int inputval()
{ 
	printf ("Enter info within sll to compare ");
	scanf ("%d", &i);

	return i;
}

int count()
{
	temp1 = head;
	for (n = 1; temp1->link != NULL; n++) {
		temp1 = temp1->link;
	}
	return n;
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

		temp->link = NULL;
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
	temp->link = head;
	head = temp;

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
	temp->link = NULL;
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

	temp1 = head;

	createnode();
	for (; (i-2) != 0; i--) {
		temp1 = temp1->link;
	}

	linking();

	return 0;
}

int insertbeforepos()
{
	inputpos();

	if (i == 1) {
		insertatbeg();
		return 0;
	}
	
	insertatpos(i - 1);
	
	return 0;
}

int insertafterpos()
{
	inputpos();

	if (i == count()) {
		insertatend();
		return 0;
	}

	insertatpos(i + 1);

	return 0;
}

int insertbeforenum()
{
	int c = count();

	inputval();

	if (head->info == i) {
		insertatbeg();
		return 0; 
	}

	createnode();
	temp1 = head;

	for (; (i != (temp1->link->info)) && ((c - 2) != 0); c--) {
		temp1 = temp1->link;
	}

	linking();

	return 0;
}
	
int insertafternum()
{
	inputval();
	
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

	insertatpos((count() / 2) + 1);

	return 0;
}

int insertatpenultimate()
{
	insertatpos(count());

	return 0;
}

int deleteatbeg()
{
	temp1 = head;
	
	temp1 = temp1->link; 
	
	head = temp1;

	return 0;
}

int deleteatend()
{
	i = count();
	
	temp1 = head;

	for (;(i - 2) != 0; i--) {
		temp1 = temp1->link;
	}
	temp1->link = NULL;
	
	return 0;
}

int deleteatpos(int i)
{
	if ((i >= count()) && (i == 0)) {
		printf ("please enter position within list\n");
		return 0;
	}
	printf ("i = %d\n", i);
	temp1 = head;
	for (; (i-2) > 0; i--) {
		temp1 = temp1->link;
	}

	if (i == 2) {
		temp1->link = temp1->link->link;
		return 0;
	} else if (temp1 == head) {
		deleteatbeg();
		return 0;
	} else if (temp1->link->link == NULL) {
		temp1->link = NULL;
		return 0;
	}
	
	temp1->link = temp1->link->link;

	return 0;
}

int deletebeforepos()
{
	deleteatpos((inputpos())- 1);
	return 0;
}
int deleteafterpos()
{
	deleteatpos((inputpos()) + 1);
	
	return 0;
}
int deletebeforenum()
{
	inputval();

	temp1 = head;
	for (; i != (temp1->link->link->info); ) {
		temp1 = temp1->link;
	}
	if (temp1 == head) {
		deleteatbeg();
		return 0;
	}

	temp1 = temp1->link;
	temp1->link = temp1->link->link;
	
	return 0;
}	
int deleteafternum()
{
	inputval();

	temp1 = head;
	while (i != (temp1->info)){
		temp1 = temp1->link;
	}
	if ( temp1 -> link == NULL) {
		printf ("No nodes after given position\n");
		return 0;
	}

	temp1->link = temp1->link->link;
	
	return 0;
}	
int deleteatmiddle()
{

	deleteatpos((count() / 2) + 1);
	return 0;
}

int deleteatpenultimate()
{

	deleteatpos(count() - 1);
	return 0;
}
