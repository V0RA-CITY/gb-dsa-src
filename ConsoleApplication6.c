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

typedef int boolean;

int cursor = -1;
boolean Visited[n] = {0};

boolean push(T data) {
	if (cursor < SZ)
	{
		Visited[++cursor] = data;
		return true;
	}
	else
	{
		printf("%s", "Stack overflow");
		return false;
	}
}

T pop() {
	if (cursor != -1)
	{
		return Visited[cursor--];
	}
	else {
		printf("%s", "Stack is empty");
		return -1;
	}
}

typedef struct {
	int pr;
	int dat;
} Node;

Node* Arr[SIZE];
int head;
int tail;
int items;

void init()
{
	for (int i = 0; i < SIZE; i++)
	{
		Arr[i] = NULL;
	}

	head = 0;
	tail = 0;
	items = 0;
}

void ins(int pr, int dat) {

	Node* node = (Node*)malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;
	int flag;

	if (items == 0)
	{
		Arr[tail++] = node;
		items++;
	}
	else if (items == SIZE)
	{
		printf("%s \n", "Queue is full");
		return;
	}
	else
	{
		int i = items;
		int idx = 0;
		Node* tmp;

		while (Arr[i] != NULL)
		{
			i++;
		}

		Arr[i] = node;
		tail++;
		items++;
	}

}

Node* rem() {



	if (items == 0)
	{
		return NULL;
	}
	else {
		int idx = Arr[head]->pr;
		int t;

		for (int i = 0; i < items; i++)
		{
			if (Arr[i + 1] == NULL || Arr[i] == NULL)
			{
				i++;
				continue;
			}

			if (idx < Arr[i + 1]->pr)
			{
				idx = Arr[i + 1]->pr;
				t = i + 1;
			}


		}

		while (Arr[tail] == NULL && Arr[tail] != Arr[head])
		{
			tail--;
		}

		Node* tmp = Arr[t];

		Arr[t] = Arr[tail];
		Arr[tail] = tmp;

		Arr[tail] = NULL;

		tail--;
		items--;
		return tmp;
	}

}


int matrix[n][n] = {
	{0,1,1,0,0,0},
	{0,0,0,1,1,1},
	{0,0,0,0,0,1},
	{1,0,0,0,0,0},
	{0,0,0,0,0,0},
	{0,0,0,0,1,0},
};

void depthTravers(int st)
{
	int r;
	printf("%d ", st);
	init();
	push(true);
	
	for ( r = 0; r <= n; r++)
	{
		if (matrix[st][r] == 1 && !Visited[r])
		{
			depthTravers(r);
		}
	}

}

void main()
{
	depthTravers(0);
	
}
