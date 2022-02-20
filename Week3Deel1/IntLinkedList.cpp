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
    for (int i = 0; i < length2() -1; i++) {
        for (int j = length2() - 1; j > i; j--) {

            // store links to decrease amount of iterating through list
            IntLink* current = getAt(j);
            IntLink* toCompare = getAt(j - 1);

            // swap values instead of actual links
            if (current->value < toCompare->value) {
                int temp            = current->value;
                current->value      = toCompare->value; // dit zal nog langzamer lopen met SetAt
                toCompare->value    = temp;
            }
        }
    }
}

/*
 *  geschatte snelheid van dit algoritme: O(n^2)
 *  onderbouwing:
 *      De logica van het algoritme verandert niet, dus het aantal compares blijven hetzelfde.
 *      Wel zal het accessen van de links evenredig groter worden in verhouding met de grootte van de list. 
 *      Dit is omdat omdat het aantal stappen gelijk is aan de index bij getAt(n).
 */

 /*
 * metingen van de duur van het sorteren...
 *
 *    aantal waarden:       duur in us:
 *        1000                3254843 
 *        2000               26617826
 *        5000              416514790
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
