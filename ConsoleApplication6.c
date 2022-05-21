#define _CRT_SECURE_NO_WARNINGS
#define SIZE 30 // Не знаю почему но работает только черезе define иначе не даёт использовать константу SIZE при объявлении массива
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>

void swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

void initArr(int* Arr, int length)
{
	for (int i = 0; i < length; i++)
	{
		Arr[i] = rand() % 100;
	}
}

void print(int* Arr, int length)
{
	for (int i = 0; i < length; i++)
	{
			printf(" %i", Arr[i]);
	}
}

void Median(int* Arr)

{
	for (int i = 0; i < 3 - 1; i++)
	{
		for (int j = 0; j < 3-1; j++)
		{
			if (Arr[j] > Arr[j+1])
			{
				swap(&Arr[j], &Arr[j+1]);
			}
		}
	}
}

void qSort(int* Arr, int first, int last)
{
	
	int i = first;
	int j = last;
	

	if (last <= 10)
	{
		int temp, pos;

		for (int i = 1; i < last; i++)
		{
			temp = Arr[i];
			pos = i - 1;

			while (pos >= 0 && Arr[pos] > temp)
			{
				Arr[pos + 1] = Arr[pos];
				pos--;
			}
			Arr[pos + 1] = temp;
		}
	}
	else
	{
		int ArrT[3] = { Arr[first], Arr[last], Arr[(first + last) / 2] };
		Median(ArrT);
		int x = ArrT[1];
		do
		{
			while (Arr[i] < x) i++;
			while (Arr[j] > x) j--;

			if (i <= j)
			{
				swap(&Arr[i], &Arr[j]);
				i++;
				j--;
			}


		} while (i <= j);
		if (i < last) qSort(Arr, i, last);
		if (j > first) qSort(Arr, first, j);
	}

	

		
}


int main()
{
	int Arr[SIZE];
	initArr(Arr, SIZE);
	print(Arr, SIZE);
	qSort(Arr, 0, SIZE - 1);
	printf("\n");
	print(Arr, 30);
}
