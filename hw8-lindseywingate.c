#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

typedef struct list
{
	char first_name[15];
	char last_name[15];
	char phone_number[7];
	struct Node* next;			
}list; 

int main(void)
{
	struct list s_array[10];//array of structs
	FILE*file1;
/*	file1.fopen("hw8data.txt");
	while(1) {
		if(feof(file1)) {
			break;
		}
		fscanf(file1, "%s", 
*/			


}
