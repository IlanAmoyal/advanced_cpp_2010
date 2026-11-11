#ifndef STRING_H
#define STRING_H

#include "object.h"

class String : public Object
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