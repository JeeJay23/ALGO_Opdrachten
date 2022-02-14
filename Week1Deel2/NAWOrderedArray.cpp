#include "stdafx.h"
#include "NAWOrderedArray.h"

///////////////////////////////////////////////////////////////////////////////
// constructor / destructor

NAWOrderedArray::NAWOrderedArray()
{
}


NAWOrderedArray::~NAWOrderedArray()
{
}

///////////////////////////////////////////////////////////////////////////////
// find, add, remove, replace...

int NAWOrderedArray::find( const NAW& toFind ) const
{
    int lowerBound = 0;
    int upperBound = listCount;

    while (lowerBound <= upperBound) {
        int middle = lowerBound + (upperBound - 1) / 2;
        int comparison = list[middle].compareTo(toFind);

        if (comparison == 0) 
            return middle;

        if (comparison > 0)
            // if toFind > middle, search right half
            lowerBound = middle + 1;
        else // else search left half
            upperBound = middle - 1;
    }

    return -1;
}

int NAWOrderedArray::add( const NAW& toAdd )
{
    if (listCount == 0) {
        list[0] = toAdd;
        listCount++;
        return 0;
    }

    // loop through list, and place item when the value of toAdd bigger is than looped item
    int insertIndex = 0;
    while (toAdd.compareTo(list[insertIndex]) < 0) {
        insertIndex++;
    }

    // insert it at found index
    // first, make space at index, copy everything one over to the right starting from insertIndex
    for (int i = listCount; i > insertIndex; i--) {
        if (i != 0)
            list[i] = list[i - 1];
    }

    // added item to array
    list[insertIndex] = toAdd;
    listCount++;

    return 0;
}

int NAWOrderedArray::remove( const NAW& toRemove )
{
    int toRemoveIndex = find(toRemove);

    // exit if naw is not found
    if (toRemoveIndex < 0) return -1;

    listCount--;
    for (int i = toRemoveIndex; i < listCount; i++) {
        list[i] = list[i + 1];
    }

    return 0;
}

int NAWOrderedArray::replace( const NAW& cOld, const NAW& cNew )
{
    if (remove(cOld) == 0)
        add(cNew);
    else
        return -1;

    return 0;
}

void NAWOrderedArray::showAll() const
{
}
