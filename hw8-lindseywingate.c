#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct list
{
	char first_name[15];
	char last_name[15];
	char phone_number[7];
	struct Node* next;			
}list; 

//void add(int num1, int num2, int num3, int num4, int num5, int c) {
			

int main(void)
{
	//do_this:  I == should add
	//			R == should delete
	char do_this;
	int num_of_nodes;
	int num1;
	int num2;
	int num3;
	int num4;
	int num5;	
	int count=0;
	
	char line[100];		
	struct list s_array[10];//array of structs
	FILE* file1;
	file1 = fopen("hw8data.txt", "r");
	
	while(1) {
		if(feof(file1)) 
			break;
		fscanf(file1, "%c %s %s %d %d %d %d %d %d", &do_this, s_array[count].first_name, s_array[count].last_name, &num_of_nodes, &num1, &num2, &num3, &num4, &num5);
	
	//add(num1, num2, num3, num4, num5, count);	

	//	fscanf(file1, "%s", line); 
	//	printf("%s\n", line);
		printf("%c %d %d %d %d %d %d\n", do_this, num_of_nodes, num1, num2, num3, num4, num5);		
		count = count+1;
	}
	int m;
	for(m=0; m<10; m++) {
		printf("%s", s_array[m].first_name);
		printf("%s\n", s_array[m].last_name);
	}
}
