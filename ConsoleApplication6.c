#define _CRT_SECURE_NO_WARNINGS
#define SIZE 10
#define SZ 1000
#define T char
#define true 1==1
#define false 1!=1
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>

typedef int boolean;

typedef struct Node
{
	int dat;
	struct Node *next;

} Node;

typedef struct
{
	Node *head;
	int size;

}list;



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

boolean sequence()
{
	int prev;
	char str[SZ];
	printf("Write sequence :");
	scanf("%s", &str);

	for (int i = 0; i < SZ; i++)
	{
		if (str[i] == '(' || str[i] == '[' || str[i] == '{')
		{
			push(str[i]);
		}

		if (str[i] == ')' || str[i] == ']' || str[i] == '}')
		{
			if (cursor == -1)
			{
				return false;
			}

			for (int j = 0; j <= cursor; j++)
			{
				if ((int)Stack[j] == (int)(str[i] - 1) || (int)Stack[j] == (int)(str[i] - 2))
				{
					pop();
					continue;
				}
			}
		}
	}

	if (cursor == -1)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void initList (list* lst)
{
	lst->head = NULL;
	lst->size = 0;
}

void ListPush(list* lst, int value)
{
	Node* new = (Node*)malloc(sizeof(Node));
	new->dat = value;
	new->next = NULL;

	Node* current = lst->head;

	if (current == NULL)
	{
		lst->head = new;
		lst->size++;
		return;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
		}
		current->next = new;
		lst->size++;
	}
}

Node* ListPop(list* lst)
{
	Node* current = lst->head;

	if (current == NULL)
	{
		printf("List is empty");
	}
	else
	{
		lst->head = current->next;
		lst->size--;
		return current;
	}
}

void NodePrint(Node* n)
{
	if (n == NULL)
	{
		printf("[]");
	}
	else
	{
		printf("[%i]", n->dat);
	}
}

void ListPrint(list* lst)
{
	Node* current = lst->head;
	if (current == NULL)
	{
		printf("List is empty");
	}
	else
	{
		while (current != NULL)
		{
			NodePrint(current);
			current = current->next;
			
		}
	}
}

list* ListCopy(list* lst)
{
	Node* current1 = lst->head;
	list* lstCopy = (list*)malloc(sizeof(list));
	initList(lstCopy);

	if (current1 == NULL)
	{
		printf("Nothing to copy");
	}
	else
	{
		while (current1 != NULL)
		{
			ListPush(lstCopy, current1->dat);
			current1 = current1->next;
		}
	}
	
	return lstCopy;
}

boolean SortDetect(list* lst)
{
	Node* current = lst->head;
	int counter = 0;
	int counter2 = 0;
	if (current == NULL)
	{
		printf("%s", "List is empty");
	}
	else
	{
		while (current->next != NULL)
		{
			if (current->dat < current->next->dat)
			{
				counter++;
			}
			else if (current->dat > current->next->dat)
			{
				counter2++;
			}
			current = current->next;
		}
	}

	if (counter == (lst->size - 1) || counter2 == (lst->size - 1))
	{
		return true;
	}
	else
	{
		return false;
	}

	
}

int main()
{
	list* lst = (list*)malloc(sizeof(list));
	printf("%i", sequence());
	
	printf("\n");
	initList(lst);
	ListPush(lst, 30);
	ListPush(lst, 20);
	ListPush(lst, 10);
	ListPrint(lst);
	printf("\n");
	ListPrint(ListCopy(lst));
	printf("\n");
	ListPrint(lst);
	printf("\n");
	printf("%i", SortDetect(lst));
}
