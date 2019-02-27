/****************************************************************
 * Example iterator program from cplusplus.com, modified to use
 * a private array in a separate class.
 *
 * Author/copyright:  Duncan Buell, Brian Flick.
 *                    All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

#include "../../Utilities/utils.h"

#include "record.h"

using namespace std;

class MyArray {
  private:
#include "myiterator.h" // this makes the iterator private
 Record array_[10];
 int length_;

  public:

 typedef MyIterator TheIterator;

 /////////////////////////////////////////////////////////////
 // Constructor.
 MyArray();

 /////////////////////////////////////////////////////////////
 // add a record unless it would overrun the array
 void Add(Record rec);

 /////////////////////////////////////////////////////////////
 // return the beginning and ending iterator values
 MyIterator begin();
 MyIterator end();

 /////////////////////////////////////////////////////////////
 // usual tostring
 string ToString();

}; // class MyArray
