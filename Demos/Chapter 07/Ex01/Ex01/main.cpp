#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

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
	
	static void reverse_print(vector<T,A> &v)
	{
		/* example of backward iteration */
		vector<T,A>::reverse_iterator riter = v.rbegin();
		while(riter != v.rend())
		{
			cout << *riter++ << " ";
		}
		cout << endl;
	}
};

int main(int argc, char **argv)
{
	vector<int> v1;
	vector_utils<int>::print(v1);
	
	vector<int> v2(10, 5);
	vector_utils<int>::print(v2);
	
	vector<int> v3(v2.begin(), v2.end());
	vector_utils<int>::print(v3);
	
	vector<int> v4(v2.begin() + 2, v2.end() - 3);
	vector_utils<int>::print(v4);
	
	cout << "v4.size()= " << v4.size() << endl;
	cout << "v4.capacity()= " << v4.capacity() << endl;
	
	v2.clear();
	v3.clear();
	
	srand(time(NULL));
	for(int i = 0; i < 10; i++)
	{
		v1.push_back(rand() % 100);
		v2.insert(v2.begin(), rand() % 100 + 100);
	}
	v3.insert(v3.begin(), v1.rbegin(), v1.rend());
	
	vector_utils<int>::print(v1);
	vector_utils<int>::print(v2);
	vector_utils<int>::print(v3);
	
	v1.pop_back();
	vector_utils<int>::print(v1);
	
	v2.erase(v2.begin() + 3, v2.begin() + 5);
	vector_utils<int>::print(v2);
	
	v1.at(0) = 9;
	v1[6] = 11;
	vector_utils<int>::print(v1);
	
	cout << "v2.front() = " << v2.front() << endl;
	cout << "v2.back() = " << v2.back() << endl;
	
	v2.pop_back();
}
