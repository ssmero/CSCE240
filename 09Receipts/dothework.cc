#include "dothework.h"

static const string kTag = "DOTHEWORK: ";

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'DoTheWork' for the grocery receipt computation. This class has
 * nothing more than a function to read and process the data.
 *
 * Documentation for the functions is given with the functions.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

/******************************************************************************
 * Constructor
**/
DoTheWork::DoTheWork() {
}

/******************************************************************************
 * Destructor
**/
DoTheWork::~DoTheWork() {
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'ProcessInput'.
 *
 * We read the input data into a 'vector' of 'Xact' records.
 * We then process the 'vector' to print the detail, compute a
 * running total, and print the total.
**/
void DoTheWork::ProcessInput() {
  cout << kTag << "enter ProcessInput\n"; 

  // Read the data into the 'vector' named 'the_data_'.
  this->ReadData();

  // Now process the 'vector'.
  // Loop through the entries, compute cost per transaction, and total
  // into the running total.
  running_total_cost_ = 0.0;
  for(int i = 0; i < number_of_transactions_; ++i)
  {
    Xact local_xact = the_data_.at(i);

    // Side note: one could legitimately argue that 'costThisTransaction'
    //            could or should be a value in the 'Xact' class because
    //            it is directly derived from data in that class
    //            YMMV
    cost_this_transaction_ = local_xact.GetNumberOfItems()
                                  * local_xact.GetCostPerItem();
    running_total_cost_ += cost_this_transaction_;

    cout << kTag << local_xact.ToString() << " "
         << " " << Utils::Format(cost_this_transaction_, 7, 2)
         << " " << Utils::Format(running_total_cost_, 7, 2)
         << endl;
  }

  // And print the total.
  cout << kTag << "The total is $" << running_total_cost_ << "." << endl;

  cout << kTag << "leave ProcessInput\n"; 
} // void DoTheWork::ProcessInput()

/******************************************************************************
 * Function 'ReadData'.
 * We read from stdin the input data into a 'vector' of 'Xact' named
 * 'the_data_'.
 * This is simple.
 * Get the number of input transactions, then run a loop to create an
 * instance of 'Xact' and let that instance read itself from the input.
 *
 * THERE IS NO BULLETPROOFING OF THE INPUT.
**/
void DoTheWork::ReadData()
{
  cout << kTag << "enter ReadData\n"; 

  cin >> number_of_transactions_;
  for(int i = 0; i < number_of_transactions_; ++i)
  {
    Xact local_xact = Xact();
    local_xact.ReadData();
    the_data_.push_back(local_xact);
  }

  cout << kTag << "leave ReadData\n"; 
} // void DoTheWork::ReadData()
