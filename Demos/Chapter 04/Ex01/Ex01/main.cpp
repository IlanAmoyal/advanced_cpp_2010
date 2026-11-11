#include <iostream>
#include <cstring>

using namespace std;

class Stack
{
private:
	int *m_data;
	size_t m_size;
	size_t m_actualSize;
	mutable int m_currentIteratorIndex;
	
public:
	Stack()
	{
		m_data = NULL;
		m_size = 0;
		m_currentIteratorIndex = -1;
		m_actualSize = 0;
	}
	
	void Push(int value)
	{
		if(m_size == m_actualSize)
		{
			// reallocated the block 
			int *newData = new int[m_actualSize = (m_actualSize == 0 ? 2 : m_actualSize * 2)];
			if(m_data != NULL)
			{
				memcpy(newData, m_data, m_size * sizeof(int));
				delete[] m_data;
			}
			m_data = newData;
		}
		m_data[m_size++] = value;
	}
	
	int Pop()
	{
		if(m_size > 0)
		{
			return m_data[--m_size];
		}
		else
		{
			throw "Invalid operation";
		}
	}
	
	/* Iteration functions */
	void Start()const { m_currentIteratorIndex = -1; }
	
	bool Next()const 
	{ 
		if(m_currentIteratorIndex < (int)m_size)
		{
			m_currentIteratorIndex++;
		}
		return m_currentIteratorIndex < (int)m_size;
	}
	
	bool Previous()const 
	{ 
		if(m_currentIteratorIndex >= 0)
		{
			m_currentIteratorIndex--;
		}
		return m_currentIteratorIndex >= 0;
	}
	
	int Current()const
	{
		return *(m_data + m_currentIteratorIndex);
	}
	
	~Stack()
	{
		if(m_data != NULL)
		{
			delete[] m_data;
		}
	}
};

void DisplayStack(const Stack &stack)
{
	stack.Start();
	while(stack.Next()) 
	{
		cout << stack.Current() << " "; 
	}
	cout << endl;
}

int main(int argc, char **argv)
{
	Stack stack;
	stack.Push(2);
	stack.Push(6);
	stack.Push(-9);
	stack.Push(13);
	stack.Push(-14);
	stack.Push(104);
	DisplayStack(stack);
}