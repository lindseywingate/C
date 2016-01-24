/*This code was written by Lindsey Wingate*/
#include <stdio.h>

/*Main allows the selection of 1-4 items. Does not exit menu until 5 is selected*/
int main()
{
	int selection= 1;
	
	while (selection!=5)
	{
		printf("1. Sort data by the float value & print high to low\n2.Sort data by the float value & print low to high\n3.Sort data by the int value & print high to low\n4. Sort data by the int value & print low to high\n5. Exit\n");
		scanf("%d", &selection);
	/*	printf("%d", selection);*/
		
		if (selection==1)
		{
			printf("test1");
			openfile();
		}
		if (selection==2)
		{
			printf("test2");
			openfile();	
		}
		if (selection==3)
		{
			printf("test3");
			openfile();
		}
		if (selection==4)
		{
			printf("test4");
			openfile();
		}	
		if (selection==5)
		{
			break;
		}
	}
	return 0;
}

/*opens file, stores data in array. assumed no more than 100 entries*/
int open_file()
{
	FILE *fopen(const char *hw2.data, const char *r);
	return 0;
}
/*This code was written by Lindsey Wingate*/
