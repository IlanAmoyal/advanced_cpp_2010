#ifndef complex_H
#define complex_H

#include <iostream> 
#include <cmath>

class complex
{
private:
	double m_real;
	double m_imaginary;
	
public:
	/* Constructos */
	complex() : m_real(0.0), m_imaginary(0.0) {}
	complex(double value) : m_real(value), m_imaginary(0.0) {}
	complex(double r, double i) : m_real(r), m_imaginary(i) {}
	
	/* Operators */
	complex operator+(const complex &c)const;
	complex operator-(const complex &c)const;
	complex operator*(const complex &c)const;
	complex operator/(const complex &c)const;
	
	const complex& operator+=(const complex &c);
	const complex& operator-=(const complex &c);
	const complex& operator*=(const complex &c);
	const complex& operator/=(const complex &c);
	
	friend complex operator+(double value, const complex &c);
	friend complex operator-(double value, const complex &c);
	friend complex operator*(double value, const complex &c);
	friend complex operator/(double value, const complex &c);
	
	/* properties */
	complex conjugate()const { return complex(m_real, -m_imaginary); }
	double absolute() const { return sqrt((m_real * m_real) + (m_imaginary * m_imaginary)); }
	/* insertors/extractors*/
	friend std::ostream& operator<<(std::ostream &o, const complex &c);
	//friend istream& operator>>(istream &i, complex &c);
};

#endif // complex_H