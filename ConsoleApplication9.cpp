#include <iostream>
#include <string>

using namespace std;

int Count = 0;

class Person
{
public:
	Person();
	~Person();
	void set_Age(int value)
	{
		age = value;
	}
	void set_Weight(int value)
	{
		weight = value;
	}
	void set_Name(string value)
	{
		name = value;
	}
	void set_Gender(char value)
	{
		gender = value;
	}


	int get_Age()
	{
		return age;
	}
	int get_Weight()
	{
		return weight;
	}
	char get_Gender()
	{
		return gender;
	}
	string get_Name()
	{
		return name;
	}

private:
	string name = "Ivan";
	int age = 18;
	char gender = 'm';
	int weight = 50;
};

Person::Person()
{
}

Person::~Person()
{
}


class Student : public Person
{
public:
	Student()
	{
		Count++;
	};
	~Student()
	{
		Count--;
	};

	int get_Year()
	{
		return year;
	}

	void set_Year(int value)
	{
		year = value;
	}

	void plus_Year()
	{
		year++;
	}
private:
	int year = 1;
	
};

 class Fruit
{
public:
	Fruit(){};
	~Fruit(){};

	virtual string get_Name()
	{
		return name;
	}

	 virtual string get_Color()
	{
		return color;
	}

private:
	string color;
	string name;

};

class Banana : public Fruit
{
public:
	Banana(){};
	~Banana(){};

	string get_Name()
	{
		return name;
	}

	string get_Color()
	{
		return color;
	}

private:
	string color = "yellow";
	string name = "banana";

};

class Apple : public Fruit
{
public:
	Apple() {};
	Apple( string _color)
	{
		color = _color;
	};
	~Apple(){};

	string get_Name()
	{
		return name;
	}

	string get_Color()
	{
		return color;
	}
	

private:
	string color = "";
	string name = "apple";

};

class GrannySmith : public Apple
{
public:
	GrannySmith() {};
	~GrannySmith(){};

	 string get_Name()
	{
		return name;
	}

	 string get_Color()
	{
		return color;
	}

private:
	string color = "green";
	string name = "GrannySmith";
	
};

int main()
{
	Student P1,P2,P3;
	P2.set_Age(25);
	P1.set_Weight(65);
	P3.plus_Year();
    cout << P1.get_Age() << " " << P1.get_Gender() << " " << P1.get_Name() << " " << P1.get_Weight() << " " << P1.get_Year() << endl;
	cout << P2.get_Age() <<  " " << P2.get_Gender() << " " << P2.get_Name() << " " << P2.get_Weight() << " " << P2.get_Year() << " " << endl;
	cout << P3.get_Age()  << " " << P3.get_Gender()  << " " << P3.get_Name() << " " << P3.get_Weight()  << " " << P3.get_Year() << endl;


	Apple a("red");
	Banana b;
	GrannySmith c;
	
	cout << "My " << a.get_Name() << " is " << a.get_Color() << endl;
	cout << "My " << b.get_Name() << " is " << b.get_Color() << endl;
	cout << "My " << c.get_Name() << " is " << c.get_Color() << endl;
}


