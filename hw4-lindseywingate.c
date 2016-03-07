/* This code was written by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* vector_class(char*, int);
int SIZE = 0;
int main()
{
	char *str;
	str = (char *) malloc(15);
	char c;
	int count;
	printf("Please enter a character. Press enter twice to quit: ");
	while(1) {
		if(c =='\n')
			break;
		c = getchar();
		getchar();
		str[count] = c;
		count++;
		if(count>(sizeof(str))) {
			str = (char *) realloc(str, count+10);
		}	
	}
	for(int a=0; a<count; a++)
		printf("%c", str[a]);

	free(str);
	return(0);	
}

/* This code was written by Lindsey Wingate*/
