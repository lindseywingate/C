/*This code was written by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>

//hints: no word > 50, determine file size first, create single dynamic array, write results to words.txt, man 3 malloc or calloc, man 3 strcmp and strcpy, man 3 feof
int main()
{
	FILE*file1;
	FILE*file2;
	FILE*file3;
//	int i;
	int count=0;
	int count2=0;
	int count3=0;
	int counter=0;
	int size;
	char line[50];
//	int size;
	file1 = fopen("american0.txt", "r");
	while(fscanf(file1, "%s", file1[count])>=1){
		count++;
	}
	printf("%d\n",count);
	fclose(file1);
	//return count;

	file2 = fopen("american1.txt", "r");
	while(fgets(line, "%s", file2)) {
		count2++;
	}
	printf("%d\n",count2);	
	
	file3 = fopen("american2.txt", "r");
	while(fgets(line, "%s", file3)) {
		count3++;
	}
	printf("%d\n", count3);

	size = count+count2+count3;
	printf("%d\n", size);

///creating one big array from files
	char* array;
	array = (char*)calloc(size, 50);

	printf("%d", counter);
	file1 = fopen("american0.txt", "r");
	while(fscanf(file1, "%c", &array[counter])>=1) {
		counter++;
	}
	printf("%d", size);
/*	printf("%d", counter);
	fclose(file1);
	file2 = fopen("american1.txt", "r");
	while(fscanf(file2, "%c", &array[counter]>=1)) {
		counter++;	
	}
*/
	for(int i = 0; i<sizeof(array); i++) {
		printf("%c", array[i]);
	}

	return 0;
}

	/*This code was written by Lindsey Wingate*/
