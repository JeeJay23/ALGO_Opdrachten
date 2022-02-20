#include "stdafx.h"
#include "IntDoubleLinkedList.h"
#include "IntDoubleLink.h"
#include <iostream>


IntDoubleLinkedList::IntDoubleLinkedList()
    :   first(nullptr)
    ,   last(nullptr)
    ,   length(0)
{
}

IntDoubleLinkedList::~IntDoubleLinkedList()
{
}

void IntDoubleLinkedList::insertAtStart( int i )
{
    IntDoubleLink* toAdd = new IntDoubleLink(i, nullptr, nullptr);

    if (first == nullptr) {
        last = toAdd;
    }
    else {
        first->prev = toAdd;
    }

    toAdd->next = first;
    first = toAdd;

    length++;
}

void IntDoubleLinkedList::insertAtEnd( int i )
{
    IntDoubleLink* toAdd = new IntDoubleLink(i, nullptr, nullptr);

    if (first == nullptr) {
        first = toAdd;
    }
    else {
        last->next = toAdd;
    }

    toAdd->prev = last;
    last = toAdd;

    length++;
}

bool IntDoubleLinkedList::removeAtStart()
{
    return false;
}

bool IntDoubleLinkedList::removeAtEnd()
{
    return false;
}

IntDoubleLink* IntDoubleLinkedList::getHead()
{
    return first;
}

IntDoubleLink* IntDoubleLinkedList::getTail()
{
    return last;
}

void IntDoubleLinkedList::rapidBubbleSort()
{
    IntDoubleLink* outer = first;
    IntDoubleLink* inner = last;

    while (outer->getNext() != last) { // step to end of list
        while (inner != outer) { // step backwars until outer

            if (inner->value < inner->getPrev()->value) {
                int temp                = inner->value;
                inner->value            = inner->getPrev()->value;
                inner->getPrev()->value = temp;
            }

            // step to next link
            inner = inner->getPrev();
        }

        // move outer border forwards by 1
        outer = outer->getNext();
        // reset inner
        inner = last;
    }
}

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

/*
 *  Vergelijking met bubblesort van week 3 deel 1
 *
 *
 */

void IntDoubleLinkedList::insertAction( int code )
{
}

int IntDoubleLinkedList::undo()
{
    return -1; // return current value/action...
}

int IntDoubleLinkedList::redo()
{
    return -1; // return current value/action...
}

int IntDoubleLinkedList::getCurrentAction()
{
    return -1;
}

void IntDoubleLinkedList::showAll()
{
    IntDoubleLink* curr = first;

    while (curr != nullptr) {
        std::printf("%p : %i\n", curr, curr->value);
        curr = curr->getNext();
    }
}
