/*This code was written by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*struct Node {
	char data[50];
	struct Node* next;
	struct Node* prev;
};
struct Node* head;
*/
int main()
{
	int c;
	FILE*file1;
	char test;
	
	file1 = fopen("hw9.data", "r");
	if(file1==NULL) {
		printf("Can't open file.");
		exit(1);
	}	
	if(file1) {
		while((c=getc(file1)) !=EOF)
			putchar(c);
		fclose(file1);
	}
}
/*This code was written by Lindsey Wingate*/
