#include<stdio.h>
#include<stdlib.h>
typedef struct st
{

	int data;
	struct st *next;

}ST;

void insert( ST **hptr)
{
        int x,num,i;
printf("enter the no.of nodes requied...\n");
scanf("%d",&num);
        for(i=0;i<num;i++)
        {
                printf("enter the x value : ");
                scanf("%d",&x);

                ST *new = (ST *) malloc(sizeof(ST *));

                new->data = x;
                if(hptr == NULL)
            //            new->next = (*hptr);
                (*hptr) = new;
                
                else 
                        new->next = (*hptr);
                        (*hptr) = new;
                        
       } 

}
void reverse(ST **hptr)
{
        ST *temp = NULL;
        ST *prv = NULL;

        while((*hptr) != NULL)
        {
                temp = (*hptr)->next;
                (*hptr)->next = prv;

                prv = (*hptr);
                (*hptr) = temp;

        }

}
void print(ST **hptr)
{

        while((*hptr) != NULL)
        {

                printf("%d",(*hptr)->data);

                (*hptr) = (*hptr)->next;
        }


}
int main()
{
ST *hptr = NULL;
	insert(&hptr);
	print(&hptr);
	reverse(&hptr);
	print(&hptr);

	return 0;

}
