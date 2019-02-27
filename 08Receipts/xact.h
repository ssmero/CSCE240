/****************************************************************
 * Header file for a single grocery receipt transaction.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

#ifndef XACT_H
#define XACT_H

#include <iostream>
using namespace std;

class Xact {
public:
 Xact();
 virtual ~Xact();

 double GetCostPerItem(); // accessor
 string GetItemName(); // accessor
 int GetNumberOfItems(); // accessor

 void ReadData();

private:
 int number_of_items_;
 double cost_per_item_;
 string item_name_;
};

#endif
