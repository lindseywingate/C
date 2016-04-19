/*This code was written by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
	char data[50];
	struct Node* next;
	struct Node* prev;
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

//Prints all the elements in linked list in forward traversal order
void print() {
	struct Node* temp = nodester;
	while(temp != NULL) {
		printf("%s\n",temp->data);
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
		printf("Right to left output:	%s\n",temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main()
{
	int c;
	FILE*file1;
	char test[50];
	char trash;
	file1 = fopen("hw9data.txt", "r");
	if(file1==NULL) {
		printf("Can't open file.");
		exit(1);
	}
	while(fgets(test, sizeof test, file1) !=NULL) {
		if(strstr(test, "STOP") != 0)
			break;
		else {	
			add(test);	
		}
	}
	print();
	fclose(file1);
}

/*This code was written by Lindsey Wingate*/
