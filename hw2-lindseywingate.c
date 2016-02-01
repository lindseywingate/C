#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

struct
	{
		char name[15];
		float f;
		int i;
		char desc[15];
	}a,hw_data[101];

int main()
{
	int selection= 1;
	while (selection!=5)
	{
		printf("1. Sort data by the float value & print high to low\n2.Sort data by the float value & print low to high\n3.Sort data by the int value & print high to low\n4. Sort data by the int value & print low to high\n5. Exit\n");
		scanf("%d", &selection);
		int sort_by, sort_by2, count;
		count = setup();
		if (selection==1) {
			sort_float(count);
			printme2(count);
		}
		if (selection==2) {
			sort_float(count);
			printme(count);
		}
		if (selection==3) {
			sort_int(count);
			printme2(count);
		}
		if (selection==4) {
			sort_int(count);
			printme(count);
		}	
		if (selection==5) {
			break;
		}
	}
	return 0;
}

/*opens file, stores hw_data in array. assumed no more than 100 entries*/
int setup( )
{
	FILE*hw; /*hw pointer allows program keep track of file being accessed*/
	/*read each line into struct*/
	int size = 101, n, count = 0, x;
	char str[size];

	hw = fopen("hw2.data", "r");
	while(fscanf(hw, "%s %f %d %s", hw_data[count].name, &hw_data[count].f, &hw_data[count].i, hw_data[count].desc)>=1){
		count++;	
	}
	fclose(hw);
	return count;
}

int printme2(int count)
{
	int test = count;
	while(test>=0) {
		if(hw_data[test].i!=0){
			printf("%s %f %d %s\n", hw_data[test].name, hw_data[test].f, hw_data[test].i, hw_data[test].desc);
		}
		test--;
	}
	return 0;
}
int printme(int count)
{
	int test = 0;
	while(test<count) {
		if(hw_data[test].i!=0){
			printf("%s %f %d %s\n", hw_data[test].name, hw_data[test].f, hw_data[test].i, hw_data[test].desc);
		}
		test++;
	}
	return 0;
}

int sort_int(int count)
{
	char s_temp[15];
	float f_temp;
	int i_temp;
	int i=0, j=i+1, test=0;
	
	while(i<count){
		j=i+1;
		while(j<count){
			if(hw_data[i].i>hw_data[j].i){
				/*reassign name*/
				strcpy(s_temp, hw_data[i].name);
				strcpy(hw_data[i].name, hw_data[j].name);
				strcpy(hw_data[j].name, s_temp);

				/*reassign float*/
				f_temp = hw_data[i].f;
				hw_data[i].f = hw_data[j].f;
				hw_data[j].f = f_temp;

				/*reassign int*/
				i_temp = hw_data[i].i;
				hw_data[i].i = hw_data[j].i;
				hw_data[j].i = i_temp;

				/*reassign desc*/
				strcpy(s_temp,hw_data[i].desc);
				strcpy(hw_data[i].desc,hw_data[j].desc);
				strcpy(hw_data[j].desc, s_temp);
			}
			j++;
		}
		i++;
	}
}

int sort_float(int count)
{
	char s_temp[15];
	float f_temp;
	int i_temp;
	int i=0, j=i+1, test=0;
	
	while(i<count){
		j=i+1;
		while(j<count){
			if(hw_data[i].f>hw_data[j].f){
				/*reassign name*/
				strcpy(s_temp, hw_data[i].name);
				strcpy(hw_data[i].name, hw_data[j].name);
				strcpy(hw_data[j].name, s_temp);
				/*reassign float*/
				f_temp = hw_data[i].f;
				hw_data[i].f = hw_data[j].f;
				hw_data[j].f = f_temp;
				/*reassign int*/
				i_temp = hw_data[i].i;
				hw_data[i].i = hw_data[j].i;
				hw_data[j].i = i_temp;
				/*reassign desc*/
				strcpy(s_temp,hw_data[i].desc);
				strcpy(hw_data[i].desc,hw_data[j].desc);
				strcpy(hw_data[j].desc, s_temp);
			}
			j++;
		}
		i++;
	}
}
