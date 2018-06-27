#include <stdlib.h>
#include <stdio.h>

struct Link {
	int value;
	struct Link * next;
};

typedef struct Link node;

// add a node to the beginning of list
// return the pointer to the new beginning
node * push(node * head, int value) {
	node * l = malloc(sizeof(node));
	l->value = value;
	l->next = head;
	return l;
}

// print the list starting from head
void print(node * head) {
	node * i = head;
	printf("{");
	while(i != NULL) {
		if(i == head)
			printf("%d",i->value);
		else
			printf(",%d",i->value);
		i = i->next;
	}
	printf("}\n");
}

// reverse the list
node * reverse (node * head) {
	if(head->next == NULL){
       printf("if head->next == NULL\n");
		return head;
   }
	else {
       printf("before newnode:-%d\n",head->value);
		node * newhead = reverse(head->next);
      printf("after newnode:-%d\n",newhead->value);
		head->next->next = head;
      printf("after head->next->next=head\n");
		head->next = NULL;
      printf("after head->next=nULL\n");
		return newhead;
	}
}

int main() {
	// make a linked list
	node * head = NULL;
	head = push(head, 5);
	head = push(head, 4);
	head = push(head, 3);
	head = push(head, 2);
	head = push(head, 1);

	// print the list, reverse it, and print again
	print(head);
	head = reverse(head);
	print(head);
}
