#include <iostream>

using namespace std;

class base
{
private:
	int a, b;
	
protected:
	int c, d;
	
public:
	int e, f;
	base() { a = 1; b = 2; c = 3; d = 4; e = 5; f = 6; }
};

class derived : private base
{
public:
	int g, h;
	derived() : base() {g = 7; h = 8; }
	void func()
	{
		// 'base::a' : cannot access private member declared in class 'base'
		// a = 1;
		
		// OK
		c = 12;
	}
};

class anotherDerivation : private base
{
public:
	int g, h;
	anotherDerivation() : base() {g = 70; h = 80; }
	using base::e;
	using base::c; /* OK */
	
	// 'base::a' is not accessible from  'base'
	//using base::a;
};

int main(int argc, char **argv)
{
	derived d;
	
	// OK
	d.g = 10;
	
	// 'type cast' : conversion from 'derived *' to 'base *' exists, but is inaccessible
	// base *pB = &d;
	
	// 'base::e' not accessible because 'derived' uses 'private' to inherit from 'base'
	// d.e = 6;
	
	anotherDerivation ad;
	
	// OK
	ad.e  = 10;
	ad.c = 9;
	
	/* Oh, we can cheat the compiler */
	reinterpret_cast<base*>(&d)->e = 11;
}