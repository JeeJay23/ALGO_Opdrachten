#include "stdafx.h"
#include "IntDoubleLinkedList.h"
#include "IntDoubleLink.h"
#include <iostream>


IntDoubleLinkedList::IntDoubleLinkedList()
    :   first(nullptr)
    ,   last(nullptr)
    ,   length(0)
    ,   lastAction(nullptr)
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
    lastAction = toAdd;

    length++;
}

bool IntDoubleLinkedList::removeAtStart()
{
    return false;
}

bool IntDoubleLinkedList::removeAtEnd()
{
    if (last == nullptr) return false;

    IntDoubleLink* toDelete = last;
    if (last->getPrev() == nullptr) { // if there is no node before last, the list size must be 1
        first = nullptr;
        delete(last);
        last = nullptr;
        length--;
        return true;
    }
    else {
        auto toDelete = last;
        last = last->getPrev();
        last->next = nullptr;
        delete(toDelete);
        length--;
    }

    return true;
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
 *        1000                8172
 *        2000               35580
 *        5000              223294
 *       10000              992933
 *         ...
 */  

/*
 *  gemeten snelheid van dit algoritme: O(n^2)
 *  onderbouwing:
 *      waar de waardes groeien met een factor van 2 vergroot de tijdsduur grofweg met een waarde van 4, wat 2^2 is.
 *
 */

/*
 *  Vergelijking met bubblesort van week 3 deel 1
 *  opdracht omschrijving op brightspace vraagt om een vergelijking met week 2 vraag 4? maar die bestaat niet zover ik weet.
 *  Ik neem maar aan dat je deze week bedoelt.
 *  
 *  Bij deel 1 kwamen de bereking uit op O(n^3) en bij deze O(n^2). Dat is een flink verschil zonder de logica van het algoritme zelf te veranderen.
 *  Dit toont hoe duur een enkelzijdige list kan zijn bij veel accesses. 
 *  
 */

void IntDoubleLinkedList::insertAction( int code )
{
    // delete all nodes after lastAction
    while (lastAction != last) {
        removeAtEnd();
    }

    insertAtEnd(code);
}

int IntDoubleLinkedList::undo()
{
    if (lastAction->getPrev() == nullptr) return -1;

    lastAction = lastAction->getPrev();
    return lastAction->value; // return current value/action...
}

int IntDoubleLinkedList::redo()
{
    if (lastAction->getNext() == nullptr) return -1;

    lastAction = lastAction->getNext();
    return lastAction->value; // return current value/action...
}

int IntDoubleLinkedList::getCurrentAction()
{
    return lastAction->value;
}

void IntDoubleLinkedList::showAll()
{
    IntDoubleLink* curr = first;

    while (curr != nullptr) {
        std::printf("%p : %i\n", curr, curr->value);
        curr = curr->getNext();
    }
}
