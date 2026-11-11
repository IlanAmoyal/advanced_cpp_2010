#include <iostream>

using namespace std;

template<class T>
void DoSomthing(T t)
{
	cout << "DoSomthing<" << typeid(T).name() << ">() is called...t = " << t << endl;
}

void DoSomthing(double t)
{
	cout << "oveloaded DoSomthing<double> is called...t = " << t << endl;
}

template<>
void DoSomthing(int t)
{
	cout << "specialized DoSomthing<int> is called...t = " << t << endl;
}

void DoSomthing(int t)
{
	cout << "overloaded DoSomthing<int> is called...t = " << t << endl;
}


int main(int argc, char **argv)
{
	DoSomthing(1.1);
	DoSomthing<double>(1.2);
	DoSomthing(2);
	DoSomthing<int>(3);
	DoSomthing((float)4);
}