/*the program for reverse double circuler linked list*/
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
if(head == NULL)
{
	printf("adding 1st node:%d  \n",new->x);
	head=new;
	head->nxt=head;
	head->prev=head;
	return head;
}
new->nxt=head;
new->prev=NULL;

while(tem->nxt != head)
	tem=tem->nxt;
tem->nxt=new;
new->prev=tem;
head->prev=new;
return head;
}


struct node *reverse_the_list(struct node *head)
{
struct node *pre=NULL;
struct node *curr=head;
struct node *next;
while(curr->nxt != head)
{

next=curr->nxt;
curr->nxt=pre;
curr->prev=next;
pre=curr;
curr=next;
}
curr->nxt=pre;
curr->prev=head;
head->nxt=curr;
return head=curr;
}


int print_list(struct node *head)
{
struct node *tem=head,*pre;
int res=0;
if(head==NULL)
{
printf("list is empty");
return;
}
while(1)
{

	printf("%d  ",tem->x);
	pre=tem;
	tem=tem->nxt;
if(res==2)
break;
if(tem->nxt==head)
res++;
}
printf("\n");
res=0;
while(1)
{
	printf("%d  ",pre->x);
	pre=pre->prev;
if(res==2)
break;
if(pre->prev==head)
res++;
}
printf("\n");
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


