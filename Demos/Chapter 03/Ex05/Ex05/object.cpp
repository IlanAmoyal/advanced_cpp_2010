#include "object.h"
#include "string.h"

template<typename T>
T *Object::GetInterface(T *dummy)const
{
	try
	{
		return dynamic_cast<T*>(dynamic_cast<__baseObject*>(const_cast<Object*>(this)));
	}
	catch(std::bad_cast &bd)
	{
		return NULL;
	}
	catch(...)
	{
		return NULL;
	}
}

bool Object::operator<(const Object &obj)const
{
	IComparable *pComparable = GetInterface<IComparable>(NULL);
	if(pComparable)
	{
		return pComparable->CompareTo(obj) < 0;
	}
	throw "Not implemented";
}

bool Object::operator<=(const Object &obj)const
{
	IComparable *pComparable = GetInterface<IComparable>(NULL);
	if(pComparable)
	{
		return pComparable->CompareTo(obj)<= 0;
	}
	throw "Not implemented";
}

bool Object::operator==(const Object &obj)const
{
	IComparable *pComparable = GetInterface<IComparable>(NULL);
	if(pComparable)
	{
		return pComparable->CompareTo(obj)== 0;
	}
	throw "Not implemented";
}

bool Object::operator>=(const Object &obj)const
{
	IComparable *pComparable = GetInterface<IComparable>(NULL);
	if(pComparable)
	{
		return pComparable->CompareTo(obj)>= 0;
	}
	throw "Not implemented";
}

bool Object::operator>(const Object &obj)const
{
	IComparable *pComparable = GetInterface<IComparable>(NULL);
	if(pComparable)
	{
		return pComparable->CompareTo(obj)> 0;
	}
	throw "Not implemented";
}

bool Object::operator!=(const Object &obj)const
{
	IComparable *pComparable = GetInterface<IComparable>(NULL);
	if(pComparable)
	{
		return pComparable->CompareTo(obj)!= 0;
	}
	throw "Not implemented";
}

std::ostream &operator<<(std::ostream &o, const Object &obj)
{
	o << (char *)(&obj)->ToString();
	return o;
}