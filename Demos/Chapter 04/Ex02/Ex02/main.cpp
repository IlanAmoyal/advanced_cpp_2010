#include <iostream>

using namespace std;

int main(int argc, char **argv)
{
	char *str = new(nothrow) char[10];
	str[0] = 'a';
	str[1] = 'a';
	str[2] = 'a';
	str[3] = '\0';
	std::cerr << str << std::endl;
}