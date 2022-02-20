#include "stdafx.h"
#include "NAWLink.h"

NAWLink::NAWLink( const NAW& n, NAWLink* l )
    :   item(n)
    ,   next(l)
{
}

NAWLink::~NAWLink()
{
}

const NAW& NAWLink::getItem() const
{
    return item;
}

NAWLink* NAWLink::getNext() const
{
    return next;
}
