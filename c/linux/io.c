#include <stdio.h>
extern void io();

int insertatbeg();
int insertatend();
int insertatpos(int );
int insertbeforepos();
int insertafterpos();
int insertbeforenum();
int insertafternum();
int insertatmiddle();
int insertatpenultimate();
int deleteatbeg();
int deleteatend();
int deleteatpos(int );
int deletebeforepos();
int deleteafterpos();
int deletebeforenum();
int deleteafternum();
int deleteatmiddle();
int deleteatpenultimate();
void display();
int inputpos();

int i;

void io()
{
	int choice;
	char ch;
	printf( "1. insert at the beginning\n2. insert at the end\n3. insert at a given position\n4. insert before a given position\n5. Insert after a given position\n");
	printf( "6. insert before a given number\n7. insert after a given number\n8. insert at the middle\n9. insert at penultimate node\n10. delete at the beginning\n11. delete at the end\n");
	printf( "12. delete at a given position\n13. delete before a given position\n14. delete after a given position\n15. delete before a given number\n");
	printf( "16. delete after a given number\n17. delete at the middle\n18. delete at penultimate node\n");

do {

	printf ("enter your choice ");
	scanf ("%d", &choice);

	switch (choice) {

	case 1 :
			insertatbeg();
			break;
	case 2 :
			insertatend();
			break;
	case 3 :inputpos();
			insertatpos(i);
			break;
	case 4 :
			insertbeforepos();
			break;
	case 5 :
			insertafterpos();
			break;
	case 6 :
			insertbeforenum();
			break;
	case 7 :
			insertafternum();
			break;
	case 8 :
			insertatmiddle();
			break;
	case 9 :
			insertatpenultimate();
			break;
	case 10 :
			deleteatbeg();
			break;
	case 11 :
			deleteatend();
			break;
	case 12 :inputpos();
			deleteatpos(i);
			break;
	case 13 :
			deletebeforepos();
			break;
	case 14 :
			deleteafterpos();
			break;
	case 15 :
			deletebeforenum();
			break;
	case 16 :
			deleteafternum();
			break;
	case 17 :
			deleteatmiddle();
			break;
	case 18 :
			deleteatpenultimate();
			break;
	}

	display();

	label : printf ("do you to continue [y/n]");
			getchar();
			scanf ("%c", &ch);

			if (ch == 'y')
				continue;

			else if (ch == 'n')
				break;

			else { 
				printf ("invalid input\n");
				goto label;
			}

	} while(1);
}
