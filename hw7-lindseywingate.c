#include <stdio.h>
#include <stdlib.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.

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
	//head is head node  
	struct Node* temp = head;
	//pointer to new nodea
	struct Node* newNode = get_new_node(x);
	if(head == NULL) {
		//point to node
		head = newNode;
		return;
	}
	//temp is the pointer that moves around
	while(temp->next != NULL) 
		temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

//Prints all the elements in linked list in forward traversal order
void DISPLAY_INORDER() {
	struct Node* temp = head;
	if(temp==NULL) {
		return;
	}
	while(temp != NULL) {
		printf("Left to right output:	%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void DISPLAY_POSTORDER() {
	struct Node* temp = head;
	if(temp == NULL) 
		return; // empty list, exit
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

void FREE_INORDER() {	
	struct Node* temp = head;
	while(temp->next != NULL) {
		temp = temp->next;
	}
	while(temp!=NULL) {
		free(temp->prev);
	}
}

/*void delete_node(int num) {
	struct Node* temp = head;
	struct Node* temp2 = NULL;
	//if(temp==NULL)
	//head deleted
	//if(temp->data==num)
		
	while(temp->next != NULL) {
		if(temp->data == num) {
			temp2 = temp->next;
		}	
		temp=temp->next;
	}

}*/

struct Node* find_node(int num) {
	struct Node* temp = head;
	if(temp==NULL)
		return temp;
	while(temp->next != NULL) {
		if (temp->data == num) {
			printf("FOUND!");
			return temp;	
		}
		temp = temp->next;		
	}
	return NULL;
}

int main(int num, char*arg[]) 
{
	if(num==2)
		printf("\nCommand line argument:	%s\n\n", arg[1]);
	else if(num>2)
		printf("Too many arguments supplied.\n");
	else
		printf("One argument expected.\n");

	head = NULL; // empty list. set head as NULL. 
	end = NULL;

	int n;
	int n2 = atoi(arg[1]);
	//add to list up until number n2, which is the command line input
	for(n=0; n<n2+1; n++)
	{
		add(n); 
		printf("Input Data:		%d\n",n);
	}
	printf("\n");
	DISPLAY_INORDER();	
	DISPLAY_POSTORDER();
	FREE_INORDER();
	struct Node* newNode = find_node(3);
	printf("%d", newNode->data);	
}
/* This code was written by Lindsey Wingate*/
