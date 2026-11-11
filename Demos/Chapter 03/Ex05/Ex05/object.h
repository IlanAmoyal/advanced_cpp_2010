#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>
#include "__baseObject.h"

class String;
class IComparable;

class Object : virtual public __baseObject
{
private:
	template<typename T>
	T *GetInterface(T *dummy)const;
	
public:
	virtual String ToString()const = 0;
	virtual ~Object() {};
	
	bool operator<(const Object &obj)const;
	bool operator<=(const Object &obj)const;
	bool operator==(const Object &obj)const;
	bool operator>=(const Object &obj)const;
	bool operator>(const Object &obj)const;
	bool operator!=(const Object &obj)const;
	
	friend std::ostream &operator<<(std::ostream &o, const Object &obj);
};

#endif // OBJECT_H