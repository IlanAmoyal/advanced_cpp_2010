#ifndef WORKER_H
#define WORKER_H

#include "object.h"
#include "string.h"

class Worker : public Object
{
private:
	String m_name, m_phone;
	
public:
	Worker(const char *name, const char *phone) : m_name(name), m_phone(phone) {}
	Worker(const String &name, const String &phone) : m_name(name), m_phone(phone) {}
	String ToString()const;
};

#endif // WORKER_H