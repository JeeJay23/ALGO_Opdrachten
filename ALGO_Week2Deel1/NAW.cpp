#include "NAW.h"

///////////////////////////////////////////////////////////////////////////////
// constructor / destructor

NAW::NAW()
{
}

NAW::NAW( const std::string& naam, const std::string& adres, const std::string& woonplaats, int id)
    :   naam(naam)
    ,   adres(adres)
    ,   plaats(woonplaats)
    ,   id(id)
{ }

NAW::~NAW()
{
}

///////////////////////////////////////////////////////////////////////////////
// comparators, part 1

int NAW::compareTo( const NAW& other ) const
{
    // check if plaats is the same
    int cPlaats = plaats.compare(other.getPlaats());

    // if they are equal, check naam
    if (0 == cPlaats) {
        int cName = naam.compare(other.getNaam());

        // if name is the same, check adres
        if (0 == cName)
            return adres.compare(other.getAdres());
        else
            return cName;
    }

    return cPlaats;
}


///////////////////////////////////////////////////////////////////////////////
// getters / setters

const std::string& NAW::getNaam() const
{
    return naam; // neem broncode over van week 1 deel 1
}

const std::string& NAW::getAdres() const
{
    return adres; // neem broncode over van week 1 deel 1
}

const std::string& NAW::getPlaats() const
{
    return plaats; // neem broncode over van week 1 deel 1
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
// comparators, part 2

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

bool NAW::operator>=(const NAW& b) const
{
    return (compareTo(b) >= 0);
}
