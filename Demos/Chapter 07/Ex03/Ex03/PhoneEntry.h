#ifndef PHONE_ENTRY_H
#define PHONE_ENTRY_H

#include <iostream>
#include <cstdlib>

class PhoneEntry
{
private:
	char *m_name, *m_phone;
public:
	PhoneEntry();
	PhoneEntry(const char *name, const char *phone);
	PhoneEntry(const PhoneEntry &phoneEntry);
	~PhoneEntry();
	
	const PhoneEntry &operator=(const PhoneEntry &phoneEntry);
	bool operator==(const PhoneEntry &phoneEntry)const;
	bool operator<(const PhoneEntry &phoneEntry)const;
	bool operator>(const PhoneEntry &phoneEntry)const;
	bool operator<=(const PhoneEntry &phoneEntry)const;
	bool operator>=(const PhoneEntry &phoneEntry)const;
	
	friend std::ostream &operator << (std::ostream &o, const PhoneEntry &p);
	
	// getters
	const char *get_name()const;
	const char *get_phone()const;
};

class PhoneEntryPredicate
{
private:
	char *m_value;
	bool m_ignoreCase;
	bool m_byPhone;
	
public:
	PhoneEntryPredicate();
	PhoneEntryPredicate(const char*value, bool ignoreCase = false, bool byPhone = false);
	PhoneEntryPredicate(const PhoneEntryPredicate &pred);
	bool operator()(const PhoneEntry &p);
	~PhoneEntryPredicate();
};

#endif // PHONE_ENTRY_H