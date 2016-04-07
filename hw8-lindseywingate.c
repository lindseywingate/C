#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
	char first_name[20];
	char last_name[20];
	int phone_number;
	struct Node* next;			
}Node; 

struct Node s_array[10];//array of structs

struct Node* get_new_node(int num)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));	
	newNode->phone_number=num;
	return newNode;
}

void add(int num, int count) {
	struct Node* temp = &s_array[count];	
	struct Node* newNode = get_new_node(num);
	while(temp->next !=NULL)
		temp=temp->next;
	temp->next=newNode;	

}
		
int delete(char first[20], char last[20], int c) {
	return c;
}

void printme(int count) {
	struct Node* temp=&s_array[count];
	printf("%s %s", temp->first_name, temp->last_name);
	while(temp->next !=NULL){
		printf("%d\n", temp->phone_number);	
		temp=temp->next;
	}
}

int main(void)
{
	char do_this;
	char first[20];
	char last[20];
	int num_of_nodes;
	int num1, num2, num3, num4, num5, m, x;
	int count=0;
	int temp[5];
	
	char line[100];		
	FILE* file1;
	file1 = fopen("hw8data.txt", "r");
	
	while(1) {
		if(feof(file1)) 
			break;
		fscanf(file1, "%c %s %s %d %d %d %d %d %d", &do_this, s_array[count].first_name, s_array[count].last_name, &num_of_nodes, &num1, &num2, &num3, &num4, &num5);
		temp[0]=num1;
		temp[1]=num2;
		temp[2]=num3;
		temp[3]=num4;
		temp[4]=num5;
		if(do_this=='I'){
			for(x=0; x<5; x++) {
				printf("Reading in these nums: %d\n", temp[x]);
				add(temp[x], count);	
			}
			num1=0;
			num2=0;
			num3=0;
			num4=0;
			num5=0;
		}
		else if(do_this=='R')		
			delete(first, last, count);	
		if(do_this=='Q')		
			break;		
	//printf("%c %s %s %d %d %d %d %d %d\n", do_this, first, last, num_of_nodes, num1, num2, num3, num4, num5);		
		count = count+1;
	}
	//confirms names are added to list 
	for(m=0; m<10; m++) {
		printme(m);
	}
}

