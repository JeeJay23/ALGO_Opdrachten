#include "stdafx.h"
#include "NAW.h"

///////////////////////////////////////////////////////////////////////////////
// constructor / destructor

NAW::NAW()
{
}

NAW::NAW( const std::string& naam, const std::string& adres, const std::string& woonplaats )
    :   naam(naam)
    ,   adres(adres)
    ,   plaats(woonplaats)
{
}

NAW::~NAW()
{
}

///////////////////////////////////////////////////////////////////////////////
// getters / setters

const std::string& NAW::getNaam() const
{
    return naam;
}

const std::string& NAW::getAdres() const
{
    return adres;
}

const std::string& NAW::getPlaats() const
{
    return plaats;
}

void NAW::setNaam( const std::string& n )
{
    naam = n;
}

void NAW::setAdres( const std::string& a )
{
    adres = a;
}

void NAW::setPlaats( const std::string& p )
{
    plaats = p;
}

///////////////////////////////////////////////////////////////////////////////
// comparators

bool NAW::heeftNaam( const std::string& other ) const
{
    return naam.compare(other) == 0;
}

bool NAW::heeftAdres( const std::string& other ) const
{
    return adres.compare(other) == 0;
}

bool NAW::heeftPlaats( const std::string& other ) const
{
    return plaats.compare(other) == 0;
}
