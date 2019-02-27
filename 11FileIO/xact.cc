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
 * Accessor for 'cost_this_transaction_'.
 *
 * Returns:
 *   'cost_this_transaction_'
**/
double Xact::GetCostThisTransaction() {
  return cost_per_item_ * number_of_items_;
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
 * AND WE ASSUME THAT THERE IS IN FACT A 'next' ITEM TO READ
**/
void Xact::ReadData(Scanner& in_scanner) {
  cout << kTag << "enter ReadData\n"; 

  item_name_ = in_scanner.Next();
  number_of_items_ = in_scanner.NextInt();
  cost_per_item_ = in_scanner.NextDouble();

  cout << kTag << "leave ReadData\n"; 

} // void DoTheWork::ReadData()

/******************************************************************************
 * Function 'ToString'.
 *
 * This is the usual 'ToString' that formats this data item for printing.
**/
string Xact::ToString() {
  string s = "";

  cout << kTag << "enter ToString\n"; 

  s += Utils::Format(item_name_, 20, "left");
  s += Utils::Format(number_of_items_, 5);
  s += Utils::Format(cost_per_item_, 6, 2);

  cout << kTag << "leave ToString\n"; 

  return s;
} // void DoTheWork::ToString()
