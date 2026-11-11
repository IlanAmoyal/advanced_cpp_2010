/*
 * Ex03 - Copy constructor second demonstration.
 *
 * Written by: Ilan Amoyal
 */
 
#include <iostream>
#include <cstdlib>

using namespace std;

class ClassA
{
private:
	char *m_strValue;
	int m_nId;
public:
	ClassA(const char *strValue) { m_strValue = strdup(strValue); }
	void SetId(int id) { m_nId = id; }
	~ClassA() 
	{ 
		cout << "Object ID: " << m_nId << ", trying to release the address: " << (int)m_strValue << "\n";
		std::free(m_strValue); 
		cout << "success\n";
	}
};

int main(int argc, char **argv)
{
	ClassA a("Hello world.");
	a.SetId(1);
	ClassA aCopy(a);
	aCopy.SetId(2);
}