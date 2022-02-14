#pragma once
#include "NAW.h"

class NAW;

class NAWOrderedArray
{
public:
                    NAWOrderedArray();
    virtual        ~NAWOrderedArray();

public: 
    virtual int     find( const NAW& )      const;
    virtual int     add( const NAW& );
    virtual int     dirty_add( const NAW& );
    virtual int     remove( const NAW& );
    virtual int     replace( const NAW& cOld, const NAW& cNew );
    void showAll();

    int             sort();

private:
    int listCount = 0;
    NAW list[20];
};
