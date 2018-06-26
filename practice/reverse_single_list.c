/*the program for reverse single linked list*/
#include<stdio.h>
struct node
{
int x;
struct node *nxt;

};

struct node *create_list(struct node *head, int x)
{

struct node *tem=head;
struct node *new;
new=(struct node *)malloc(sizeof(struct node *));
new->x=x;
new->nxt=NULL;
if(head == NULL)
{
printf("adding 1st node:%d\n",new->x);
head=new;
return head;
}
while(tem->nxt != NULL)
tem=tem->nxt;
tem->nxt=new;
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
pre=curr;
curr=next;
}
curr->nxt=pre;
return head=curr;
}
int print_list(struct node *head)
{
struct node *tem=head;
while(tem != NULL)
{
	printf("%d\n",tem->x);
	tem=tem->nxt;
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
 list=reverse_the_list(list);
 print_list(list);

return;

}
