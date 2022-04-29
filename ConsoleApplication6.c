#include <stdio.h>

void transformation(int x) {
	if (x > 0) {
		printf("%i", x % 2);
		transformation(x / 2);
	}
		
}

void exponentiation(int a, int b) {
	int sum = a;
	if (a > 1 && b >= 1)
	{
		for (int i = 1; i < b; i++)
		{
			sum = a * sum;
		}
		printf("\n%i", sum);
	}
	else if (a == 0)
	{
		printf("\n%i", 0);
	}
	else if (b == 0)
	{
		printf("\n%i", 1);
	}else 
		printf("\n%i", 1);
	
	
}
	
int RecursiveExponentiation(int a, int b) {
	
	if (a == 0)
		return 0;
	if (b == 0)
		return 1;
	if (a == 1)
		return 1;
	if (a > 1 && b >= 1)
	{
		int sum = 0;
		sum = a * RecursiveExponentiation(a, b - 1);
		return sum;
	}
	

	
}

int RecursiveExponentiationAlter(int a, int b) {

	if (a == 0)
		return 0;
	if (b == 0)
		return 1;
	if (a == 1)
		return 1;
	if (a > 1 && b >= 1  && b % 2 == 1)
	{
		int sum = 0;
		sum = a * RecursiveExponentiation(a, b - 1);
		return sum;
	}

	if (a > 1 && b >= 1 && b % 2 == 0)
	{
		int sum = 0;
		sum = a * RecursiveExponentiation(a, b / 2);
		return sum;
	}


}

int routes(int x, int y) {
	if (x == 0 && y == 0)
		return 0;
	else if (x == 0 ^ y == 0)
		return 1;
	if (x == 3 && y == 2)
		return routes(x - 1, y -1);


	return routes(x, y - 1) + routes(x - 1, y);
}


int main ()
{
	printf("%s", "Read Binary number from right to left\n");
	transformation(12);
	exponentiation(5, 5);
	printf("\n%d", RecursiveExponentiation(5, 5));
	printf("\n%d", RecursiveExponentiationAlter(5, 5));

	const int sizeX = 5;
	const int sizeY = 5;

	printf("\n");
	for (int y = 0; y < sizeY; y++)
	{
		for (int x = 0; x < sizeX; x++)
		{
			printf("%5d", routes(x, y));
		}
		printf("\n");
	}
	
		
}
