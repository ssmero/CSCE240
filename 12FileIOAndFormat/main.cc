#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Example program to demonstrate file I/O using the utilities.
 *
 * This program reads a sequence of grocery store transactions
 * and just prints them to the console, finishing with a total.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

/****************************************************************
 * Function 'main'.
 *
 * We use the 240-provided utilities code for opening files and
 * for scanning input data in the way that Java does.
 * As we read, we output the running grocery receipt and keep a
 * running total, which is then output at the end.
 *
**/
int main( ) {

  int number_of_items = 0;
  double cost_per_item = 0.0;
  double running_total = 0.0;
  double total_this_item = 0.0;
  string filename = "dummy_filename";
  string item = "dummy_itemname";
  string out_string = "dummy_out_string";
  Scanner in_scanner;

  cout << "Execution beginning\n"; 
  cout << "Reading from hard coded file name\n"; 

  filename = "xinput.txt"; // this has been HARD CODED IN THIS EXAMPLE

  if(Utils::FileDoesNotExist(filename)) {
    cout << "File '" << filename << "' does not exist." << endl;
    cout << "Terminating program." << endl; 
    exit(0);
  } 

  in_scanner.OpenFile(filename);
  cout << "File '" << filename << "' exists and has been opened." << endl;

  running_total = 0.0;
  while(in_scanner.HasNext()) {
    item = in_scanner.Next();
    number_of_items = in_scanner.NextInt();
    cost_per_item = in_scanner.NextDouble();

    total_this_item = number_of_items * cost_per_item;
    running_total += total_this_item;

    out_string = "";
    out_string += Utils::Format(number_of_items, 5) + " ";
    out_string += Utils::Format(item, 20, "left") + " ";
    out_string += "@ " + Utils::Format(cost_per_item, 8, 2) + " ";
    out_string += Utils::Format(total_this_item, 8, 2) + " ";
    out_string += Utils::Format(running_total, 8, 2) + "\n";
    cout << out_string;
  }

  cout << "Final Total $" << running_total << endl;

  cout << "Execution ending\n"; 

  return 0;
} // int main( )

