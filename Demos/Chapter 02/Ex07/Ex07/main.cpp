#include <iostream>

using namespace std;

class A
{
private:
	int a;
public: 
	A(int _a) 
	{ 
		cout << "A( a = " << _a << ")" << endl;
		a = _a; 
	}
	~A()
	{
		cout << "~A()" << endl;
	}
};

class B : virtual public A
{
private:
	int b;
public: 
	B(int _a, int _b) : A(_a)
	{ 
		cout << "B( a = " << _a << ", b = " << _b << ")" << endl;
		b = _b;
	}
	~B()
	{
		cout << "~B()" << endl;
	}
};

class C : virtual public A
{
private:
	int c;
public: 
	C(int _a, int _c) : A(_a)
	{ 
		cout << "C( a = " << _a << ", c = " << _c << ")" << endl;
		c = _c;
	}
	~C()
	{
		cout << "~C()" << endl;
	}
};

class D : public B, public C
{
private:
	int d;
public: 
	D(int _a, int _b, int _c, int _d) : B(_a, _b), C(_a, _c), A(_a)
	{ 
		cout << "D( a = " << _a << ", b = " << _b << ", c = " << _c << ", d = " << _d << ")" << endl;
		d = _d;
	}
	~D()
	{
		cout << "~D()" << endl;
	}
};

int main(int argc, char **argv)
{
	{
		cout << "Inspect a..." << endl;
		A a(1);
	}
	
	{
		cout << "\nInspect b..." << endl;
		B b(2, 3);
	}
	
	{
		cout << "\nInspect c..." << endl;
		C c(4, 5);
	}
	
	{
		cout << "\nInspect d..." << endl;
		D d(6, 7, 8, 9);
	}
	
	B b(2,3);
	b = D(1, 2,3,4);
}