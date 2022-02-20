#pragma once

class IntLink
{
public:
                        IntLink();
                        IntLink( int, IntLink* );
    virtual            ~IntLink();

public:

private:
    int value;
    IntLink *next;

private:
    friend class IntLinkedList;
};

