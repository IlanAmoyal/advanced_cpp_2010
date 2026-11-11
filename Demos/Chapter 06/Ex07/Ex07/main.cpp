#include <iostream>

using namespace std;

class Object
{
private:
	int m_value;
	int m_displayCount;
	
public:
	Object(int value) { m_value = value; m_displayCount = 0; }
	void Display() const 
	{ 
		cout << m_value << endl; 
		const_cast<Object*>(this)->m_displayCount++;
	}
	int GetDisplayCount() { return m_displayCount; }
};

int main(int argc, char **argv)
{
	Object object(10);
	object.Display();
	object.Display();
	object.Display();
	cout << "display count = " << object.GetDisplayCount() << endl;
	
}