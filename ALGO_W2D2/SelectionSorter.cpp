#include "SelectionSorter.h"

// selection sort
void SelectionSorter::sort()
{
	for (int i = size - 1; i >= 0; i--) {
		int biggest = i;
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[biggest]) {
				biggest = j;
			}
		}
		swap(i, biggest);
	}
}

void SelectionSorter::swap(int a, int b)
{
	int t	= arr[a];
	arr[a]	= arr[b];
	arr[b]	= t;
}
