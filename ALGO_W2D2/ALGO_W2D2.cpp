// ALGO_W2D2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "SelectionSorter.h"
#include "InsertionSorter.h"

int main()
{
	// Opdr 1
	SelectionSorter sSorter;
	sSorter.sort();

	// Opdr 2
	InsertionSorter iSorter;
	iSorter.sort();

	/*
	* Insertion sort is een O(N^2) algoritme omdat het maximaal N * (N-1)/2 keer
	* runt. (eerste keer is er maar 1 vergelijking, 2e keer max 2, 
	* 3e keer max 3, etc...)
	* Dit kan omgeschreven worden naar N^2 * -1/2. Constanten kunnen weg gelaten
	* worden dus dit eindigt op N^2.
	* 
	* Voor gesorteerde lijsten is er maximaal 1 vergelijking per stap dus is 
	* het algoritme daar O(N). 
	*/
}

