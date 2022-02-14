#pragma once

#include <string>
#include "NAW.h"

class NAW;

class NAWArray
{
public:
                    NAWArray();
    virtual        ~NAWArray();

public: // niet gevraagd, wel handig
    virtual void    add( const NAW& );

public: // vraag 2
    virtual int     zoekOpEersteNaam( const std::string& )          const;
    virtual int     zoekOpEersteAdres( const std::string& )         const;
    virtual int     zoekOpEerstePlaats( const std::string& )        const;
    virtual int     zoekOpEersteAdresEnPlaats( const std::string&
                                             , const std::string& ) const;

public: // vraag 4
    virtual int     verwijderEersteMetNaam( const std::string& );
    virtual int     verwijderLaatsteMetNaam( const std::string& );
    virtual int     verwijderAllenMetNaam( const std::string& );
    virtual int     verwijderEersteMetAdresEnPlaats( const std::string&
                                                   , const std::string& );
    virtual int     verwijderAllenMetAdresEnPlaats( const std::string&
                                                  , const std::string& );

private:
    int NAWArray::deleteAt(int);
    NAW list[20];
    unsigned short nList = 0;
};
