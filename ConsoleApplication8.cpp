#include <iostream>
#include <cstdint>
#include <math.h>

using namespace std;

class Power
{
public:
	Power()
	{
		a = 0;
		b = 0;
	};

	~Power()
	{

	};

	void Set(float _a, float _b)
	{
		a = _a;
		b = _b;
	};

	int Calculate()
	{
		return pow(a, b);
	}

private:
	float a;
	float b;

};



class RGBA
{
public:
	RGBA(uint8_t _m_green = 0, uint8_t _m_red = 0, uint8_t _m_blue = 0, uint8_t _m_alpha = 255) : m_green(_m_green), m_red(_m_red), m_blue(_m_blue), m_alpha(_m_alpha)
	{

	};
	~RGBA()
	{

	};

	void print()
	{
		cout << "Green:" << m_green <<" " << "Red:" << m_red << " " << "Blue:" << m_blue << " " << "Alpha:" << m_alpha << endl;
	};
private:
	uint8_t m_green;
	uint8_t m_red;
	uint8_t m_blue;
	uint8_t m_alpha;
};

class Stack
{
public:
	Stack();
	~Stack();
	
	void reset()
	{
		Arr[10] = NULL;
		size = 0;
	}

	bool push(int value)
	{
		if (size < 10)
		{
			Arr[size] = value;
			size++;
			return true;
		}
		else
		{
			return false;
		}
	}

	int pop()
	{
		if (size == 0)
		{
			cout << "Warning Stack is empty" << endl;
		}
		else
		{
			Arr[size - 1] = NULL;
			size--;
			return Arr[size - 1];
			
		}
	}

	void print()
	{
		cout << '(';
		for (int i = 0; i < size; i++)
		{
			cout << Arr[i];
		}
		cout << ')';
	}

private:
	int Arr[10];
	int size;
};

Stack::Stack()
{
}

Stack::~Stack()
{
}

int main()
{
	Power test;
	test.Set(2.5, 3.79);
	cout << test.Calculate() << endl;

	RGBA test2;
	test2.print();
	
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();
}

