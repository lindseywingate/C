/*This code was written by Lindsey WIngate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct node
{
	int data;
	struct node *next;
};
typedef struct node nodester;

/*void add(nodester **head, nodester **tail)
{
int count;
nodester *current;
}
*/

int main (int num, char *arg[])
{
	if(num==2)
		printf("%s\n", arg[1]);
	else if(num>2)
		printf("Too many arguments supplied.\n");
	else
		printf("One argument expected.\n");
	
	int thing = atoi(arg[1]);


}




/*This code was written by Lindsey WIngate*/
