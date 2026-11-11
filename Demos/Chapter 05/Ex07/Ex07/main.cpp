#include <iostream>

using namespace std;

class StackBase
{
protected:
	size_t m_maxSize;
	int m_current;
	StackBase(size_t maxSize) { m_current = 0; m_maxSize = maxSize; }
	virtual void PrintElementAt(int index)const = 0;
public:
	void Show()const
	{
		cout << '[' << m_current << " of " << m_maxSize << "] = { ";
		if(m_current > 0)
		{
			PrintElementAt(0);
		}
		for(int i = 1; i < m_current; i++)
		{
			cout << ", ";
			PrintElementAt(i);
		}
		cout << '}' << endl;
	}
	int GetSize() const { return m_current; }
	int GetMaxSize() const { return m_maxSize; }
	virtual ~StackBase(){ };
};


template<class T, int MaxSize>
class Stack : public StackBase
{
private:
	T *m_arr;
	
public:
	Stack() : StackBase(MaxSize)
	{ 
		m_arr = new T[MaxSize]; 
	}
	
	Stack& Push(T value)
	{
		if(m_current < (int)m_maxSize)
		{
			*(m_arr + m_current++) = value;
		}
		return *this;
	}
	
	T Pop()
	{
		if(m_current > 0)
		{
			return *(m_arr + --m_current);
		}
		else
		{
			throw "Stack is empty";
		}
	}
	
	void PrintElementAt(int index)const
	{
		cout << *(m_arr + index);
	}
	
	~Stack()
	{
		delete[] m_arr;
	}
};

int main(int argc, char **argv)
{
	Stack<int, 10> s1 = Stack<int, 10>();
	s1.Push(3).Push(4).Push(-9).Push(10);
	s1.Show();
	s1.Pop();
	s1.Show();
	
	Stack<double, 12> s2 = Stack<double, 12>();
	s2.Push(0.2).Push(0.3).Push(-9.5);
	s2.Show();
}