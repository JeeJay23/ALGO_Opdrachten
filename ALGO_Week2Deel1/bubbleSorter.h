#pragma once
class bubbleSorter
{
public:
	void sort();
	bubbleSorter()	{}
	~bubbleSorter() {}
private:
	int list[10] = {7, 3, 8, 1, 2, 5, 4, 6, 9, 0};
	int sizeList = 10;
};

