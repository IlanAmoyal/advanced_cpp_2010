/*
 * Chapter 02 - Ex04
 *
 * Written by Ilan Amoyal
 */

#include <iostream>

using namespace std;

void DumpMemory(const char *name, int *pBase, size_t size)
{
	cout << name << " (" << hex << (int)pBase << ") " << ":[ ";
	if(size > 0)
	{
		cout << hex << *pBase;
	}
	for(int i = 1; i < size / sizeof(int); i++)
	{
		cout << " | " << hex << *(pBase + i);
	}
	cout << " ]" << endl;
}

class A
{
public:
	int a;
	A() { a = 0xAAAAAAAA;}
};

class B
{
public:
	int b;
	B() { b = 0xBBBBBBBB; }
};

class C : public A, public B
{
public:
	int c;
	C() { c = 0xCCCCCCCC; }
};

class D : public A, public C
{
public:
	int d;
	D() { d = 0xDDDDDDDD; }
};

class E : public A, public C
{
public:
	int a; /* hides the one inherited from a and c */
	int e;
	E() { a = 0xEEEEEEEE; e = 0xEEEEEEEE; }
};

class F :  public E
{
};

int main(int argc, char **argv)
{
	cout << "Inspect D..." << endl;
	
	D d;
	DumpMemory("d", (int*)&d, sizeof(d));
	
	// ambiguous access of 'a'
	// d.a = 0x;
	
	d.A::a = 0x11111111; 
	DumpMemory("d", (int*)&d, sizeof(d));
	
	d.C::a = 0x22222222;
	DumpMemory("d", (int*)&d, sizeof(d));
	
	d.C::A::a = 0x33333333;
	DumpMemory("d", (int*)&d, sizeof(d));
	
	cout << "\nInspect E..." << endl;
	E e;
	DumpMemory("e", (int*)&e, sizeof(e));
	
	e.a = 0x11111111; /* works! */
	DumpMemory("e", (int*)&e, sizeof(e));
	
	e.A::a = 0x22222222;
	DumpMemory("e", (int*)&e, sizeof(e));
	
	e.C::a = 0x33333333;
	DumpMemory("e", (int*)&e, sizeof(e));
	
	e.C::A::a = 0x44444444;
	DumpMemory("e", (int*)&e, sizeof(e));
	
	cout << "\nInspect F..." << endl;
	F f;
	DumpMemory("f", (int*)&f, sizeof(f));
	
	f.a = 0x11111111; 
	DumpMemory("f", (int*)&f, sizeof(f));
	
	f.E::a = 0x22222222; 
	DumpMemory("f", (int*)&f, sizeof(f));
	
	f.A::a = 0x33333333; 
	DumpMemory("f", (int*)&f, sizeof(f));
	
	f.E::A::a = 0x44444444; 
	DumpMemory("f", (int*)&f, sizeof(f));
	
	f.C::a = 0x55555555; 
	DumpMemory("f", (int*)&f, sizeof(f));
	
	f.E::C::a = 0x66666666; 
	DumpMemory("f", (int*)&f, sizeof(f));
}