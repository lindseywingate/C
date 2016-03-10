/* Code created by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node 
{
	int data;
	struct node *next;
};
typedef struct node nodey;

void add(nodey **head)
{
int count;
nodey *current;
	for(count=9; count>=0; count--) {
		current = (nodey *)malloc(sizeof(nodey));
		current->data = count;
		current->next = (*head);
		(*head) = current;
	}
}

struct node *searchList(int search, nodey *head)
{
	nodey *current;
	current = head;
	while(current !=NULL) {
		if(current->data == search)
			return current;			
		else 
			current=current->next;
	}
	return NULL;
}

void printnodeys(nodey *head)
{
nodey *current;
	current = head;
	while (current != NULL) {
		printf("%d\n", current->data);
		current = current->next;
	}
}

int main(void)
{
nodey *head;
	head = NULL;
	add(&head);
	printnodeys(head);

	int search = 0;
	printf("Please enter a numerical value: ");
	scanf("%d", &search);
	searchList(search, head);
	if (search<10 && search>=0)
		printf("[%d %d]\n", search, searchList(search, head)->data);
	else
		printf("Your value was not found.\n");
	return 0;
}

/* Code created by Lindsey Wingate*/


