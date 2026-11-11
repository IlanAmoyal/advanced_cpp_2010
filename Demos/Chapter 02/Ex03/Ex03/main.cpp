/*
 * Chapter 02 - Ex03
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

class E : public A, public D, public C
{
public:
	int e;
	E() { e = 0xEEEEEEEE; }
};

int main(int argc, char **argv)
{
	A a;
	B b;
	C c;
	D d;
	E e;
	
	DumpMemory("a", (int*)&a, sizeof(a));
	DumpMemory("b", (int*)&b, sizeof(b));
	DumpMemory("c", (int*)&c, sizeof(c));
	DumpMemory("d", (int*)&d, sizeof(d));
	DumpMemory("e", (int*)&e, sizeof(e));
}