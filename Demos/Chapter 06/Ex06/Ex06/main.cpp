#include <iostream>

using namespace std;

class Object
{
private:
	int m_value;
	
public:
	Object(int value) { m_value = value; }
	void Display() const { cout << m_value << endl; }
	void Change() { m_value++; }
	void ForceChange() const { const_cast<Object*>(this)->m_value++; }
};

void OuterChangeFunction(const Object &object)
{
	// the following line causes a compilation error
	// object.Change();  
	object.ForceChange();
	object.Display();
}

void OuterForceChangeFunction(const Object &object)
{
	Object &tmp = const_cast<Object &>(object);
	// Now both lines are OK!
	tmp.Change();
	tmp.ForceChange();
	tmp.Display();
}

void OuterForceChangeFunctionV2(const Object &object)
{
	Object *pTmp = const_cast<Object *>(&object);
	// Now both lines are OK!
	pTmp->Change();
	pTmp->ForceChange();
	pTmp->Display();
}

int main(int argc, char **argv)
{
	Object object(10);
	OuterChangeFunction(object);
	OuterForceChangeFunction(object);
	OuterForceChangeFunctionV2(object);
}