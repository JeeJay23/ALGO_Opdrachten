#pragma once

#include "NAW.h"

class NAWLink
{
private:
                    NAWLink( const NAW&, NAWLink* );
public:
    virtual        ~NAWLink();

    const NAW& getItem() const;
    NAWLink* getNext() const;

private:
    NAWLink* next = nullptr;
    const NAW& const item;

private:
    friend class NAWLinkedList;
};

