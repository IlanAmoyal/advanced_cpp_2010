#include <iostream>

using namespace std;

class A
{
public:
	~A(){ cout << "~A()\n"; }
};

class B : public A
{
public:
	~B(){ cout << "~B()\n"; }
};

class C
{
public:
	virtual ~C(){ cout << "~C()\n"; }
};

class D : public C
{
public:
	~D(){ cout << "~D()\n"; }
};


int main(int argc, char **argv)
{
	cout << "new B()\n";
	A *pA = new B();
	delete pA;
	
	{
		cout << "\nblock B()\n";
		B();
	}
	
	cout << "\n new D()\n";
	C *pC = new D();
	delete pC;
	
	{
		cout << "\nblock D()\n";
		D();
	}
}