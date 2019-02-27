#include "main.h"

static const string kTag = "MAIN: ";

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Example program: basic grocery receipt, with the work of the program done
 * in a separate class.
 *
 * This program reads a sequence of grocery store transactions
 * from an input file, outputs the "receipt", and runs a total.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

/******************************************************************************
 * Function 'main'.
 *
 * We do nothing in the main except invoke a 'doTheWork' function in a class
 * of essentially the same name.
 *
**/
int main( ) {
  string filename = "";
  Scanner in_scanner;
  DoTheWork do_the_work;

  cout << kTag << "Execution beginning\n"; 

  filename = "xinput.txt"; // this is HARD CODED!!!!!!

  cout << kTag << "Reading from filename " << filename << endl; 

  // verify that the file exists so we don't crash
  if(Utils::FileDoesNotExist(filename))
  {
    cout << "File '" << filename << "' does not exist." << endl;
    cout << "Terminating program." << endl; 
    exit(0);
  }

  in_scanner.OpenFile(filename);
  cout << "File '" << filename << "' exists and has been opened." << endl;

  do_the_work.ProcessInput(in_scanner);

  cout << kTag << "Execution ending\n"; 

  return 0;
} // int main( )
