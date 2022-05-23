#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#define SZ 1000
#define T int
#define true 1==1
#define false 1!=1
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>

typedef int boolean;



int cursor = -1;
T Stack[SZ];

boolean push(T data) {
	if (cursor < SZ)
	{
		Stack[++cursor] = data;
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
		return Stack[cursor--];
	}
	else {
		printf("%s", "Stack is empty");
		return -1;
	}
}

int DecimalToBinary(int a) {

	while (a > 0)
	{
		push(a % 2);
		a = a / 2;
	}

	while (cursor != -1)
	{
		printf("%i", pop());
	}

}
////////////////////////////////////////////////////////////////////////

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

	Node* node = (Node*) malloc(sizeof(Node));
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

			if (idx < Arr[i+1]->pr)
			{
				idx = Arr[i+1]->pr;
				t = i+1;
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

void printQ() {
	printf("[ ");
	for (int i = 0; i < SIZE; i++)
	{
		if (Arr[i] == NULL)
		{
			printf("[*, *]");
		}
		else
		{
			printf("[%d, %d] ", Arr[i]->pr, Arr[i]->dat);
		}
	}
	printf(" ]\n");
}

int main()
{
	init();
	ins(1, 11);
	ins(3, 22);
	ins(4, 31);
	ins(2, 44);
	ins(5, 111);
	ins(8, 112);
	ins(19, 211);
	ins(6, 115);
	ins(9, 121);
	ins(2, 160);
	printQ();
	rem();
	rem();
	rem();
	rem();
	printQ();

	DecimalToBinary(10);

	

}
