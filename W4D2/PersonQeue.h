#pragma once

class PersonQeue
{
public:
	PersonQeue(int);
	void enqeue(int);
	int deqeue();
	int peek();
	int size();
	bool isEmpty();
	bool isFull();
private:
	static const int realMaxSize = 100;
	int maxSize;
	int front = 0;
	int rear = -1;
	int size = 0;
	int qeue[realMaxSize];
};

