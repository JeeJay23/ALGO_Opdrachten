#pragma once
#include <iostream>
#include <string>

class StringLink;

class StringStack
{
private:
	StringLink* first;

public:
	StringStack();
	void push(std::string);
	std::string pop();
	std::string peek();
	bool isEmpty();
	void showAll();
};

