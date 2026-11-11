#include "PhoneEntry.h"
#include <cstdlib>

PhoneEntry::PhoneEntry() { m_name = m_phone = NULL;}

PhoneEntry::PhoneEntry(const char *name, const char *phone)
{
	m_name = strdup(name);
	m_phone = strdup(phone);
}

PhoneEntry::PhoneEntry(const PhoneEntry &phoneEntry)
{
	m_name = strdup(phoneEntry.m_name);
	m_phone = strdup(phoneEntry.m_phone);
}

PhoneEntry::~PhoneEntry()
{
	free(m_name);
	free(m_phone);
}

const PhoneEntry &PhoneEntry::operator=(const PhoneEntry &phoneEntry)
{
	if (this == &phoneEntry)
		return *this;
	free(m_name);
	free(m_phone);
	m_name = strdup(phoneEntry.m_name);
	m_phone = strdup(phoneEntry.m_phone);
	return *this;
}

bool PhoneEntry::operator==(const PhoneEntry &phoneEntry)const
{
	return stricmp(m_name, phoneEntry.m_name) == 0;
}

bool PhoneEntry::operator<(const PhoneEntry &phoneEntry)const
{
	return stricmp(m_name, phoneEntry.m_name) < 0;
}

bool PhoneEntry::operator>(const PhoneEntry &phoneEntry)const
{
	return stricmp(m_name, phoneEntry.m_name) > 0;
}

bool PhoneEntry::operator<=(const PhoneEntry &phoneEntry)const
{
	return stricmp(m_name, phoneEntry.m_name) <= 0;
}

bool PhoneEntry::operator>=(const PhoneEntry &phoneEntry)const
{
	return stricmp(m_name, phoneEntry.m_name) >= 0;
}

const char *PhoneEntry::get_name() const
{
	return m_name;
}

const char *PhoneEntry::get_phone() const
{
	return m_phone;
}

std::ostream &operator << (std::ostream &o, const PhoneEntry &p)
{
	o << p.m_name << ": " << p.m_phone;
	return o;
}

PhoneEntryPredicate::PhoneEntryPredicate()
{
	m_value = NULL;
	m_ignoreCase = m_byPhone = false;
}

PhoneEntryPredicate::PhoneEntryPredicate(const char*value, bool ignoreCase, bool byPhone)
{
	m_value = strdup(value);
	m_ignoreCase = ignoreCase;
	m_byPhone = byPhone;
}

PhoneEntryPredicate::PhoneEntryPredicate(const PhoneEntryPredicate &pred)
{
	m_value = strdup(pred.m_value);
	m_ignoreCase = pred.m_ignoreCase;
	m_byPhone = pred.m_byPhone;
}

bool PhoneEntryPredicate::operator()(const PhoneEntry &p)
{
	const char *value = m_byPhone ? p.get_phone() : p.get_name();
	if(m_ignoreCase) { return stricmp(m_value, value) == 0;}
	else { return strcmp(m_value, value) == 0;}
}

PhoneEntryPredicate::~PhoneEntryPredicate()
{
	free(m_value);
}