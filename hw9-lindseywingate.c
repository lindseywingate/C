/*This code was written by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char data[50];
	struct Node* next;
	struct Node* prev;
	struct Node* list;
	int cost;
};

struct Node* nodester;

//Inserts a Node at tail of Doubly linked list
void add(char x[50]) {
	struct Node* temp = nodester;
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	strcpy(newNode->data, x);
	newNode->prev = NULL;
	newNode->next = NULL;
	if(nodester == NULL) {
		nodester = newNode;
		return;
	}
	while(temp->next != NULL) temp = temp->next; // Go To last Node
	temp->next = newNode;
	newNode->prev = temp;
}

void add_location(char x[50], char y[50], int num) {
	struct Node* temp = nodester;
	//finding matching location node
	while(temp!=NULL) {
		//if restaurant == restaurant searching for
		if(strstr(temp->data, x)!=0)
			break;
		//if restaurant is not what we are looking for	
		if(strstr(temp->data, x)==0){
			if(temp->next==NULL)		
				break;
			temp=temp->next;
		}
	}
	printf("PRINTING TEMP%s\n", temp->data);	
	//find the head node (in doubly linked list)
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	//set data for new location node
	strcpy(newNode->data, y);
	newNode->list=NULL;
	newNode->cost=num;
	//find end of singly linked list
	while(temp->list!=NULL)
		temp=temp->list;
	temp->list=newNode;
}

//Prints all the elements in linked list in forward traversal order
void print() {
	struct Node* temp = nodester;
	struct Node* temp2;
	while(temp != NULL) {
		printf("MAIN NODE: %s\n",temp->data);
		if(temp->list!=NULL) {
			temp2=temp->list;
			printf("Location Node: %s\n", temp2->data);
			temp2=temp2->next;
		}
		temp = temp->next;
	}
	printf("\n");
}

int main()
{
	int c;
	FILE*file1;
	char test[50];
	char trash;
	char token[50];
	char token2[50];
	int token3;
	file1 = fopen("hw9data.txt", "r");
	if(file1==NULL) {
		printf("Can't open file.");
		exit(1);
	}
	while(fgets(test, sizeof test, file1) !=NULL) {
		//if line has STOP, skip it
		if(strstr(test, "STOP")!=0)
			continue;
		//if line has space, add travel node	
		if(strstr(test, " ")!=0){
			sscanf(test, "%s %s %d\n", token, token2, &token3);
			printf("PRINTING: %s %s %d\n", token, token2, token3);
			add_location(token, token2, token3);	
		}
		//if no spaces, add to doubly linked list
		else {
			add(test);	
		}
	}
	print();
	fclose(file1);
}

/*This code was written by Lindsey Wingate*/
