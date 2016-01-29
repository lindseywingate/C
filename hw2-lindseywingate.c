#include <stdio.h>
#include <stdlib.h> 
#include <string.h>


int main()
{
	int selection= 1;
	while (selection!=5)
	{
		printf("1. Sort hw_data by the float value & print high to low\n2.Sort hw_data by the float value & print low to high\n3.Sort hw_data by the int value & print high to low\n4. Sort hw_data by the int value & print low to high\n5. Exit\n");
		scanf("%d", &selection);
	/*	printf("%d", selection);*/
		
		if (selection==1) {
			open_file();
		}
		if (selection==2) {
			open_file();	
		}
		if (selection==3) {
			open_file();
		}
		if (selection==4) {
			open_file();
		}	
		if (selection==5) {
			break;
		}
	}
	return 0;
}

/*opens file, stores hw_data in array. assumed no more than 100 entries*/
int open_file()
{
	struct data
		{
			char name[42];
			char f[10];
			char i[10];
			char desc[42];
		};
	
	/*defining the structure to store file data*/
	struct data hw_data[200]; /*array of structs*/
	/*struct data *ptr = hw_data; declare pointer*/
	char token[20], token2[20], token3[20], token4[20];
	FILE*hw; /*hw pointer allows program keep track of file being accessed*/
	char line[420];
	int count = 0;
	/*read each line into struct*/
	
	hw = fopen("hw2.data", "r");
	while (!feof(hw)) { /*as i read the file, the pointer continues down each line*/
		fgets(line, 420, hw);
		strcpy(token, strtok(line, " "));
		strcpy(token2, strtok(NULL, " "));
		strcpy(token3, strtok(NULL, " "));
		strcpy(token4, strtok(NULL, " "));
		printf("%s\n", token);
		printf("%s\n", token2);
		printf("%s\n", token3);
		printf("%s\n", token4);
	/*	
		hw_data[count].name = strcpy(*ptr,token);
		hw_data[count].f = strcpy(*ptr, token2);
		hw_data[count].i = strcpy(*ptr, token3);
		hw_data[count].desc = strcpy(*ptr,token4);
	*/	
		/*
		token=strtok(line,s);
		print(token);
		token2=strtok(NULL,s);
		print(token2);
		token3=strtok(NULL,s);
		print(token3);
		token4 = strtok(NULL,s);
		print(token4);
	
		token=strtok(line,s);
		
		while (token!=NULL) {
			printf("%s\n", token);
			token = strtok(NULL, s);
		}*/
		count = count + 1;
		/**ptr++;*/
	}
	fclose(hw);
	return 1;
}
