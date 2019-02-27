#include "dothework.h"

static const string kTag = "DOTHEWORK: ";

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Code to show 'new' usage.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 9 July 2016
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
 * Function 'GetPtr'.
int* DoTheWork::GetPtr() {
  return saved_pointer_;
}
**/

/******************************************************************************
 * Function 'TestNew1'.
**/
void DoTheWork::TestNew1(Record* rec_ptr)
{
  cout << endl << kTag << "enter TestNew1\n"; 

  Record* rec1_ptr = new Record();
  rec1_ptr->SetValue("the value");
  
  rec_ptr = rec1_ptr;

  cout << "ONE " << rec1_ptr << " " << (*rec1_ptr).ToString() << endl;

  cout << kTag << "leave TestNew1" << endl << endl;
} // void DoTheWork::TestNew1()

/******************************************************************************
 * Function 'TestNew2'.
void DoTheWork::TestNew2()
{
  ScanLine scanline;

  cout << endl << kTag << "enter TestNew2\n"; 

  cout << "TWO A " << saved_pointer_ << " " << *saved_pointer_ << endl << endl;

  int *i1_ptr = new int(19);
  int *i2_ptr = new int(23);
  cout << "TWO B " << i1_ptr << " " << *i1_ptr << endl;
  cout << "TWO C " << i2_ptr << " " << *i2_ptr << endl;

  saved_pointer_ = i1_ptr;

  cout << kTag << "leave TestNew2" << endl << endl;
} // void DoTheWork::TestNew2()
**/

/******************************************************************************
 * Function 'TestNew3'.
void DoTheWork::TestNew3()
{
  ScanLine scanline;

  cout << endl << kTag << "enter TestNew3\n"; 

  cout << "THR A " << saved_pointer_ << " " << *saved_pointer_ << endl << endl;

  int *i1_ptr = new int(29);
  int *i2_ptr = new int(31);
  cout << "THR B " << i1_ptr << " " << *i1_ptr << endl;
  cout << "THR C " << i2_ptr << " " << *i2_ptr << endl;

  cout << "THR D " << i1_ptr << " " << *i1_ptr << endl;

  saved_pointer_ = i1_ptr;

  cout << kTag << "leave TestNew3" << endl;
} // void DoTheWork::TestNew3()
**/

