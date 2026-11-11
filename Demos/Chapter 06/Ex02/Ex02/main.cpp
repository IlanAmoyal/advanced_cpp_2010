#include <iostream>
#include <typeinfo>

using namespace std;

class Base {};
class Derived : public Base {};

int main() 
{
	Derived derived;
	Base* pBase = &derived;
	cout << "Base is: " << typeid(Base).name() << endl;
	cout << "Derived is: " << typeid(Derived).name() << endl << endl;
	
	cout << "derived is: " << typeid(derived).name() << endl;
	cout << "*pbase is: " << typeid(*pBase).name() << endl;
	cout << "derived " << (typeid(derived) == typeid(*pBase) ? "=" : "!") << "= *pBase" << endl; 
}