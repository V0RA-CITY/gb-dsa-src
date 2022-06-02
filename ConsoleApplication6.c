#define _CRT_SECURE_NO_WARNINGS
#define true 1==1
#define false 1!=1
#include <stdio.h>
#include <locale.h>
#include <math.h>
#include <malloc.h>
#include <stdlib.h>

typedef int boolean;
typedef struct Node
{
	int key;
	struct Node* left;
	struct Node* right;
} TreeNode;

int counter1 = 0;
int counter2 = 0;

TreeNode* treeInsert(TreeNode* t, int data)
{
	TreeNode* newNode;
	newNode = (TreeNode*)malloc(sizeof(TreeNode));
	newNode->key = data;
	newNode->left = NULL;
	newNode->right = NULL;
	TreeNode* current = t;
	TreeNode* parent = t;

	if (t == NULL)
	{
		t = newNode;
	}
	else
	{
		while (current->key != data)
		{
			parent = current;
			if (current->key > data)
			{
				current = current->left;
				if (current == NULL)
				{
					parent->left = newNode;
					return t;
				}
			}
			else
			{
				current = current->right;
				if (current == NULL)
				{
					parent->right = newNode;
					return t;
				}
			}
		}
	}
	return t;
}

void printTree(TreeNode* root)
{
	if (root)
	{
		printf("%i", root->key);
		if (root->left || root->right)
		{
			printf("(");
			if (root->left)
			{
				printTree(root->left);
			}
			else
			{
				printf("NULL");
			}
			printf(",");
			if (root->right)
			{
				printTree(root->right);
			}
			else
			{
				printf("NULL");
			}
			printf(")");
		}
	}
}

TreeNode* getSuccessor(TreeNode* node)
{
	TreeNode* current = node->right;
	TreeNode* parent = node;
	TreeNode* s = node;

	while (current != NULL)
	{
		parent = s;
		s = current;
		current = current->left;
	}
	if (s != node->right)
	{
		parent->left = s->right;
		s->right = node->right;
	}
	return s;
}

boolean delete(TreeNode* root, int key)
{
	TreeNode* current = root;
	TreeNode* parent = root;
	boolean isLeftChild = true;

	while (current->key != key)
	{
		parent = current;
		if (key < current->key)
		{
			current = current->left;
			isLeftChild = true;
		}
		else
		{
			current = current->right;
			isLeftChild = false;
		}
		if (current = NULL)
		{
			return false;
		}
	}

	if (current->left == NULL && current->right == NULL)
	{
		if (current == root)
		{
			root = NULL;
		}
		else if (isLeftChild)
		{
			parent->left = NULL;
		}
		else
		{
			parent->right = NULL;
		}
	}
	else if (current->right == NULL)
	{
		if (isLeftChild)
		{
			parent->left = current->left;
		}
		else
			parent->right = current->left;
	}
	else if (current->left == NULL)
	{
		if (isLeftChild)
		{
			parent->left = current->right;
		}
		else
			parent->right = current->right;
	}
	else
	{
		TreeNode* successor = getSuccessor(current);
		if (current == root)
		{
			root == successor;
		}
		else if (isLeftChild)
		{
			parent->left = successor;
		}
		else
			parent->right = successor;
		successor->left = current->left;
	}
	return true;
}

boolean balanceDetect(TreeNode* root)
{
	if (root == NULL)
	{
		counter1 /= 2;
		counter2 /= 2;
	}

	if (root)
	{
		balanceDetect(root->left);
		balanceDetect(root->right);
		if (root->left)
		{
			counter1++;
		}
		if (root->right)
		{
			counter2++;
		}
	}

	if (counter1 == counter2 || counter1 == counter2 + 1 || counter1 == counter2 - 1)
	{
		return true;
	}
	else
	{
		return false;
	}
	
	
}

double createTrees(int countOfTree, int countOfUnit)
{
	double counter = 0;
	while (countOfTree != 0)
	{
		TreeNode* tree = NULL;
		tree = treeInsert(tree, rand() % 1000 + 1);
		while (countOfUnit != 0)
		{
			treeInsert(tree, rand() % 1000 + 1);
			countOfUnit--;
		}
		if (balanceDetect(tree) == true)
		{
			counter += 1;
		}
		countOfTree--;
		countOfUnit = 1000;
	}
	return  counter / 50.0 * 100.0;

}

boolean binarySearch(TreeNode* root, int data)
{
	if (root == NULL)
	{
		return false;
	}
	if (root->key > data)
	{
		binarySearch(root->left, data);
	}
	else if (root->key < data)
	{
		binarySearch(root->right, data);
	}
	else if (root->key == data)
	{
		return true;
	}
}

boolean main()
{
	TreeNode* tree = NULL;

	tree = treeInsert(tree, 10);
	treeInsert(tree,8);
	treeInsert(tree, 19);
	treeInsert(tree, 5);
	treeInsert(tree, 9);
	treeInsert(tree, 16);
	treeInsert(tree, 21);
	treeInsert(tree, 22);
	printTree(tree);
	printf("\n");
	printf("%s", balanceDetect(tree)? "True": "False");
	printf("\n");
	printf("%i%c", (int)createTrees(50, 1000), '%');
	printf("\n");
	printf("%i", binarySearch(tree, 11));
	
}
