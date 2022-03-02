#include "PersonQeue.h"

#include <iostream>

PersonQeue::PersonQeue(int max)
{
	if (max > realMaxSize) {
		std::cout << "Max size exceeds real max size\n";
		return;
	}

	maxSize = max;
}

void PersonQeue::enqeue(int num)
{
	if (rear == maxSize)
		rear = -1;

	qeue[++rear] = num;
	size++;
}

int PersonQeue::deqeue()
{
	return 0;
}

int PersonQeue::peek()
{
	return 0;
}

int PersonQeue::size()
{
	return 0;
}

bool PersonQeue::isEmpty()
{
	return false;
}

bool PersonQeue::isFull()
{
	return false;
}
