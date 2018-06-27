/*Linked list using Recursion*/
#include<stdio.h>
#include<stdlib.h>

struct node
{
    int info;
    struct node *link;
};
struct node *create_list(struct node *start);
void display(struct node *ptr);
void Rdisplay(struct node *ptr);
int length(struct node *ptr);
int sum (struct node *ptr);
int search(struct node *ptr, int item );
struct node *insertLast(struct node *ptr, int value);
struct node *delLast(struct node *ptr );
struct node *reverse(struct node *ptr);

main()
{
    struct node *start=NULL;
    int choice,data;

    while(1)
    {
        printf("\n1.Create List\n");
        printf("\n2.Display\n");
        printf("\n3.Display in reverse order\n");
        printf("\n4.Count\n");
        printf("\n5.Sum of elements\n");
        printf("\n6.Search\n");
        printf("\n7.Insert at last\n");
        printf("\n8.Delete the last node\n");
        printf("\n9.Reverse the list\n");
        printf("\n10.Quit\n");

        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1:
                start=create_list(start);
                break;
            case 2:
                display(start);
                printf("\n");
                break;
            case 3:
                Rdisplay(start);
                printf("\n");
                break;
            case 4:
                printf("\nNumber of elements = %d\n",length(start));
                break;
            case 5:
                printf("\nSum of elements = %d\n",sum(start));
                break;
            case 6:
                printf("\nEnter the element to be searched : ");
                scanf("%d",&data);
                if( search(start,data) == 1 )
                    printf("\nElement present\n");
                else
                    printf("\nElement not present\n");
                break;
            case 7:
                printf("\nEnter the element to be inserted : ");
                scanf("%d",&data);
                start=insertLast(start,data);
                break;
            case 8:
                start=delLast(start);
                printf("\nLast node deleted……\n");
                break;
            case 9:
                start=reverse(start);
                break;
            case 10:
                exit(1);
            default:
                printf("\nWrong choice\n");
        }/*End of switch */
    }/*End of while */
}/*End of main()*/

struct node *create_list(struct node *start)
{
    int i,n,value;
    struct node *q,*tmp;
    printf("\nEnter the number of nodes : ");
    scanf("%d",&n);
    start=NULL;
    for(i=1;i<=n;i++)
    {
        printf("\nEnter the element to be inserted : ");
        scanf("%d",&value);

        tmp= malloc(sizeof(struct node));
        tmp->info=value;
        tmp->link=NULL;

        if(start==NULL) /*If list is empty */
            start=tmp;
        else
        { /*Element inserted at the end */
            q=start;
            while(q->link!=NULL)
                q=q->link;
            q->link=tmp;
        }
    }
    return start;
}/*End of create_list()*/

void display(struct node *ptr)
{
    if(ptr==NULL)
        return;
    printf("%3d",ptr->info);
    display(ptr->link);
}/*End of display()*/

void Rdisplay(struct node *ptr)
{
    if(ptr==NULL)
        return;
    Rdisplay(ptr->link);
    printf("%3d",ptr->info);
}/*End of Rdisplay()*/

int length(struct node *ptr)
{
    if(ptr==NULL)
        return 0;
    return 1 + length(ptr->link);

}/*End of length()*/

int sum (struct node *ptr)
{
    if (ptr == NULL)
        return 0;
    return ptr->info + sum(ptr->link);
}/*End of sum()*/

int search(struct node *ptr, int item )
{
    if(ptr==NULL)
        return 0;
    if( ptr->info == item )
        return 1;
    return search(ptr->link, item);
}/*End of search()*/

struct node *insertLast(struct node *ptr, int item)
{
    struct node *temp;
    if (ptr == NULL)
    {
        temp = malloc(sizeof(struct node));
        temp->info = item;
        temp->link = NULL;
        return temp;
    }
    ptr->link = insertLast(ptr->link, item);
    return ptr;
}/*End of insertLast()*/

struct node *delLast(struct node *ptr )
{
    if( ptr->link == NULL )
    {
        free(ptr);
        return NULL;
    }
    ptr->link = delLast(ptr->link);
    return ptr;
}/*End of delLast()*/

struct node *reverse(struct node *ptr)
{
    struct node *temp;
    if( ptr->link == NULL )
        return ptr;
    temp=reverse(ptr->link);
    printf("=======>%d\n",ptr->link->info);
    ptr->link->link=ptr;
    ptr->link=NULL;
    return temp;
}/*End of reverse()*/

