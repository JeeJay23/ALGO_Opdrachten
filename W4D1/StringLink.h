#pragma once

#include <string>

class StringLink
{
private:
	friend class StringStack;
public:
	std::string value;
	StringLink* next;

	StringLink(std::string, StringLink*);
};

