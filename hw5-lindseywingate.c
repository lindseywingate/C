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
	return 0;

	int findme = 0;
	printf("Please enter a numerical value: ");
	scanf("%d", &findme);
//	search(findme);
	printf("%d", findme);

}

//bool search(int n)
//{

//}

/* Code created by Lindsey Wingate*/


