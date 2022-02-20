#include "stdafx.h"

#include "IntLinkedList.h"

#include "IntLink.h"

#include <iostream>

IntLinkedList::IntLinkedList()
    :   first(nullptr)
    ,   size(0)
{
}


IntLinkedList::~IntLinkedList()
{
    // delete first?
}

IntLink* IntLinkedList::getAt( int i ) const
{
    IntLink *next = first;
    int cnt = 0;

    // return link with matching index
    while (next != nullptr) {
        if (cnt++ == i) return next;
        next = next->next;
    }

    // if not found, return null
    return nullptr;
}

bool IntLinkedList::setAt( int i, int v )
{
    bool succeeded = false;

    IntLink* next = first;
    int cnt = 0;

    while (next != nullptr) {
        if (cnt == i) {
            next->value = v;
            succeeded = true;
            return succeeded;
        }
        cnt++;
        next = next->next;
    }

    return succeeded;
}

int IntLinkedList::length1() const
{
    // tel aantal links

    IntLink* next = first;
    int cnt = 0;

    while (next != nullptr) {
        cnt++;
        next = next->next;
    }

    return cnt;
}

int IntLinkedList::length2() const
{
    return size;
}

void IntLinkedList::bubbleSort()
{
}

/*
 *  geschatte snelheid van dit algoritme: O(...)
 *  onderbouwing:
 *
 *
 */

 /*
 * metingen van de duur van het sorteren...
 *
 *    aantal waarden:       duur in us:
 *        1000
 *        2000
 *        5000
 *       10000
 *         ...
 */  

/*
 *  gemeten snelheid van dit algoritme: O(...)
 *  onderbouwing:
 *
 *
 */

void IntLinkedList::addToStart( int i )
{
    IntLink* toAdd = new IntLink(i, first);
    first = toAdd;
    size++;
}

void IntLinkedList::showAll() const
{
    IntLink* next = first;
    while (next != nullptr) {
        std::printf("%p : %i\n", next, next->value);
        next = next->next;
    }
}
