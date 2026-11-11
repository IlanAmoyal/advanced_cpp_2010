#include <iostream>
#include <typeinfo>

using namespace std;

class Base {virtual void Member(){}};
class Derived: public Base {};

int main() 
{
	Derived derived;
	Base *pBase = &derived;
	cout << "derived is: " << typeid(derived).name() << endl;
	cout << "*pBase is: " << typeid(*pBase).name() << endl;
	cout << "derived " << (typeid(derived) == typeid(*pBase) ? "=" : "!") << "= *pBase" << endl;
}