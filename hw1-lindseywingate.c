/*This code was written by Lindsey Wingate*/
#include <stdio.h>

int get_payment()
{
	int check;
	printf("Please enter your monthly payment: \n");
	scanf("%d", &check);
	return check;
}

int main() 
{
	int payment = get_payment();	
	float annual_interest = .22;
	int total = 5000;
	float first_month = annual_interest/12*total;
/*	float other_months = rate/12*(total-payment+n)*/
	printf("Monthly Payment: %d\n", payment);
	printf("Interest Rate: %f\n", annual_interest); 	
	printf("Total Cost: %d\n", total);
	printf("First Month Interest Rate: %f\n", first_month);

	while (total>=0) 
	{
		total = total - 100;
		printf("Just loopin it");
	}	


return 0;
}


