#include <iostream>

using namespace std;

enum Suit
{
	Daimond,Heart,Club,Spade
};

enum Number
{
	A, K, Q, J,
	T = 10, N = 9, E = 8, S = 7, SI = 6
};

class Figure
{
public:
	Figure(){};
	~Figure(){};

	int virtual area() = 0;

protected:
	int a = 0;
	int b = 0;
	int h = 0;
	int R = 0;
};

class Parallelogram : public Figure
{
public:
	Parallelogram()
	{
		 a = 5;
		 h = 5;
	};
	~Parallelogram(){};

	int area()
	{
		return a * h;
	}

private:
	
};

class Cricle : public Figure
{
public:
	Cricle()
	{
		 R = 15;
	};
	~Cricle(){};

	int area()
	{
		return 3.14 * (R * R);
	}

private:

};

class Rectangle : public Parallelogram
{
public:
	Rectangle()
	{
		a = 7;
		b = 5;
	};
	~Rectangle(){};

	int area()
	{
		return a * b;
	}

private:

};

class Square : public Parallelogram
{
public:
	Square()
	{
		a = 7;
	};
	~Square(){};

	int area()
	{
		return a * a;
	}

private:

};

class Rhombus : public Parallelogram
{
public:
	Rhombus()
	{
		a = 9;
		h = 8;
	};
	~Rhombus(){};

	int area()
	{
		return a * h;
	}

private:

};

///////////////////////////////////////////////////////////////////////////

class  Car
{
public:
	Car(){};
	~Car(){};

protected:
	string company = "Lada";
	string model = "Granta";
};

class PassengerCar : public virtual Car
{
public:
	PassengerCar()
	{
		company = "PassengerCar";
		cout << company << " " << model << endl;
	};
	~PassengerCar(){};

private:

};

class Bus : public virtual Car
{
public:
	Bus()
	{
		company = "bus";
		cout << company << " " << model << endl;
	};
	~Bus(){};

private:

};

class  Minivan : public PassengerCar, public Bus
{
public:
	 Minivan()
	 {
		 company = "minivan";
		 cout << company << " " << model << endl;
	 };
	~Minivan(){};

private:

};

///////////////////////////////////////////////////////////////////////////

class Fraction
{
public:
	Fraction(int numer, int denom)
	{
		if (denom == 0)
		{
			cout << " You write denominator 0 denominar cant be 0 so now denominar == 1" << endl;

			numerator = numer;
			denominator = 1;
		}
		else
		{
			numerator = numer;
			denominator = denom;
		}
	};
	~Fraction(){};

	int get_num()
	{
		return numerator;
	}

	int get_denom()
	{
		return denominator;
	}

	Fraction operator+ (Fraction F2)
	{
		if (this->denominator != F2.denominator)
		{
			int temp = this->denominator;

			this->numerator *= F2.denominator;
			F2.numerator *= this->denominator;

			this->denominator *= F2.denominator;
			F2.denominator *= temp;

			return Fraction(this->numerator + F2.numerator, F2.denominator);
		}
		else if (this->denominator == F2.denominator)
		{
			return Fraction(this->numerator + F2.numerator, F2.denominator);
		}
	}

	Fraction operator- (Fraction F2)
	{
		if (this->denominator != F2.denominator)
		{
			int temp = this->denominator;

			this->numerator *= F2.denominator;
			F2.numerator *= this->denominator;

			this->denominator *= F2.denominator;
			F2.denominator *= temp;

			return Fraction(this->numerator - F2.numerator, F2.denominator);
		}
		else if (this->denominator == F2.denominator)
		{
			return Fraction(this->numerator - F2.numerator, F2.denominator);
		}
	}

	Fraction operator* (Fraction F2)
	{
		return Fraction(this->numerator * F2.numerator, this->denominator * F2.denominator);
	}

	Fraction operator/ (Fraction F2)
	{
		int temp = F2.numerator;
		
		F2.numerator = F2.denominator;
		F2.denominator = temp;

		return Fraction(this->numerator * F2.numerator, this->denominator * F2.denominator);
	}

	bool operator== (Fraction F2)
	{
		int temp = this->denominator;

		this->numerator *= F2.denominator;
		F2.numerator *= this->denominator;

		this->denominator *= F2.denominator;
		F2.denominator *= temp;

		if (this->numerator == F2.numerator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator!= (Fraction F2)
	{
		int temp = this->denominator;

		this->numerator *= F2.denominator;
		F2.numerator *= this->denominator;

		this->denominator *= F2.denominator;
		F2.denominator *= temp;

		if (this->numerator != F2.numerator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator< (Fraction F2)
	{
		int temp = this->denominator;

		this->numerator *= F2.denominator;
		F2.numerator *= this->denominator;

		this->denominator *= F2.denominator;
		F2.denominator *= temp;

		if (this->numerator < F2.numerator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator> (Fraction F2)
	{
		int temp = this->denominator;

		this->numerator *= F2.denominator;
		F2.numerator *= this->denominator;

		this->denominator *= F2.denominator;
		F2.denominator *= temp;

		if (this->numerator > F2.numerator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}


	bool operator>= (Fraction F2)
	{
		int temp = this->denominator;

		this->numerator *= F2.denominator;
		F2.numerator *= this->denominator;

		this->denominator *= F2.denominator;
		F2.denominator *= temp;

		if (this->numerator >= F2.numerator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	bool operator<= (Fraction F2)
	{
		int temp = this->denominator;

		this->numerator *= F2.denominator;
		F2.numerator *= this->denominator;

		this->denominator *= F2.denominator;
		F2.denominator *= temp;

		if (this->numerator <= F2.numerator)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

private:
	int numerator = 0;
	int denominator = 0;

};


class Card
{
public:
	Card();
	~Card();

	void Flip()
	{
		if (position == true)
		{
			position = false;
		}
		else
		{
			position = true;
		}
	}

	int get_value()
	{
		return suit, number;
	}

private:
	Suit suit;
	Number number;
	bool position;
};

int main()
{
	Rhombus R1;
	Square R2;
	Rectangle R3;
	Cricle R4;
	Parallelogram R5;


	cout << R1.area() << " " << R2.area() << " " << R3.area() << " " << R4.area() << " " << R5.area() << endl;


	Car C1;
	PassengerCar C2;
	Bus C3;
	Minivan C4;

	Fraction F1(5,3);
	Fraction F2(2,6);
	
	Fraction F3 = F1 / F2;

	cout << F3.get_num() << "/" << F3.get_denom() << endl;


	

}
