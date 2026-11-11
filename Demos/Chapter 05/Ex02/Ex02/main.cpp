#include <iostream>

using namespace std;

template<typename T>
int Compare(const T &obj1, const T &obj2)
{
	return obj1 > obj2 ? 1 : (obj1 == obj2 ? 0 : -1);
}

int main(int argc, char **argv)
{
	int a = 2, b = 6;
	cout << "Compare(a, b) = " << Compare(a, b) << endl;
	cout << "Compare(b, a) = " << Compare(b, a) << endl;
	
	const char *str1 = "aaa";
	const char *str2 = "bbb";
	cout << "Compare(str1, str2) = " << Compare(str1, str2) << endl;
}