#include <iostream>
#include <typeinfo>

using namespace std;

int main() 
{
	double d;
	double *pd;
	cout << "double is: " << typeid(double).name() << endl;
	cout << "d is: " << typeid(d).name() << endl;
	cout << "pd is: " << typeid(pd).name() << endl;
	cout << "*pd is: " << typeid(*pd).name() << endl;
	cout << "typeid(d) " << (typeid(d) == typeid(*pd) ? "=" : "!") << "= typeid(*pd)" << endl;
}