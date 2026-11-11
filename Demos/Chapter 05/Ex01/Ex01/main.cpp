#include <iostream>

using namespace std;

template<class T>
void Swap(T &obj1, T &obj2)
{
	T tmp = obj1;
	obj1 = obj2;
	obj2 = tmp;
}

int main(int argc, char **argv)
{
	int a = 7, b = 9;
	Swap<int>(a, b);
	cout << "a = " << a << ", b = " << b << endl;
	
	double d1 = 2.0, d2 = 6.7;
	Swap<double>(d1, d2);
	cout << "d1 = " << d1 << ", d2 = " << d2 << endl;
}