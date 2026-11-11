#include <iostream>

using namespace std;

class A { };
class B { };

int main(int argc, char **argv)
{
	int n = 123456;
	float* pF = reinterpret_cast<float*>(&n); /* No error */
	
	A a;
	B *pB = reinterpret_cast<B*>(&a); /* No error */
	B &anotherB = reinterpret_cast<B&>(a); /* No error */
}