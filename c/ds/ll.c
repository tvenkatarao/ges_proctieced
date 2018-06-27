#include<stdio.h>
#include<stdlib.h>
int count =0;
struct st
{
	struct st *prev;
	int data;
	struct st *next;
}*temp,*hptr,*new;
void create()
{
	int x;
	new = (struct st *) malloc(1*sizeof(struct st));
	new->prev =NULL;
	new->next = NULL;
	printf("enter the value x:\n");
	scanf("%d",&x);
	new->data = x;
	count++;
}
void insert()
{
	if(hptr == NULL)
	{
		create();
		hptr = new;
	}
	else
	{
		create();
		new->next = hptr;
		hptr->prev = new;
		hptr = new;
	}

}
void delete()
{
	int i=1,pos;
	printf("enter the position to be deleted:");
	scanf("%d",&pos);

	temp = hptr;
	if((pos <1) || (pos >= count+1))
	{
		printf("\nERROR:position out of range to delete\n");
		return ;
	}
	if(hptr == NULL)
	{

		printf("ERRor:empty list:\n");
		return ;

	}
	else
	{
		while(i<pos)
		{
			temp = temp->next;
			i++;
		}
		if(i == 1)
		{
			if(temp->next == NULL)
			{
				printf("node delete from list\n");
				free(temp);
				temp = hptr = NULL;
				return;

			}
		}
		if(temp->next == NULL)
		{
			temp ->prev->next =NULL;
			free(temp);
			printf("node delete from list:\n");
			return;
		}

		temp -> next ->prev =temp->prev;
		if(i != 1)
		{
			temp->prev->next = temp->prev;
		}
		if(i == 1)
			hptr = temp ->next;
		printf("node deleted\n");
		free(temp);
	}
	count--;
}



void print()
{
	struct st *ptr = hptr;
   char buff[10];
   char buff2[10];
	while(ptr != NULL)
	{
      sprintf(buff,"%d",(char*)ptr->data);
      buff+sizeof(buff)-1;
		printf("%d\t",ptr->data);
		ptr = ptr->next;
     
	}

      printf("\n%s\n",buff);
}
int main()
{
	int no;
hptr = NULL;
new = NULL;
	printf("add :1\n");
	printf("delete:2\n");
	printf("print:3\n");
	printf("update:4\n");

	while(1)
	{
		printf("enter the option:");
		scanf("%d",&no);

		switch(no)
		{
			case 1: insert();
				break;
			case 2: delete();
				break;
			case 3: print();
				break;
			case 4:exit(0);
			default :
			       printf("wrong entry:\n");
		}
	}




}

