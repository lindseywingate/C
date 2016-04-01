#include <stdio.h>
int main()
{
	int a = 10;
	int *p;
	p = &a;
	*p = 5;	
	printf("%d\n", a);
	return 0;

}
