#ifndef OBJECT_H
#define OBJECT_H

#include <iostream>

class String;

class Object
{
public:
	virtual String ToString()const = 0;
	virtual ~Object() {};
	friend std::ostream &operator<<(std::ostream &o, const Object &obj);
};

#endif // OBJECT_H