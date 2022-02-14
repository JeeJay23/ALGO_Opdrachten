#include "stdafx.h"
#include "NAWArray.h"
#include "NAW.h"

#include <sstream>

NAWArray::NAWArray()
{
}

NAWArray::~NAWArray()
{
// gooi zo nodig, zaken weg....
}

void NAWArray::add( const NAW& n )
{
    list[nList] = n;
    nList++;
}

int NAWArray::zoekOpEersteNaam( const std::string& naam ) const
{
    for (int i = 0; i < nList; i++) {
        if (list[i].heeftNaam(naam)){ 
            return i;
        }
    }
    return -1;
}

int NAWArray::zoekOpEersteAdres( const std::string& adres ) const
{
    for (int i = 0; i < nList; i++) {
        if (list[i].heeftAdres(adres)){ 
            return i;
        }
    }
    return -1;
}

int NAWArray::zoekOpEerstePlaats( const std::string& plaats ) const
{
    for (int i = 0; i < nList; i++) {
        if (list[i].heeftPlaats(plaats)){ 
            return i;
        }
    }
    return -1;
}

int NAWArray::zoekOpEersteAdresEnPlaats( const std::string& adres
                                       , const std::string& plaats ) const
{
    for (int i = 0; i < nList; i++) {
        if (list[i].heeftPlaats(plaats) && list[i].heeftAdres(adres)){ 
            return i;
        }
    }
    return -1;
}

int NAWArray::deleteAt(int index)
{
    // iterate through array starting from found index until nList
    nList--;
    for (int i = index; i < nList; i++) {
        list[i] = list[i + 1];
    }
    return 0;
}

int NAWArray::verwijderEersteMetNaam( const std::string& naam )
{
    int foundIndex = zoekOpEersteNaam(naam);

    // exit out if there is no found name
    if (foundIndex < 0) { return -1; }

    deleteAt(foundIndex);
}

int NAWArray::verwijderLaatsteMetNaam( const std::string& naam )
{
    int indexes[20];
    int totalIndexesFound = 0;

    // get all naw's with matching name
    for (int i = 0; i < nList; i++) {
        bool hasName = list[i].heeftNaam(naam);
        if (hasName) {
            indexes[totalIndexesFound] = i;
            totalIndexesFound++;
        }
    }

    if (totalIndexesFound == 0) { return -1; }

    // delete last found index
    int lastIndex = indexes[totalIndexesFound - 1];

    deleteAt(lastIndex);
}

int NAWArray::verwijderAllenMetNaam( const std::string& naam )
{
    int i = 0;
    while (i != -1) {
        i = zoekOpEersteNaam(naam);
        if (i < 0) { return -1; }
        deleteAt(i);
    }
}

int NAWArray::verwijderEersteMetAdresEnPlaats( const std::string& adres
                                             , const std::string& plaats )
{
    int foundIndex = zoekOpEersteAdresEnPlaats(adres, plaats);

    // exit out if there is no found name
    if (foundIndex < 0) { return -1; }

    deleteAt(foundIndex);

}

int NAWArray::verwijderAllenMetAdresEnPlaats( const std::string& adres
                                            , const std::string& plaats )
{
    int i = 0;
    while (i != -1) {
        i = zoekOpEersteAdresEnPlaats(adres, plaats);
        if (i < 0) { return -1; }
        deleteAt(i);
    }
}
