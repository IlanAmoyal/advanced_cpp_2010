#include <iostream>
#include <cstdlib>
#include "complex.h"

using namespace std;

template<class T> class Arithmetic
{
private:
	T m_a1, m_d;
public:
	Arithmetic(T a1, T d) : m_a1(a1), m_d(d) { }
	T operator()(size_t n) { return m_a1 + ((n - 1) * m_d); }
};

template<class T> class ComplexAbsolute
{
public:
	T operator()(const complex &c) {return c.absolute(); }
};

template<class I, class O, class F>
class Sequence
{
private:
	I *m_input;
	O *m_output;
	F *m_function;
	char *m_functionName;
	int m_current;
	size_t m_maxSize;
	
public:
	Sequence(const char *functionName, size_t maxSize)
	{
		m_current = 0;
		m_input = new I[maxSize];
		m_output = new O[maxSize];
		m_maxSize = maxSize;
		m_functionName = strdup(functionName);
	}
	
	void CalcFor(I input)
	{
		if(m_current < (int) m_maxSize)
		{
			O output = F()(input);
			m_input[m_current] = input;
			m_output[m_current] = output;
			m_current++;
		}
	}
	
	template<class I2, class O2, class F2>
	friend ostream &operator<<(ostream &o, const Sequence<I2, O2, F2> &seq);
	
	virtual ~Sequence()
	{
		delete[] m_input;
		delete[] m_output;
		free(m_functionName);
	}
};

template<class I, class O, class F>
ostream &operator<<(ostream &o, const Sequence<I, O, F> &seq)
{
	if(seq.m_current > 0)
	{
		o << seq.m_functionName << "(" << seq.m_input[0] << ") = " << seq.m_output[0];
	}
	for(int i = 1; i < seq.m_current; i++)
	{
		o << " ; " << seq.m_functionName << "(" << seq.m_input[i] << ") = " << seq.m_output[i];
	}
	return o;
}

int main(int argc, char **argv)
{
	Arithmetic<double> f(2.0, 3.0);
	cout << f(9) << endl;
	
	Arithmetic<complex> g(complex(1,3), complex(2,4));
	cout << g(3) << endl;
	
	Sequence<complex, double, ComplexAbsolute<double>> seq("abs", 10);
	seq.CalcFor(complex(3,4));
	seq.CalcFor(complex(7,24));
	seq.CalcFor(complex(8,15));
	cout << seq << endl;
}