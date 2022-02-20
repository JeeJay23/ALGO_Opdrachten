#pragma once

class IntLink
{
public:
                        IntLink();
                        IntLink( int, IntLink* );
    virtual            ~IntLink();

public:
    /*
     * plaats hier de methodes voor de klasse
     */

private:
    int value;
    IntLink *next;

private:
    friend class IntLinkedList;
};

