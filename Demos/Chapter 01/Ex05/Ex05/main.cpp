/*
 * Ex05 - Implicit constructor (conversion) demonstration.
 *
 * Written by: Ilan Amoyal
 */
 
#include <iostream>

using namespace std;

class Complex
{
private:
	double m_real, m_imaginary;
public:
	Complex(double real) { m_real = real; m_imaginary = 0.0; }
	Complex(double real, double imaginary) { m_real = real; m_imaginary = imaginary; }
	void Show() { cout << "(" << m_real << ", " << m_imaginary << ")\n"; }
};

int main(int argc, char **argv)
{
	Complex z1(3);
	z1.Show();
	
	Complex z2 = 4;
	z2.Show();
}