#include "StringStack.h"
#include "StringLink.h"

StringStack::StringStack()
	:	first(nullptr)
{
}

void StringStack::push(std::string s)
{
	StringLink* toAdd = new StringLink(s, first);
	first = toAdd;
}

std::string StringStack::pop()
{
	if (isEmpty()) return "";
	std::string toReturn = first->value;

	// delete item
	StringLink* toDelete = first;
	first = first->next;
	delete(toDelete);

	return toReturn;
}

std::string StringStack::peek()
{
	if (isEmpty()) return "";
	return first->value;
}

bool StringStack::isEmpty()
{
	return first == nullptr;
}

void StringStack::showAll()
{
	StringLink* curr = first;
	while (curr != nullptr) {
		std::printf("%p %s\n", curr, curr->value.c_str());
		curr = curr->next;
	}
}
