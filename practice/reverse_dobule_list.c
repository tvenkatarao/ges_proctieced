/*the program for reverse double linked list*/
#include<stdio.h>
struct node
{
int x;
struct node *nxt;
struct node *prev;

};

struct node *create_list(struct node *head, int x)
{

struct node *tem=head;
struct node *new;
new=(struct node *)malloc(sizeof(struct node *));
new->x=x;
new->nxt=NULL;
new->prev=NULL;
if(head == NULL)
{
	printf("adding 1st node:%d\n",new->x);
	head=new;
	return head;
}
while(tem->nxt != NULL)
	tem=tem->nxt;
tem->nxt=new;
new->prev=tem;
return head;
}


struct node *reverse_the_list(struct node *head)
{
struct node *pre=NULL;
struct node *curr=head;
struct node *next;
while(curr->nxt != NULL)
{

next=curr->nxt;
curr->nxt=pre;
curr->prev=next;
pre=curr;
curr=next;
}
curr->nxt=pre;
curr->prev=NULL;
return head=curr;
}
int print_list(struct node *head)
{
struct node *tem=head,*pre;
while(tem != NULL)
{
	printf("%d\n",tem->x);
	pre=tem;
	tem=tem->nxt;
}
while(pre != NULL)
{
	printf("%d\n",pre->x);
	pre=pre->prev;
}
return;
}
main()
{
struct node *list;
//list = (struct node *)malloc(sizeof(struct node *));
int x=1;
while(x <= 10)
list=create_list(list, x++);
//}
 print_list(list);
printf("After revese the list:\n");
 list=reverse_the_list(list);
 print_list(list);

return;

}


