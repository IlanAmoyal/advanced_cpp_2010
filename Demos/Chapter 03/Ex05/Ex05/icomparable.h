#ifndef ICOMPARABLE_H
#define ICOMPARABLE_H

#include "object.h"
#include "__baseObject.h"

class IComparable : virtual public __baseObject
{
public:
	virtual int CompareTo(const Object &obj)const = 0;
	virtual ~IComparable(){}
};

#endif // ICOMPARABLE_H