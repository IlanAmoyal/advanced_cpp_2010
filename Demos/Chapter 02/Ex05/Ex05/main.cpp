/*
 * Chapter 02 - Ex05
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

class B : virtual public A 
{ 
public:
	int b;
	B() { b = 0xBBBBBBBB; }
};

class C : virtual public A 
{
public:
	int c;
	C() { c = 0xCCCCCCCC; }
};

class D : public B, public C
{
};

int main(int argc, char **argv)
{
	cout << "Inspect B..." << endl;
	B b;
	DumpMemory("b", (int*)&b, sizeof(b));
	
	cout << "\nInspect C..." << endl;
	C c;
	DumpMemory("c", (int*)&c, sizeof(c));
	
	cout << "\nInspect D..." << endl;
	D d;
	DumpMemory("d", (int*)&d, sizeof(d));
	
	d.a = 0x11111111;
	DumpMemory("d", (int*)&d, sizeof(d));
	
	d.B::a = 0x22222222;
	DumpMemory("d", (int*)&d, sizeof(d));
	
	d.C::a = 0x33333333;
	DumpMemory("d", (int*)&d, sizeof(d));
	
	B *pB = &d;
	pB->a = 0x44444444;
	DumpMemory("d", (int*)&d, sizeof(d));
}

