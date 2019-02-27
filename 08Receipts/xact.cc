#include "xact.h"

static const string kTag = "XACT: ";

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'Xact' for a single grocery receipt transaction. This class is
 * just the data payload.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

/******************************************************************************
 * Constructor
**/
Xact::Xact() {
}

/******************************************************************************
 * Destructor
**/
Xact::~Xact() {
}

/******************************************************************************
 * Accessors and Mutators
**/
/******************************************************************************
 * Accessor for 'cost_per_item_'.
 *
 * Returns:
 *   'cost_per_item_'
**/
double Xact::GetCostPerItem() {
  return cost_per_item_;
}
/******************************************************************************
 * Accessor for 'item_name_'.
 *
 * Returns:
 *   'item_name_'
**/
string Xact::GetItemName() {
  return item_name_;
}
/******************************************************************************
 * Accessor for 'number_of_items_'.
 *
 * Returns:
 *   the 'number_of_items_'
**/
int Xact::GetNumberOfItems() {
  return number_of_items_;
}

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'ReadData'.
 *
 * We read the distinct lines of input data. Each line is a label
 * of the item, the number bought, and the cost per item.
 *
 * THERE IS NO BULLETPROOFING OF THE INPUT DATA.
**/
void Xact::ReadData() {
  cout << kTag << "enter ReadData\n"; 

  cin >> item_name_;
  cin >> number_of_items_;
  cin >> cost_per_item_;

  cout << kTag << "leave ReadData\n"; 

} // void DoTheWork::ReadData()
