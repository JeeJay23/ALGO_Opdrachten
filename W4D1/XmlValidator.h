#pragma once
#include <string>
#include "StringStack.h"

class XmlValidator
{
private:
    StringStack stack;
	void processTag(std::string);
public:
	XmlValidator();
	bool validate(std::string);
};

