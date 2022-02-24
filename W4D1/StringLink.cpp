#include "StringLink.h"

StringLink::StringLink(std::string s, StringLink* n)
	:	value(s)
	,	next(n)
{
}
