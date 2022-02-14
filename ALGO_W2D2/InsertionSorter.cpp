#include "InsertionSorter.h"

void InsertionSorter::sort()
{
	for (int i = size - 2; i >= 0; i--) {
		int t = arr[i];							// store temp
		int j = i;								// start at temp's position
		while (j < size - 1 && arr[j+1] <= t) { // loop from temp to end of array or until temp > checked item
			arr[j] = arr[j + 1];				// shift to the left
			j++;
		}
		arr[j] = t;								// store temp
	}
}
