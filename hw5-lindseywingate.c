/* Code created by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
	int data;
	struct node *next;
};

int main(void)
{
	//set up root node first
	struct node *root;
	root = (struct node*) malloc(sizeof(struct node));
	root->next = NULL;
	root->data = 9;
	int	count = 8;

	/*for(count; count>-1; count--) {
		struct node *current;
		current = (struct node*) malloc(sizeof(struct node));
		current->next = NULL;
		root->data = count;
	}
	*/
		//create linked list with for loop and print low to high
		//request input and do linear search for data

		//correctly free all links
}

/* Code created by Lindsey Wingate*/


