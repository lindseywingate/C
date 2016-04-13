/*This code was written by Lindsey Wingate*/
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

void add(char first[20], char last[20], int num, int count) {
	struct Node* temp = &s_array[count];
	strncpy(temp->first_name, first, 20);
	strncpy(temp->last_name, last, 20);	
	struct Node* newNode = get_new_node(num);
	while(temp->next !=NULL)
		temp=temp->next;
	temp->next=newNode;	
}
		
void delete(char first[20], char last[20], int c) {
	int a;
	
	for(a=0; a<10; a++) {
		struct Node* temp = &s_array[a];	
		int test = strcmp(s_array[a].first_name, first);
		if(test==0){
			//printf("FOUND %s", s_array[a].first_name);		
	
	
	//other temp that actually deletes nodes/gets freed
			struct Node* temp = &s_array[a];
			struct Node* temp2 = &s_array[a];
			strncpy(s_array[a].first_name, "", 20);
			strncpy(s_array[a].last_name, "", 20);
			s_array[a].phone_number=0;
			while(temp2->next != NULL){	
				temp2=temp2->next;
				temp->phone_number=0;	
				temp=temp2;
			}	
			temp->phone_number=0;
		}
	}
}

void printme(int count) {
	struct Node* temp=&s_array[count];
	int test = strcmp(s_array[count].first_name, "");
	if (test!=0) {
		printf("\n%s %s \n", temp->first_name, temp->last_name);
		while(temp!=NULL){
			if(temp->phone_number!=0)
				printf("%d\n", temp->phone_number);	
			temp=temp->next;
		}
	}
	else{
		printf("\nEmpty Contact\n");
	}
}

int main(void)
{
	char do_this;
	char first[20],last[20];
	int num1=0;
	int num2=0;
	int num3=0;
	int num4=0;
	int num5=0;
	int num_of_nodes=0;
	int m, x, o;
	int count=0;
	int add_count=0;
	int temp[5];
	FILE* file1;
	file1 = fopen("hw8data.txt", "r");
	
	while(1) {
		if(feof(file1)) 
			break;
		fscanf(file1,"%c %s %s %d %d %d %d %d %d", &do_this, first, last, &num_of_nodes, &num1, &num2, &num3, &num4, &num5);
		//set individual values
		temp[0]=num1;
		temp[1]=num2;
		temp[2]=num3;
		temp[3]=num4;
		temp[4]=num5;
		if(do_this=='I'){
			add_count = add_count +1;
			for(x=0; x<5; x++) 
				add(first, last, temp[x], add_count);	
			//resets values for next batch
			num1=0;
			num2=0;
			num3=0;
			num4=0;
			num5=0;
		}
		if(do_this=='R')		
			delete(first, last, count);	
		if(do_this=='Q')		
			break;		
		count = count+1;
	}
	for(o=0; o<10; o++) 
		printme(o);
}
/*This code was written by Lindsey Wingate*/
