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

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class Xact {
public:
 Xact();
 virtual ~Xact();

 double GetCostPerItem();
 double GetCostThisTransaction();
 string GetItemName();
 int GetNumberOfItems();

 void ReadData(Scanner& in_scanner);
 string ToString();

private:
 int number_of_items_;
 double cost_per_item_;
 string item_name_;
};

#endif
