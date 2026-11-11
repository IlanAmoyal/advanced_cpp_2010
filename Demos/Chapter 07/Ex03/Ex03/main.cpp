#include <iostream>
#include <list>
#include "PhoneEntry.h"
#include <algorithm>

using namespace std;

template<typename T, typename A = allocator<T>>
class list_utils
{
public:
	static void print(const char *listName, list<T,A> &l, const char *separator = "\n")
	{
		/* example of forward iteration */
		cout << listName << ": ";
		list<T,A>::iterator iter = l.begin();
		if(iter != l.end())
		{
			cout << *iter++;;
		}
		while(iter != l.end())
		{
			cout << separator << *iter++;
		}
		cout << endl;
	}
	
	static void reverse_print(const char *listName, list<T,A> &l, const char *separator = "\n")
	{
		/* example of backward iteration */
		cout << listName << "(r): ";
		list<T,A>::reverse_iterator riter = l.rbegin();
		if(riter != l.rend())
		{
			cout << *riter++;
		}
		while(riter != l.rend())
		{
			cout << separator << *riter++;
		}
		cout << endl;
	}
};

int main(int argc, char **argv)
{
	list<PhoneEntry> l1;
	l1.push_back(PhoneEntry("Paul", "111111"));
	l1.push_back(PhoneEntry("Paula", "222222"));
	l1.push_back(PhoneEntry("Ilan", "4568721"));
	l1.push_back(PhoneEntry("Linda", "3216457"));
	l1.push_back(PhoneEntry("Dana", "666666"));
	l1.push_back(PhoneEntry("Ilan", "4545454"));
	list_utils<PhoneEntry>::print("list1", l1, " ; ");
	
	/* sort */
	l1.sort();
	list_utils<PhoneEntry>::print("list1", l1, " ; ");
	
	/* removes duplicats */
	l1.unique();
	list_utils<PhoneEntry>::print("list1", l1, " ; ");
	
	/* creates another list */
	list<PhoneEntry> l2;
	l2.push_front(PhoneEntry("Goerge", "3521654"));
	l2.push_front(PhoneEntry("Roni", "6547895"));
	l2.push_front(PhoneEntry("Aya", "5689755"));
	
	/* swaps elements */
	l1.swap(l2);
	list_utils<PhoneEntry>::print("list1", l1, " ; ");
	list_utils<PhoneEntry>::print("list2", l2, " ; ");
	
	/* merge lists */
	l1.sort();
	l2.sort();
	l1.merge(l2);
	list_utils<PhoneEntry>::print("list1", l1, " ; ");
	list_utils<PhoneEntry>::print("list2", l2, " ; ");
	
	/* search by a name */
	list<PhoneEntry>::iterator searchIter = find_if(l1.begin(), l1.end(), PhoneEntryPredicate("ilan", true));
	if(searchIter != l1.end())
	{
		cout << "Found: " << *searchIter << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}
	
	/* search by a phone */
	searchIter = find_if(l1.begin(), l1.end(), PhoneEntryPredicate("3216457", true, true));
	if(searchIter != l1.end())
	{
		cout << "Found: " << *searchIter << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}
	
	/* another search */
	searchIter = find_if(l1.begin(), l1.end(), PhoneEntryPredicate("Orna", true));
	if(searchIter != l1.end())
	{
		cout << "Found: " << *searchIter << endl;
	}
	else
	{
		cout << "Not found!" << endl;
	}
}
