#pragma once
#include "NAW.h"

class NAW;

class NAWOrderedArray
{
public:
                    NAWOrderedArray();
    virtual        ~NAWOrderedArray();

public: // methode voor vraag 1
    virtual int     find( const NAW& )      const;
    virtual int     add( const NAW& );
    virtual int     remove( const NAW& );
    virtual int     replace( const NAW& cOld, const NAW& cNew );

public: // niet gevraagd, wel handig
    virtual void    showAll()               const;

private:
    int listCount = 0;
    NAW list[20];
};
