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
	char line[100];		
	struct list s_array[10];//array of structs
	FILE*file1;
	file1 = fopen("hw8data.txt", "r");
	
	while(1) {
		if(feof(file1)) 
			break;
		fscanf(file1, "%s", line); 
		/*fscanf(file1, "%c %s %s %d %d", &do_this, first_name, last_name, &num_of_nodes, &phone); 
		printf("%c %s %s %d %d\n", do_this, first_name, last_name, num_of_nodes, phone);
		*/
		printf("%s\n", line);
	}
}
