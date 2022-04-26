#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void PrimeInt();

int main ()
{
	PrimeInt();
}

void PrimeInt() {
	
	int x = 2;
	int i = 0;
	printf("Hi pleas enter number from 2 till 1000\n");
	int a = 4;
	scanf("%d", &a);

	while (a >= x)
	{
		if (a % x == 0)
		{
			i++;
			x++;
		}
		else 
		{
			x++;
		}
	}

	if (i == 1)
	{
		printf("is prime number");
	}
	else
	{
		printf("is not prime number");
	}
	
}