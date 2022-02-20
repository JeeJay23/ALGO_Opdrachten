#include "stdafx.h"

#include "IntLink.h"


IntLink::IntLink()
{
}

IntLink::IntLink( int i, IntLink* n )
	:	value(i)
	,	next(n)
{
}

IntLink::~IntLink()
{
}
