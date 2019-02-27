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
void DoTheWork::ProcessInput(Scanner& in_scanner) {
  double cost_this_transaction = 0.0;
  cout << kTag << "enter ProcessInput\n"; 

  // Read the data into the 'vector' named 'the_data_'.
  this->ReadData(in_scanner);

  // Now process the 'vector'.
  // Loop through the entries, compute cost per transaction, and total
  // into the running total.
  running_total_cost_ = 0.0;
  for(int i = 0; i < number_of_transactions_; ++i) {
    Xact local_xact = the_data_.at(i);

    cost_this_transaction = local_xact.GetCostThisTransaction();
    this->running_total_cost_ += cost_this_transaction;

    cout << kTag << local_xact.ToString() << " "
         << " " << Utils::Format(cost_this_transaction, 7, 2)
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
void DoTheWork::ReadData(Scanner& in_scanner) {
  cout << kTag << "enter ReadData\n"; 

  while (in_scanner.HasNext()) {
    Xact local_xact = Xact();
    local_xact.ReadData(in_scanner);
    the_data_.push_back(local_xact);
  }

  number_of_transactions_ = the_data_.size();

  cout << kTag << "leave ReadData\n"; 
} // void DoTheWork::ReadData()
