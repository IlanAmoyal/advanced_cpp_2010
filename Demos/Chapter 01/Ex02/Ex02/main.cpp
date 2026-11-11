/*
 * Ex02 - Copy constructor first demonstration 
 *
 * Written by: Ilan Amoyal
 *
 */

#include <iostream>

using namespace std;

class ClassA
{
private:
	int m_value;
	
public: 
	ClassA(int value = 0){ m_value = value; }
	/* A copy constructor is automatically created! */
	
	void Show() { cout << "ClassA: Value = " << this->m_value << endl; }
};

class ClassB
{
private:
	int m_value;
	
public: 
	ClassB(int value = 0 ){ m_value = value; }
	ClassB(const ClassB &obj) { m_value = obj.m_value; }
	/* A copy constructor is automatically created! */
	
	void Show() { cout << "ClassB: Value = " << m_value << endl; }
};

int main(int argc, char *argv[])
{
	cout << "a...\n";
	ClassA a(7);
	a.Show();
	
	cout << "\ncopy of a...\n";
	ClassA aCopy(a); /* The compiler copy constructor is executed */
	aCopy.Show();
	
	cout << "\nb...\n";
	ClassB b(9);
	b.Show();
	
	cout << "\ncopy of b...\n";
	ClassB bCopy(b);
	bCopy.Show();
}