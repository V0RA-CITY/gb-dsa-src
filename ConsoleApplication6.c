#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include <math.h>


void BubbleSort(int Arr[3][3])
{
	for (int i = 0; i < 9; i++)
	{
		for (int i = 0; i < 3; i++)
		{


			for (int j = 0; j < 2; j++)
			{
				if (Arr[i][j] > Arr[i][j + 1])
				{
					int t = Arr[i][j];
					Arr[i][j] = Arr[i][j + 1];
					Arr[i][j + 1] = t;
				}
			}

			if (i < 2)
			{
				if (Arr[i][2] > Arr[i + 1][0])
				{
					int t = Arr[i][2];
					Arr[i][2] = Arr[i + 1][0];
					Arr[i + 1][0] = t;
				}
			}

		}
	}
		
	
		
		
	
	
}

void print(int Arr[][3])
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			printf("%i", Arr[i][j]);
		}
		printf("\n");
	}
}

void TPK()
{
	int Arr[11] ;
	printf("%s", "Введите 11 чисел: ");
	
	for (int i = 0; i < 11; i++)
	{
		int t;
		scanf("%i", &t);
		Arr[i] = t;
	}

	int left = 0;
	int right = 10;

	while (left < 6)
	{
		int temp = Arr[left];
		Arr[left] = Arr[right];
		Arr[right] = temp;
		left++;
		right--;
	}

	for (int i = 0; i < 11; i++)
	{
		Arr[i] = sqrt(fabs(Arr[i])) + 5 * pow(Arr[i], 3);

		if (Arr[i] > 400)
		{
			printf("%s%i%s\n", "Результат элемента ", i ," превысил 400");
		}
	}
}

int main()
{
	setlocale(LC_ALL, "Rus");

	int Arr[3][3] = {{1,9,2},
					{5, 7, 6},
					{4, 3, 8}};

	BubbleSort(Arr);
	print(Arr);
	TPK();
}
