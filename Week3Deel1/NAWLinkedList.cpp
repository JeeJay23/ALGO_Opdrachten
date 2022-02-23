#include "stdafx.h"

#include "NAWLinkedList.h"

#include "NAW.h"
#include "NAWLink.h"

#include <iostream>

/*
 * opdracht 1
 */

NAWLinkedList::NAWLinkedList()
{
}


NAWLinkedList::~NAWLinkedList()
{
}

void NAWLinkedList::addToStart(const NAW& naw)
{
    NAW* toAdd = new NAW(naw.getNaam(), naw.getAdres(), naw.getPlaats());
    NAWLink* n = new NAWLink(*toAdd, first);
    first = n;
    size++;
}

NAWLink* NAWLinkedList::search(const NAW& naw) const
{
    NAWLink* next = first;
    while (next != nullptr) {
        if (next->getItem().compareTo(naw) == 0) {
            return next;
        }
        else {
            // naw not found, go to next in list
            next = next->getNext();
        }
    }
    return nullptr;
}

void NAWLinkedList::showAll() const
{
    NAWLink* next = first;
    while (next != nullptr) {
        const NAW& n = next->getItem();
        std::printf("%p : %s %s %s \n",
            &n,
            n.getNaam().c_str(), 
            n.getAdres().c_str(), 
            n.getPlaats().c_str()
        );
        next = next->getNext();
    }
}

NAWLink* NAWLinkedList::removeFirst( const NAW& naw )
{
    NAWLink *next = first, *prev = first, *toDelete;

    while (next != nullptr) {
        if (next->getItem().compareTo(naw) == 0) {
            // found item to delete
            toDelete = next;
            prev->next = toDelete->getNext();
            delete(toDelete);
            return prev->next;
        }
        else {
            // naw not found, go to next in list
            prev = next; // store previous node
            next = next->getNext();
        }
    }

    return nullptr;
}
