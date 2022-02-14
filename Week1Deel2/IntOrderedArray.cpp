#include "stdafx.h"
#include "IntOrderedArray.h"
#include <iostream>


IntOrderedArray::IntOrderedArray()
{
}


IntOrderedArray::~IntOrderedArray()
{
}

void IntOrderedArray::exploreBinarySearch( int f ) const
{
    int l = 0;
    int r = listCount - 1;
    int curIn;

    while (true) {
        curIn = (l + r) / 2;
        if (list[curIn] == f) {
            // kan niet want functie returnt void?
            // return curIn;
            return;
        }
        else if (l > r) {
            std::cout << "number not found in array\n";
            std::cout << "lowerBound: " << l << "\n";
            std::cout << "upperBound: " << r << "\n";
            return;
        }
        else {
            if (list[curIn] < f)
                l = curIn + 1;
            else
                r = curIn - 1;
        }
    }
}

/*
 * vul hieronder de tabel in voor vraag 3.b
 *
 *    waarde  lowerbound    upprbound
 *      0           0           -1
 *      2           1            0
 *      4           2            1 
 *      5           2            1
 *     23           6            5
 *     26           6            5
 *     30           7            8
 */

/*
 * formuleer hieronder het antwoord op vraag 3.c
 * als de waarde kleiner is dan het kleinste getal is de upperbound -1
 * lowerBound = size of array wanneer waarde groter is dan grootste waarde in array
 * waarde valt altijd tussen de indexes van waar hij past.
 */


int IntOrderedArray::getLastElementSmallerOrEqualTo( int x )   const
{
    int l = 0;
    int r = listCount - 1;
    int curIn;

    while (true) {
        curIn = (l + r) / 2;
        if (list[curIn] == x) {
            // found value, how do we know it's the last one
            return x;
        }
        else if (l > r) {
            if (l == listCount) return l; // return size of array is x is biggest number
            else return r;
            // number doesn't exist in array, use nearest upprbound (containing last smaller value;
        }
        else {
            if (list[curIn] < x)
                l = curIn + 1;
            else
                r = curIn - 1;
        }
    }
}

void IntOrderedArray::moveElementsOnePositionToRight( int insertIn )
{
    for (int i = listCount; i > insertIn; i--) {
        if (i != 0)
            list[i] = list[i - 1];
    }
}

int IntOrderedArray::quickInsert( int value )
{
    int in = getLastElementSmallerOrEqualTo(value);
    moveElementsOnePositionToRight(in);
    list[in] = value;
    return 0;
}

void IntOrderedArray::showAll() const
{
}
