#include <iostream>

using namespace std;

class ConstClass
{
private:
	const int m_relative;
	int m_value;
	
public:
	ConstClass(int relative, int value) : m_relative(relative), m_value(value) { }
	void WhoIsGreater()
	{
		if(m_relative > m_value)
		{
			cout << "relative > value" << endl;
		}
		else if(m_relative < m_value)
		{
			cout << "relative < value" << endl;
		}
		else
		{
			cout << "relative == value" << endl;
		}
	}
};

int main(int argc, char **argv)
{
	ConstClass(7, 9).WhoIsGreater();
	ConstClass(9, 7).WhoIsGreater();
	ConstClass(8, 8).WhoIsGreater();
}