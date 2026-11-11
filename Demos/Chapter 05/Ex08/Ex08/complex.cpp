#include "complex.h"

complex complex::operator +(const complex &c) const
{
	return complex(m_real + c.m_real, m_imaginary + c.m_imaginary);
}

complex complex::operator -(const complex &c) const
{
	return complex(m_real - c.m_real, m_imaginary - c.m_imaginary);
}

complex complex::operator *(const complex &c) const
{
	return complex((m_real * c.m_real) - (m_imaginary * c.m_imaginary), (m_real * c.m_imaginary) + (m_imaginary * c.m_real));
}

complex complex::operator /(const complex &c) const
{
	double tmp = (c.m_real * c.m_real) + (c.m_imaginary * c.m_imaginary);
	if(tmp == 0.0)
	{
		throw "Invalid operation";
	}
	return complex
	(
		((m_real * c.m_real) + (m_imaginary * c.m_imaginary)) / tmp,
		((m_imaginary * c.m_real) - (m_real * c.m_imaginary)) / tmp
	);
}

const complex& complex::operator +=(const complex &c)
{
	complex tmp = *this + c;
	m_real = tmp.m_real;
	m_imaginary = tmp.m_imaginary;
	return *this;
}

const complex& complex::operator -=(const complex &c)
{
	complex tmp = *this - c;
	m_real = tmp.m_real;
	m_imaginary = tmp.m_imaginary;
	return *this;
}

const complex& complex::operator *=(const complex &c)
{
	complex tmp = *this * c;
	m_real = tmp.m_real;
	m_imaginary = tmp.m_imaginary;
	return *this;
}

const complex& complex::operator /=(const complex &c)
{
	complex tmp = *this / c;
	m_real = tmp.m_real;
	m_imaginary = tmp.m_imaginary;
	return *this;
}

complex operator+(double value, const complex &c)
{
	return c + value;
}

complex operator-(double value, const complex &c)
{
	return c - value;
}

complex operator*(double value, const complex &c)
{
	return c * value;
}

complex operator/(double value, const complex &c)
{
	return c / value;
}

std::ostream& operator<<(std::ostream &o, const complex &c)
{
	o << c.m_real << " + " << c.m_imaginary << "i";
	return o;
}

//istream& operator>>(istream &i, complex &c)
//{
//	c.m_real << o;
//	
//}