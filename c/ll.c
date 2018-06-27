#include<stdio.h>
typedef struct st
{
	char name[20];
	struct st *next;
}Node;
Node *hptr,*new ,*ptr;
void reverse(Node  * ptr)
{
	Node * temp;
	Node * previous = NULL;
	while(ptr != NULL) {
		temp = ptr->next;
		ptr->next = previous;
		previous = ptr;
		ptr = temp;
	}
	return previous;
}
void create();
void insert();
void display();
int main()
{
	int i,num;
	hptr=NULL;
	printf("enter the number of ...\n");
	scanf("%d",&num);
	for(i=0;i<num;i++)
		insert();
	reverse(&hptr);
	display1();
}
void create()
{
	int n;
	new=(Node  *)malloc(1*sizeof(Node));
	new->next=NULL;
	printf("enter the node data...\n");
	scanf("%d",&n);
	new->data=n;
}
void insert()
{
	if(hptr==NULL)
	{
		create();
		hptr=new;
	}
	else
	{
		create();
		new->next=hptr;
		hptr=new;
	}
}
void display()
{
	while(hptr)
	{
		printf("%d ",hptr->data);
		hptr=hptr->next;
	}
}
