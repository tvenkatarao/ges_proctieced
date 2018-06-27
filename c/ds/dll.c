#include <stdio.h>
#include <stdlib.h>

void io();
int insertatpos(int i);

struct node 
{
	int info;
	struct node *rlink;
	struct node *llink;
};

int i;
int n;

struct node *temp1;
struct node *head = NULL; 
struct node *temp;

int inputpos()
{ 
	printf ("enter position ");
	scanf ("%d", &n);
	return n;
}

void display()
{
	temp1 = head;
	printf ("\n");
	for (i = 1; temp1->rlink != NULL; i++) {
		printf ("%d	", temp1->info);
		temp1 = temp1->rlink;
	}
	printf ("%d\n", temp1->info);
}

int count()
{
	temp1 = head;
	for (i = 1; temp1->rlink != NULL; i++) {
		temp1 = temp1->rlink;
	}
	return i;
}

void createnode()
{
	temp = (struct node *) malloc (sizeof(struct node));  
	printf ("enter data ");
	scanf ("%d", &temp->info);

}

void linking()
{
	temp->rlink = temp1->rlink;
	temp->llink = temp1;
	temp1->rlink->llink = temp;
	temp1->rlink = temp;	
}
void linkingbefore()
{
	temp->rlink = temp1;
	temp->llink = temp1->llink;
	temp1->llink->rlink = temp;
	temp1->llink = temp;

}

int main(void)
{

	int create()
	{
		printf ("enter no of nodes to create ");
		scanf ("%d", &n);
	
	    createnode();
		
		temp->llink = NULL;
	
		head = temp;
		temp1 = temp;

		for (i = 2; i <= n; i++) {
			temp = (struct node *) malloc (sizeof(struct node));  
			temp1->rlink = temp;
			temp->llink = temp1;
			scanf ("%d", &temp->info);
			temp1 = temp1->rlink;
		}

		temp->rlink = NULL;

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
	head->llink = temp;
	temp->rlink = head;
	head = temp;
	return 0;
}
int insertatend()
{

	createnode();

	temp1 = head;
	while (temp1->rlink != NULL) {
		temp1 = temp1->rlink;
	}

	temp1->rlink = temp;
	temp->llink = temp1->rlink;
	temp->rlink = NULL;

	return 0;
}
int insertatpos(int i)
{
	
	if (i > count()) {
		printf ("please enter position within list and list size is %d\n", count());
		return 0;
	}

	if (i == 1) {
		insertatbeg();
		return 0;
	}

	createnode();
	temp1 = head;

	for (; (i - 2) != 0; i--) {
		temp1 = temp1->rlink;
	}

	linking();

	return 0;
}
int insertbeforepos()
{
	i = inputpos();

	insertatpos(i - 1);

	return 0;
}
int insertafterpos()
{
	i = inputpos();
	insertatpos(i + 1);

	return 0;
}
int insertbeforenum()
{
	int c = count();

	printf ("Enter data in dll to insert data before it : ");
	scanf ("%d", &i);

	if (head->info == i) {

		insertatbeg();

		return 0; 
	}

	createnode();

	temp1 = head;

	for (; (i != (temp1->info)) && ((c - 1) != 0); c--) {
		temp1 = temp1->rlink;
	}
/*	if (c == 0) {
		printf ("Given data is not present in dll  and below see the list of dll and try again \n");
		return 0;
	}*/

	linkingbefore();

	return 0;
}	
int insertafternum()
{

	printf ("Enter data in dll to insert data after it : ");
	scanf ("%d", &i);

	createnode();

	temp1 = head;

	for (; i != (temp1->info); ) {
		temp1 = temp1->rlink;
	}
	if (temp1->rlink == NULL) {
		temp->llink = temp1;
		temp1->rlink = temp;
		temp->rlink = NULL;
		return 0;
	}

	linking();

	return 0;
}	
int insertatmiddle()
{
	insertatpos((count()) / 2);
	
	return 0;
}

int insertatpenultimate()
{
	insertatpos((count())- 2);
	
	return 0;
}

int deleteatbeg()
{

	temp1 = head;
	
	temp1 = temp1->rlink; 
	
	head = temp1;

	return 0;
}
int deleteatend()
{
	i = count();
	
	temp1 = head;

	for (;(i - 2) != 0; i--) {
		temp1 = temp1->rlink;
	}
	temp1->rlink = NULL;

return 0;
}
int deleteatpos(int i)
{

	if (i > count()) {
		printf ("please enter position within list\n");
		return 0;
	}

	temp1 = head;

	for (;(i-2) != 0; i--) {
		temp1 = temp1->rlink;
	}
	if (temp1 == head) {
		deleteatbeg();
		return 0;
	}

	if (temp1->rlink->rlink == NULL) {
		temp1->rlink = NULL;
		return 0;
	}
	
	temp1->rlink = temp1->rlink->rlink;

return 0;
}

int deletebeforepos()
{
	inputpos();

	deleteatpos(i - 1);

return 0;
}
int deleteafterpos()
{
	inputpos();

	deleteatpos(i - 1);

	return 0;
}
int deletebeforenum()
{
	printf ("Enter info within dll to compare ");
	scanf ("%d", &i);

	temp1 = head;
	for (; i != (temp1->rlink->rlink->info); ) {
		temp1 = temp1->rlink;
	}
	if (temp1 == head) {
		deleteatbeg();
		return 0;
	}

	temp1 = temp1->rlink;
	temp1->rlink = temp1->rlink->rlink;
	
	return 0;
}	
int deleteafternum()
{
	printf ("Enter info within dll to compare ");
	scanf ("%d", &i);

	temp1 = head;
	while (i != (temp1->info)){
		temp1 = temp1->rlink;
	}
	if ( temp1 -> rlink == NULL) {
		printf ("No nodes after given position\n");
		return 0;
	}

	temp1->rlink = temp1->rlink->rlink;
	
	return 0;
}	
int deleteatmiddle()
{

	deleteatpos((count()) / 2);

	return 0;
}

int deleteatpenultimate()
{
	deleteatpos((count()) - 2);

	return 0;
}

