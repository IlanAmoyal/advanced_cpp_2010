/*
 * Ex06 - Explicit constructor demostration.
 *
 * Written by: Ilan Amoyal
 */
 
#include <iostream>
#include <cstring>

using namespace std;

class String
{
private:
	char *m_buffer;
	int m_bufferSize;

public:
	explicit String(size_t bufferSize) { m_buffer = new char[m_bufferSize = bufferSize]; }
	String(const char *str)
	{
		m_bufferSize = std::strlen(str) + 1;
		m_buffer = new char[m_bufferSize];
		std::memcpy(m_buffer, str, m_bufferSize);
	}
	void Set(const char *str) { strncpy(m_buffer, str, m_bufferSize); m_buffer[m_bufferSize - 1] = '\0'; }
	void Show() { cout << m_buffer << endl; }
	~String() { delete[] m_buffer; }
};

int main(int argc, char **argv)
{
	// String s = 5; ERROR!!
	String s1(5); // OK!
	s1.Set("Hello world");
	s1.Show();
	
	String s2 = (String)5;
	s2.Set("Oh yehh");
	s2.Show();
}