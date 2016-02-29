/* This code was written by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* vector_class(char);

int main()
{
	
	char c="a";
	do {
	printf("Please enter a letter. Press enter to quit: ");
	//if enter pressed, pass \0 to array, indicating string needs to be created and appended to HW 4 input: and then printed 
	c = getchar();
	//putchar(c);
	getchar();
	printf("\n");
	char* array_spot = vector_class(c);
	vector_class(c);

	}
	while(isalpha(c)!=0);
	
		return(0);	
}

char* vector_class(char var)
{
	int count = 0;
	char* array = (char *)malloc(5);		
	array[count] = var;
	printf("%c var: \n", var);
	count = count+1;
//must use malloc/calloc to adjust array size- can be done in chunks of 5 or 10
//read about memcpy
//return pointer to array to main
	free(array);
	return(array);
}

/* This code was written by Lindsey Wingate*/


