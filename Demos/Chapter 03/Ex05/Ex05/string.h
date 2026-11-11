#ifndef STRING_H
#define STRING_H

#include "object.h"
#include "icomparable.h"

class String : public Object, virtual public IComparable
{
private:
	char *m_str;
	String(const char *str, bool copy);
	void CreateEmptyString();
	void CopyFrom(const char *str, bool copy);
	void ClearMemory();
	
public:
	String();
	String(const char *str);
	String(const String &str);
	String ToString()const;
	const String& operator=(const String &str);
	operator char*();
	String operator+(const String &str)const;
	~String();

/* IComparable members */
public:
	int CompareTo(const Object &obj)const;

#ifdef _DEBUG
private:
	static int m_stringCouter;
	static int IncrementStringCounter();
	static int DecrementStringCounter();
public:
	static int GetStringCounter();
#endif

};

#endif STRING_H