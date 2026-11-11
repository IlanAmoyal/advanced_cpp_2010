#include "object.h"
#include "string.h"

std::ostream &operator<<(std::ostream &o, const Object &obj)
{
	o << (char *)(&obj)->ToString();
	return o;
}