#pragma once
class IntDoubleLink
{
private:
                            IntDoubleLink();
                            IntDoubleLink( int, IntDoubleLink*, IntDoubleLink* );
public:
    virtual                ~IntDoubleLink();

public:
    virtual IntDoubleLink  *getPrev();
    virtual IntDoubleLink  *getNext();

private:
    int value;
    IntDoubleLink* prev;
    IntDoubleLink* next;

private:
    friend class IntDoubleLinkedList;
};

