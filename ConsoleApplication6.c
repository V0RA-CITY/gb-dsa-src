#define _CRT_SECURE_NO_WARNINGS
#define true 1==1
#define false 1!=1
#define n 6
#define SZ 1000
#define SIZE 10
#define T int
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>



int hashF (char data[SZ])
{
	int tmp = 0;

	for (int i = 0; i < SZ; i++)
	{
		tmp += (int)data[i];
	}

	return tmp;
}

void sumAlgo()
{
	int result = 0;
	int a = 50;
	int b = 10;
	int c = 5;
	int d = 2;
	int e = 1;
	
	while (result != 98)
	{
		

		if (result + a > 98)
		{
			result += b;
		}
		else
		{
			result += a;
		}
		if (result + b > 98)
		{
			result += c;
		}
		if (result + c > 98)
		{
			result += d;
		}
		if (result + d > 98)
		{
			result += e;
		}
	}
	printf("%i", result);
}

void main()
{
	char str[SZ] = {0};
	printf("%s", "Enter string :");
	scanf("%s", &str);
	hashF(str);
	sumAlgo();
}
