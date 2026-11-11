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

class derived : public base
{
private:
	/* makes c private */
	using base::c;
	
protected:
	/* making e protected */
	using base::e;
	
public:
	int g, h;
	derived() : base() {g = 7; h = 8; }
};

int main(int argc, char **argv)
{
	derived d;
	
	// 'derived::e' : cannot access protected member declared in class 'derived'
	//d.e = 10;
	
	/* OK */
	base *pB = &d;
	pB->e = 10; /* bypasses the privacy! */
}