#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct Node  {
	int data;
	struct Node* next;
	struct Node* prev;
};

struct Node* head; // global variable - pointer to head node.
struct Node* head_garbage;
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
		temp = temp->next; // go to last Node
	temp->next = newNode; //adds new node to end of list
	newNode->prev = temp; //links node back to list
}

void add_garbage(int x) {
	//head is head node  
	struct Node* temp = head_garbage;
	//pointer to new nodea
	struct Node* newNode = get_new_node(x);
	if(head_garbage == NULL) {
		//point to node
		head_garbage = newNode;
		return;
	}
	//temp is the pointer that moves around
	while(temp->next != NULL) 
		temp = temp->next; // go to last Node
	temp->next = newNode; //adds new node to end of list
	newNode->prev = temp; //links node back to list
}

void delete_node_perm(int num) {
	struct Node* temp = head;
	struct Node* temp2 = head;//use for reference for deleting nodes 
	if(temp==NULL)
		return;	
	if(temp->data==num) {
		head = temp->next;
		head->prev=NULL;
		free(temp);
		return;
	}
	while(temp->next!=NULL)	{
		if(temp->data==num) {
			temp2 = temp->prev;//node before temp
			temp2->next = temp->next;//node before temp points to node after temp
			temp->next = NULL;//temp is disconnected from next node
			temp->prev = NULL;//temp is disconnected from prev node
			free(temp);
			temp=temp2->next;//temp is reassigned to node after temp2
			temp->prev = temp2;//list is reconnected, goes full circle
			return;
		}
		if(temp->data!=num) {
			temp=temp->next;
		}
	}
	if(temp->next==NULL) {
		temp2 = temp->prev;
		temp2->next = NULL;
		temp->prev = NULL;
		free(temp);	
		return;	
	}
}

void add_to_garbage_list(int num) {
	struct Node* temp = head;
	struct Node* temp2 = head;//use for reference for deleting nodes 
	if(temp==NULL)
		return;	
	if(temp->data==num) {
		head = temp->next;
		head->prev=NULL;
		add_garbage(temp->data);
		free(temp);
		return;
	}
	while(temp->next!=NULL)	{
		if(temp->data==num) {
			temp2 = temp->prev;//node before temp
			temp2->next = temp->next;//node before temp points to node after temp
			temp->next = NULL;//temp is disconnected from next node
			temp->prev = NULL;//temp is disconnected from prev node
			add_garbage(temp->data);
			free(temp);
			temp=temp2->next;//temp is reassigned to node after temp2
			temp->prev = temp2;//list is reconnected, goes full circle
			return;
		}
		if(temp->data!=num) {
			temp=temp->next;
		}
	}
	if(temp->next==NULL) {
		temp2 = temp->prev;
		temp2->next = NULL;
		temp->prev = NULL;
		add_garbage(temp->data);
		free(temp);	
		return;	
	}
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

//Prints all the elements in linked list in forward traversal order
void DISPLAY_TRASH() {
	struct Node* temp = head_garbage;
	if(temp==NULL) {
		return;
	}
	while(temp != NULL) {
		printf("TRASH LIST:		%d\n",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

//Prints all elements in linked list in reverse traversal order. 
void DISPLAY_POSTORDER() {
	struct Node* temp = head;
	if(temp == NULL)
		return; // empty list, exit
	// go to last Node
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
		head = temp->next;
		temp->next=NULL;
		free(temp);		
		temp = head;
	}
	if(temp->next==NULL) {
		head=NULL;
		free(temp);	
	}
}

void FREE_TRASH() {
	struct Node* temp = head_garbage;
	while(temp->next != NULL) {
		head_garbage = temp->next;
		temp->next=NULL;
		free(temp);		
		temp = head_garbage;
	}
	if(temp->next==NULL) {
		head_garbage=NULL;
		free(temp);	
	}
}

int length() {
	struct Node* temp = head;
	int count=0;
	if(temp==NULL)
		return 0;
	while(temp->next != NULL) {
		temp=temp->next;
		count++;
	}
	return count;
}
//*****************************************main********************************************//

int main(int num, char*arg[]) {
	//get data from command line
	if(num==2)
		printf("\nCommand line argument:	%s\n\n", arg[1]);
	else if(num>2)
		printf("Too many arguments supplied.\n");
	else
		printf("One argument expected.\n");

	head = NULL; // empty list. set head as NULL. 
	head_garbage = NULL; //empty trash list. set head as null

	int n,i;
	int n2 = atoi(arg[1]);//number input from command line
	//add to list up until number n2, which is the command line input
	for(n=0; n<n2+1; n++)
	{
		add(n); 
		printf("Input Data:		%d\n",n);
	}
	printf("\n");
	
	//show the nodes that were added to the main list
	DISPLAY_INORDER();	
	DISPLAY_POSTORDER();
	
	//randomly select the nodes that will be deleted using seeded rand
	time_t t;
	srand((unsigned) time(&t));
	int delete_me;
	int del_node_num;
	if(n2==1 || n2==2 || n2==3)
		del_node_num = 1;
	if(n2>3)
		del_node_num = rand() % n2+1;
	for(i=0; i<del_node_num; i++) {
		delete_me = rand() % n2;
		add_to_garbage_list(delete_me);
	}
			
	//display trash list and free
	DISPLAY_TRASH();
	FREE_TRASH();

	//display remaining contents of the original list
	DISPLAY_INORDER();
	DISPLAY_POSTORDER();
	//free original list
	FREE_INORDER();
}
/* This code was written by Lindsey Wingate*/
