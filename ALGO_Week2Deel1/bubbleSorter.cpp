#include "bubbleSorter.h"

void bubbleSorter::sort()
{
	for (int i = 0; i < sizeList - 1; i++) {
		for (int j = sizeList - 1; j > i; j--) {
			if (list[j] < list[j - 1]) {
				int temp	= list[j];
				list[j]		= list[j - 1];
				list[j - 1] = temp;
			}
		}
	}
}
