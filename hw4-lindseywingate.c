/* This code was written by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* vector_class(char*, int);
int SIZE = 0;
int main()
{
	int count = 0;
	char array[5];
	char c;
	char* p;
	printf("Please enter a character. Press enter twice to quit: ");
	while(1) {
		if(c =='\n')
			break;
		//two getchar()s in a row get rid of extra characters (ex: \n)
		c = getchar();
		getchar();
		p = &array[count];
		array[count] = c;
		count++;
		//printf("size of array: %lu", sizeof(array));	
		if(count==(sizeof(array)-1)) 
			vector_class(p, count);
	
	}
//	free(p);
	return(0);	
}

char* vector_class(char* p, int count)
{
	printf("%d",count);
	printf("does it even get here?");
	char* new_array = (char*)calloc(count+1, sizeof(char));
	printf("size of new_array: %lu", sizeof(new_array));
	return(p2);
}

/* This code was written by Lindsey Wingate*/
