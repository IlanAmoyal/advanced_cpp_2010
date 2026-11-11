#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
#include <cstdlib>

using namespace std;

template<typename T, typename A = allocator<T>>
class vector_utils
{
public:
	static void print(vector<T,A> &v)
	{
		/* example of forward iteration */
		vector<T,A>::iterator iter = v.begin();
		while(iter != v.end())
		{
			cout << *iter++ << " ";
		}
		cout << endl;
	}
};

class String
{
private:
	char *m_str;
public:
	String(const char *str) { m_str = strdup(str); }
	String(const String &str) { m_str = strdup(str.m_str); }
	const String &operator=(const String &str)
	{
		if (this == &str)
			return *this;
		free(m_str); 
		m_str = strdup(str.m_str); 
		return *this;
	}
	bool operator<(const String &str) const 
	{ 
		return strlen(m_str) < strlen(str.m_str); 
	}
	~String() { free(m_str); }
	friend ostream& operator<<(ostream &o, const String str);
};

ostream& operator<<(ostream &o, const String str)
{
	o << str.m_str;
	return o;
}

int main(int argc, char **argv)
{
	vector<String> v;
	v.push_back("ilan");
	v.push_back("amoyal");
	v.push_back("is");
	v.push_back("the");
	v.push_back("writer");
	v.push_back("of");
	v.push_back("this");
	v.push_back("book");
	sort(v.begin(), v.end());
	vector_utils<String>::print(v);
}