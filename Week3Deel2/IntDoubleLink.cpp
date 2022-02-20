#include "stdafx.h"

#include "IntDoubleLink.h"

IntDoubleLink::IntDoubleLink()
{
}

IntDoubleLink::IntDoubleLink( int i, IntDoubleLink* prev, IntDoubleLink* next )
    :   value(i)
    ,   prev(prev)
    ,   next(next)
{
}

IntDoubleLink::~IntDoubleLink()
{
}

IntDoubleLink* IntDoubleLink::getPrev()
{
    return prev;
}

IntDoubleLink* IntDoubleLink::getNext()
{
    return next;
}
