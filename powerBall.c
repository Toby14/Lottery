#include <stdio.h>
#include <time.h>
#include <stdlib.h>

// @Freakinlovecoding
// 12/30/16
void powerBall(int choice)
{
	printf("==============================\n");
	printf("====  POWER BALL LOTTERY  ====\n");
	printf("==============================\n");
	printf("===  1. Random ticket(s)   ===\n");
	printf("===  2. Pick your numbers  ===\n");
	printf("===  3. For More Details   ===\n");
	printf("=== (-1). Exit the program!  =\n");
	printf("==============================\n");
}

void detail()
{
	printf("--- Pick 5 numbers and 1 powerball number ---\n");
	printf("--- The 5 numbers are in 1-69 range ---------\n");
	printf("--- The powerball number is in 1-26 ---------\n");
	printf("--- GOOD LUCK! ------------------------------\n\n");
}


int* pickNum(int* ticket)
{
	int i, number, powerBall;
	ticket = malloc(sizeof(int));
	for (i = 0; i <= 5; i++)
	{
		if (i == 5)
		{
			printf("Enter a power ball number: ");
			scanf("%d", &powerBall);
			ticket[5] = powerBall;
		}
		else
		{
			printf("Enter a number: ");
			scanf("%d", &number);
			ticket[i] = number;
		}
	}
	return ticket;
}


int randomTicket(int ticket)
{
	int number, count = 1;
	
	srand(time(NULL));
	
	int i, j;
	for (j = 0; j < ticket; j++)
	{

		for (i = 1; i <= 6; i++)
		{			
			if (count < 6)
			{
				printf("%d ", number = rand() % 69 + 1);
				count ++;
			}
		
			else
			{
				printf("|");
				printf(" %d\n", number = rand() % 26 + 1);
				printf("\n");
				count = 1;
			}
		}	
	}

	return ticket;
}

void displayTickets(int ticket)
{
	printf("Printing the ticket(s)...\n");
	printf("Your ticket(s): %d\n", randomTicket(ticket));
	
}


void displayPickNum(int* ticket)
{
	int* pick = malloc(sizeof(int));
	int i, count = 0;
	
	ticket = malloc(sizeof(int));

	pick = pickNum(ticket);
	
	printf("Your ticket(s): \n");
	for (i = 0; i < 6; i++)
	{
		if (i < 5)
		{
			printf("%d ", pick[i]);
			count ++;
		}
		else
		{
			printf("| ");
			printf("%d", pick[5]);
			count = 0;
		}	
	}
	
	printf("\n");
	free(ticket);
	free(pick);
}


int main(void)
{
	int ticket, choice, i, count = 0;
	int* pick = malloc(sizeof(int));
	int* number = malloc(sizeof(int));

	while (choice != -1)
	{
		
		powerBall(choice);
		
		printf("Choose the option: ");
		scanf("%d", &choice);

		// Display your choice
		printf("------------------------------\n");
		printf("You chose %d\n", choice);
		
		switch(choice)
		{
			case 1: 
				printf("How many tickets do you want?\n");
				scanf("%d", &ticket);
				displayTickets(ticket);
				printf("------------------------------\n");
				break;
		
			case 2:
				displayPickNum(pick);
				printf("------------------------------\n");
				break;
				
			case 3:
				detail();
				break;
				
			case -1:
				exit(-2);
		
			default:
				printf("Please choose 1 or 2. Thanks!\n");
				printf("------------------------------\n");
				break;
		}
	
	}

	free(pick);
	free(number);

	return 0;

}



