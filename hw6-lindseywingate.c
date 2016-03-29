#include <stdio.h>
#include <stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* nodester; // global variable - pointer to nodester node.

//Creates a new Node and returns pointer to it. 
struct Node* get_new_node(int x) 
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	return newNode;
}

//Inserts a Node at tail of Doubly linked list
void add(int x) {
	struct Node* temp = nodester;
	struct Node* newNode = get_new_node(x);
	if(nodester == NULL) {
		nodester = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void print() {
	struct Node* temp = nodester;
	while(temp != NULL) {
		printf("Left to right output:	%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void print_reverse() {
	struct Node* temp = nodester;
	if(temp == NULL) return; // empty list, exit
	// Going to last Node
	while(temp->next != NULL) {
		temp = temp->next;
	}
	// Traversing backward using prev pointer
	while(temp != NULL) {
		printf("Right to left output:	%d\n",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main(int num, char*arg[]) {

	if(num==2)
		printf("\nCommand line argument:	%s\n\n", arg[1]);
	else if(num>2)
		printf("Too many arguments supplied.\n");
	else
		printf("One argument expected.\n");

	/*Driver code to test the implementation*/
	nodester = NULL; // empty list. set nodester as NULL. 

	int n;
	int n2 = atoi(arg[1]);
	for(n=0; n<n2+1; n++)
	{
		add(n); 
		printf("Input Data:		%d\n",n);
	}
	printf("\n");
	print();	
	print_reverse();
}
/* This code was written by Lindsey Wingate*/
