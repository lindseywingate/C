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

/*link *searchList(int n, link *head)
{
	nodey *current;
	current = head;
	while(current->next !=NULL) {
		if(current->data == n)
			return 1;			
		else 
			current=current->next;
	}
	return 0;
}
*/

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

	int findme = 0;
	printf("Please enter a numerical value: ");
	scanf("%d", &findme);
//	searchList(findme, head);
//	printf("[%d %d]\n", n, searchList(n, head)->data);

	return 0;
}

/* Code created by Lindsey Wingate*/


