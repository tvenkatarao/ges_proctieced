// recursion
#include<stdio.h>
#include<stdlib.h>
typedef struct st
{
	struct st *prev;
        int data;
        struct st *next;
}ST;
ST *hptr,*new ,*ptr,*q;
void create();
void insert();
void display();
void reverse(ST *ptr)
{
printf("%d\t",ptr->data);
if(ptr == NULL)
return ;
reverse(ptr->next);
printf("%d\t",ptr->data);
}

int main()
{
        int i,num;
        hptr=NULL;
        printf("enter the number of ...\n");
        scanf("%d",&num);
        for(i=0;i<num;i++)
                insert();
        reverse(hptr);
//      display();
}
void create()
{
        int n;
        new=(ST *)malloc(1*sizeof(ST));
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
