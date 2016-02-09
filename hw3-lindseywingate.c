/*This code was written by Lindsey Wingate*/
#include <stdio.h>
#include <stdlib.h>

//hints: no word > 50, determine file size first, create single dynamic array, write results to words.txt, man 3 malloc or calloc, man 3 strcmp and strcpy, man 3 feof
int main()
{
	FILE*file1;
	FILE*file2;
	char line[50];
	FILE*file3;
//	int i;
	int count=0;
	int count2=0;
	int count3=0;
	int size;
	char* pnt;
//	
//	pnt = calloc(50, sizeof(char[50]);

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

	//creates dynamic array
	pnt = calloc(size, 50);

	//opens files and adds contents to array
	file1 = fopen("american0.txt", "r");
	while(fgets(line, "%s", file1)!=NULL){	
		printf("%s", line);
	}
	fclose(file1);

	file2 = fopen("american1.txt", "r");
	while(fgets(line, "%s", file2)) {
		printf("%s", line);
	}
	
	file3 = fopen("american2.txt", "r");
	while(fgets(line, "%s", file3)) {
		printf("%s", line);
	}	
	
	free(pnt);
	
	return 0;
}

	/*This code was written by Lindsey Wingate*/
