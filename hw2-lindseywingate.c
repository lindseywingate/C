/*This code was written by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h> 

struct hw_data
{
	char name;
	float f;
	int i;
	char desc;
}

/*Main allows the selection of 1-4 items. Does not exit menu until 5 is selected*/
int main()
{
	int selection= 1;
	struct hw_data data[];

	while (selection!=5)
	{
		printf("1. Sort hw_data by the float value & print high to low\n2.Sort hw_data by the float value & print low to high\n3.Sort hw_data by the int value & print high to low\n4. Sort hw_data by the int value & print low to high\n5. Exit\n");
		scanf("%d", &selection);
	/*	printf("%d", selection);*/
		
		if (selection==1)
		{
			printf("test1");
			openfile(data[]);
		}
		if (selection==2)
		{
			printf("test2");
			openfile(data[]);	
		}
		if (selection==3)
		{
			printf("test3");
			openfile(data[]);
		}
		if (selection==4)
		{
			printf("test4");
			openfile(data[]);
		}	
		if (selection==5)
		{
			break;
		}
	}
	return 0;
}

/*opens file, stores hw_data in array. assumed no more than 100 entries*/
int open_file(data[])
{
	FILE*hw; /*file pointer allows program keep track of file being accessed*/
	hw = *fopen("hw2.hw_data", "r");
	
	if (hw!=null)
	{
		char buffer[32];
		while(!feof(hw))
		{
			fread(buffer, sizeof(char), sizeof(buffer), hw)
		}
	}

	int fclose(hw);
	free(hw);/*frees up space allocated by malloc*/
	return 0;
}
/*This code was written by Lindsey Wingate*/
