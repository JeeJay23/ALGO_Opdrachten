// ALGO_Week2Deel1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "bubbleSorter.h"
#include "NAWOrderedArray.h"

int main()
{
    // opdr 1
    // bubbleSorter s;
    // s.sort();

    // opdr 2
    /*
    * stabiliteits test. NAW is aangepast zodat het een id heeft. 
    * deze is alleen voor identificatie, en beinvloedt het sorteren niet.

    * RESULTATEN
    * originele lijst                           = [ 0, 1, 2, 3, 4 ]
    * Verwachtte uitkomst met stabiel algoritme = [ 1, 0, 2, 3, 4 ]
    * Uitkomst                                  = [ 1, 0, 3, 2, 4 ]
    * relatieve positie wordt niet behouden tussen dezelfde elementen, 
    * dus het algoritme is onstabiel.
    * Is ook logisch aangezien de >= ervoor zorgt dat elementen worden 
    * omgewisselt ook wanneer ze hetzelfde zijn
    */

    NAWOrderedArray arr;
    arr.dirty_add( { "Jan", "Wilhelmsingel", "Den Bosch",   0 } );
    arr.dirty_add( { "Jan", "Wilhelmsingel", "Amsterdam",   1 } );
    arr.dirty_add( { "Jan", "Wilhelmsingel", "Den Bosch",   2 } );
    arr.dirty_add( { "Jan", "Wilhelmsingel", "Den Bosch",   3 } );
    arr.dirty_add( { "Jan", "Wilhelmsingel", "Sneek",       4 } );
    arr.sort();
    arr.showAll();
}

/*
* bubblesort is een O(N^2) algoritme omdat het voor elk item in de array door de hele array moet lopen. 
*/
