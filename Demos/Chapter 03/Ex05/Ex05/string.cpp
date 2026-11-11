#include "string.h"
#include <cstring>
#include <cstdlib>

#if _DEBUG

int String::m_stringCouter = 0;

int String::IncrementStringCounter() 
{ 
	++m_stringCouter;
	std::cout << "\nstring counter = " << m_stringCouter << std::endl;
	return m_stringCouter;
}

int String::DecrementStringCounter() 
{ 
	--m_stringCouter; 
	std::cout << "\nstring counter = " << m_stringCouter << std::endl;
	return m_stringCouter;
}

int String::GetStringCounter()
{ 
	return m_stringCouter; 
}

#endif // _DEBUG 

void String::CreateEmptyString()
{
	m_str = new char[1];
	m_str[0] = '\0';
}

void String::CopyFrom(const char *str, bool copy)
{
	
	if(copy)
	{
		m_str = new char[std::strlen(str) + 1];
		std::strcpy(m_str, str);
	}
	else
	{
		m_str = const_cast<char *>(str);
	}
}

void String::ClearMemory()
{
	delete[] m_str;
}

String::String(const char *str, bool copy)
{
#ifdef _DEBUG
	IncrementStringCounter();
#endif // _DEBUG
	if(str == NULL)
	{
		CreateEmptyString();
	}
	else
	{
		CopyFrom(str, false);
	}
}

String::String()
{
#ifdef _DEBUG
	IncrementStringCounter();
#endif // _DEBUG
	CreateEmptyString();
}

String::String(const char *str)
{
#ifdef _DEBUG
	IncrementStringCounter();
#endif // _DEBUG
	CopyFrom(str, true);
}

String::String(const String &str)
{
#ifdef _DEBUG
	IncrementStringCounter();
#endif // _DEBUG
	CopyFrom(str.m_str, true);
}

String String::ToString()const
{
	return *this;
}

String String::operator+(const String &str)const
{
	char *tmp = new char[strlen(m_str) + strlen(str.m_str) + 1];
	tmp[0] = '\0';
	strcat(tmp, m_str);
	strcat(tmp, str.m_str);
	return String(tmp, false);
}

const String &String::operator=(const String &str)
{
	if(this == &str) // self assinment
		return *this;
	ClearMemory();
	CopyFrom(str.m_str, true);
	return *this;
}

String::operator char*()
{
	return m_str;
}

String::~String()
{
#ifdef _DEBUG
	DecrementStringCounter();
#endif
	ClearMemory();
}

int String::CompareTo(const Object &obj) const
{
	return strcmp(this->m_str, obj.ToString().m_str);
}
