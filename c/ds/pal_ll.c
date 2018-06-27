// palindrom linked list


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void insertAtEnd();
void display();

struct Node
{
	char str[10];
	struct Node *next;
}*head = NULL;

void main()
{
	int choice,choice1,loc1,loc2;
   char str[10];
	while(1){
mainMenu: printf("\n\n********* MENU ************");
	printf("\n1. Insert\n2. Display\n3.exit\nEnter your choice: ");
	  scanf("%d",&choice);
	  switch(choice)
	  {
						case 1: insertAtEnd();
								break;
		            case 2: 	display();
				               break;
		  case 3: 	exit(0);
		  default: printf("\nWrong input!!! Try again!!\n\n");
	  }
goto mainMenu;
	}
}


void insertAtEnd()
{
 
	struct Node *newNode;
	newNode = (struct Node*)malloc(sizeof(struct Node));
   
  
   printf("Enter the string to be insert: ");
				scanf("%s",newNode->str);

	newNode->next = NULL;
	if(head == NULL)
		head = newNode;
	else
	{
		struct Node *temp = head;
		while(temp->next != NULL)
			temp = temp->next;
		temp->next = newNode;
	}
	printf("\nOne node inserted!!!\n");
}


int is_palindrome(char*);
void copy_string(char*, char*);
void reverse_string(char*);
int string_length(char*);
int compare_string(char*, char*);


int is_palindrome(char *string) {
    int check, length;
    char *reverse;
    length = string_length(string);
    reverse = (char*)malloc(length+1);
    copy_string(reverse, string);
    reverse_string(reverse);
    check = compare_string(string, reverse);
    free(reverse);
    if ( check == 0 )
        return 1; else
            return 0;
}
int string_length(char *string) {
    int length = 0;
    while(*string) {
        length++;
        string++;
    }
    return length;
}
void copy_string(char *target, char *source) {
    while(*source) {
        *target = *source;
        source++;
        target++;
    }
    *target = '\0';
}
void reverse_string(char *string) {
    int length, c;
    char *begin, *end, temp;
    length = string_length(string);
    begin = string;
    end = string;
    for ( c = 0 ; c < ( length - 1 ) ; c++ )
        end++;
    for ( c = 0 ; c < length/2 ; c++ ) {
        temp = *end;
        *end = *begin;
        *begin = temp;
        begin++;
        end--;
    }
}
int compare_string(char *first, char *second) {
    while(*first==*second) {
        if ( *first == '\0' || *second == '\0' )
            break;
        first++;
        second++;
    }
    if( *first == '\0' && *second == '\0' )
        return 0; else
            return -1;
}








void display()
{
         char  dest[50];
	if(head == NULL)
	{
		printf("\nList is Empty\n");
	}
	else
	{
		struct Node *temp = head;
		printf("\n\nList elements are - \n");
		while(temp!= NULL)
		{
			printf("%s --->",temp->str);
         {
      //   char src[50];
       //  strcpy(src,  temp->str);
       //  strcat(dest, src);
         }
         strcat(dest, temp->str);
         memset(temp->str,0,sizeof(char)*strlen(temp->str));
			temp = temp->next;
		}
		printf(" --->NULL\n");
	}
//palindrome(dest);
int result;
  result = is_palindrome(dest);
    if ( result == 1 )
        printf("\"%s\" is a palindrome string.\n", dest); 
    else
            printf("\"%s\" is not a palindrome string.\n", dest);
 


printf("dest=%s\n",dest);
}
