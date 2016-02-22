/*This code was written by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//hints: no word > 50, determine file size first, create single dynamic array, write results to words.txt, man 3 malloc or calloc, man 3 strcmp and strcpy, man 3 feof
int main()
{
	FILE*file1;
	FILE*file2;
	FILE*file3;
	
	char *trash;
	char *trash2;
	char *trash3;
	char line[50];

	int count=0;
	int count2=0;
	int count3=0;
	int size, y, i, j;
	
	char *data;
	char **array;	
	char t[50];

	file1 = fopen("american0.txt", "r");
	while(1) {
		if (feof(file1)) {
			break;
		}
		fscanf(file1, "%s", &trash);
		count++;
	}
//	printf("%d\n",count);
	rewind(file1);
	//return count;

	file2 = fopen("american1.txt", "r");
	while(1) {
		if (feof(file2)) {
			break;
		}
		fscanf(file2, "%s", &trash2);
		count2++;
	}
//	printf("%d\n", count2);
	rewind(file2);
	
	file3 = fopen("american2.txt", "r");
	while(1) {
		if (feof(file3)) {
			break;
		}
		fscanf(file3, "%s", &trash3);
		count3++;
	}
//	printf("%d\n",count3);
	rewind(file3);

	size = count+count2+count3;
//	printf("%d\n", size);

	//column of pointers	
	array = (char **)calloc(size+1, sizeof(*array));//size of pointer
	//char ** casts into pointer you want
	for (y=0; y<size; y++) {
		//row of bytes
		array[y] = (char *)calloc(51, sizeof(char));
	}

	//printf("%d\n", size);

	for(i=0; i<count; i++) {
		fscanf(file1, "%s", array[i]);
	}
	
	for(i=count; i<count+count2; i++) {
		fscanf(file2, "%s", array[i]);
	}

	for(i=count+count2; i<count+count2+count3; i++) {
		fscanf(file3, "%s", array[i]);
	}

		free(array);

	for(i=1; i<size; i++) {
		for (j=1; j<size; j++) {
			if(strcmp(array[j-1], array[j]) > 0) {
				strcpy(t, array[j-1]);
				strcpy(array[j-1],array[j]);
				strcpy(array[j], t);
			}	
		}
	}

	FILE *words = fopen("words.txt", "w");
	for(int b=0; b<size; b++) {
		printf("%s\n", array[b]);
		fprintf(words, "%s\n", array[b]);
	}
	fclose(words);	
	fclose(file1);
	fclose(file2);
	fclose(file3);
	
	return 0;
}

	/*This code was written by Lindsey Wingate*/
