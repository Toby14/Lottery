#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_myName(char *first, char *last)
{
	printf("Your name is: %s %s\n", first, last);
}


int main(void)
{
	int name_size;
	char *first_name;
	char *last_name;
	
	
	printf("How many letter of your first name?\n");
	scanf("%d", &name_size);
	
	first_name = malloc(sizeof(char) * (name_size + 1));
	printf("Enter your first name: \n");
	scanf("%s", first_name);
	
	printf("How many letter of your last name?\n");
	scanf("%d", &name_size);
	
	last_name = malloc(sizeof(char) * (name_size + 1));
	printf("Enter your last name: \n");
	scanf("%s", last_name);
	
	print_myName(first_name, last_name);
	
	return 0;
}
