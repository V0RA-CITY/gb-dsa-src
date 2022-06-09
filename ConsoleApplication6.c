#define _CRT_SECURE_NO_WARNINGS
#define true 1==1
#define false 1!=1
#define SZ 1000
#define size 27
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

char Alphabet[size] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z', ' '};

int FindPosition(char value)
{
	int i = 0;

	while (Alphabet[i] != value)
	{
		i++;
	}

	return i;
}

void CaesarCipher(char str[SZ], int key)
{
	 int i = 0;
	 while (str[i] != 0)
	 {
		 if (FindPosition(str[i]) + key >= size - 1)
		 {
			 str[i] = Alphabet[FindPosition(str[i])];
		 }
		 else
		 {
			 str[i] = Alphabet[FindPosition(str[i]) + key];
		 }
		 
		 i++;
	 }
		
	 printf("%s", str);
}

void CaesarDecipher(char str[SZ], int key)
 {
	 int i = 0;
	 while (str[i] != 0)
	 {
		 if (FindPosition(str[i]) + key >= size - 1)
		 {
			 str[i] = Alphabet[FindPosition(str[i])];
		 }
		 else
		 {
			 str[i] = Alphabet[FindPosition(str[i]) - key];
		 }
		 
		 i++;
	 }

	 printf("%s", str);
 }

void Cipher(char str[SZ], char arr[SZ][SZ], int key)
 {
	int counter = 0;
	for (int i = 0; i < key; i++)
	{
		for (int j = 0; j < key; j++)
		{
			arr[i][j] = str[counter];
			counter++;
		}
		
	}

		for (int g = 0; g < key; g++)
		{
			char tmp = arr[0][g];
			arr[0][g] = arr[0 + 1][g];
			arr[0 + 1][g] = tmp;
		}

		if (key >= 4)
		{
			for (int g = 0; g < key; g++)
			{
				char tmp = arr[2 + 1][g];
				arr[2 + 1][g] = arr[2][g];
				arr[2][g] = tmp;
			}
		}

	for (int k = 0; k < key; k++)
	{
		for (int g = 0; g < key; g++)
		{
			printf("%c", arr[g][k]);
		}
	}
 }

void DeCipher(char str[SZ], char arr[SZ][SZ] , int key)
{

		for (int g = 0; g < key; g++)
		{
			char tmp = arr[0 + 1][g];
			arr[0 + 1][g] = arr[0][g];
			arr[0][g] = tmp;
		}

		if (key >= 4)
		{
			for (int g = 0; g < key; g++)
			{
				char tmp = arr[2 + 1][g];
				arr[2 + 1][g] = arr[2][g];
				arr[2][g] = tmp;
			}
		}

	for (int k = 0; k < key; k++)
	{
		for (int g = 0; g < key; g++)
		{
			printf("%c", arr[k][g]);
		}
	}
}

void main()
{
	char str[SZ] = { 0 };
	char arr[SZ][SZ] = { 0 };
	printf("Enter message uppercase :");
	fgets(str, SZ, stdin);
	CaesarCipher(str, 1);
	printf("\n");
	CaesarDecipher(str, 1);
	printf("\n");
	Cipher(str, arr ,6);
	printf("\n");
	DeCipher(str, arr, 6);
}
