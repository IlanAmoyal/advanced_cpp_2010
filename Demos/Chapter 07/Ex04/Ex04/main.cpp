#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

template<typename T, typename A = allocator<T>>
class deque_utils
{
public:
	static void print(const char *name, deque<T,A> &c, const char *separator = "\n")
	{
		/* example of forward iteration */
		cout << name << ": ";
		deque<T,A>::iterator iter = c.begin();
		if(iter != c.end())
		{
			cout << *iter++;;
		}
		while(iter != c.end())
		{
			cout << separator << *iter++;
		}
		cout << endl;
	}
	
	static void reverse_print(const char *name, deque<T,A> &c, const char *separator = "\n")
	{
		/* example of backward iteration */
		cout << name << "(r): ";
		deque<T,A>::reverse_iterator riter = c.rbegin();
		if(riter != c.rend())
		{
			cout << *riter++;
		}
		while(riter != c.rend())
		{
			cout << separator << *riter++;
		}
		cout << endl;
	}
};

bool less_ints(int a, int b);

int main(int argc, char **argv)
{
	deque<char> d1, d2;
	for(int i = 0; i < 5; ++i)
	{
		d1.push_back('A' + i);
	}
	for(int i = 0; i < 5; ++i)
	{
		d2.push_front('A' + i);
	}
	deque_utils<char>::print("d1", d1, ", ");
	deque_utils<char>::print("d2", d2, ", ");
	
	/* copy d2 to the end of d1 */
	d1.insert(d1.end(), d2.begin(), d2.end());
	deque_utils<char>::print("d1", d1, ", ");
	deque_utils<char>::print("d2", d2, ", ");
	
	/* revese sort */
	stable_sort(d1.rbegin(), d1.rend(), less_ints);
	deque_utils<char>::print("d1", d1, ", ");
}

bool less_ints(int a, int b)
{
	return a < b;
}