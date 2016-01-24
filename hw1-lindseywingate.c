/*This code was written by Lindsey Wingate*/
#include <stdio.h>

float get_payment()
{
	float check;
	printf("Please enter your monthly payment more than $91: \n");
	scanf("%f", &check);
	return check;
}

int main() 
{
	float payment = get_payment();	
	float annual_interest = .22;
	int total = 5000;
	float first_month = .22/12*total;
	printf("------------\n"); 
	printf("Monthly Payment: %.2f\n", payment);
	printf("Interest Rate: %.2f\n", annual_interest); 	
	printf("Total Cost: %.2d\n", total);

	printf("\n1\t%.2f\t%.2d\n", first_month, total);
	float total_interest = first_month;	
	float owe = total-payment+first_month;
	int n = 1;

	while (owe>0) 
	{
		float interest = .22/12*(owe);
		printf("%d\t%.2f\t%.2f\n",n,interest,owe);
		owe = owe - payment + interest;
		n = n + 1;
		total_interest = total_interest + interest;

		if (owe<=0)
		{
			printf("\nTotal Interest Paid: %.2f\n", total_interest); 
		}
	}	
	

	return 0;
}
/*This code was written by Lindsey Wingate*/
