/****************************************************************
 * Example iterator program from cplusplus.com, modified to use
 * a private array in a separate class.
 *
 * Author/copyright:  Duncan Buell, Brian Flick.
 *                    All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

#include "myarray.h"

using namespace std;

/****************************************************************
 * Constructor.
 *
 * We build an array of 10 'Record' instances, each of which
 * is just a dummy/placeholder. This is just to allocate the
 * space, and we set the 'length' variable to 0 so we can use
 * that variable as the length of that part of the array we have
 * actually put data into.
**/
MyArray::MyArray() {
  Record rec;
  rec = Record();
  for(int i = 0; i < 10; ++i) array_[i] = rec;
  length_ = 0; // this is the number of array locations actually
              // used to hold real data
} // MyArray()

/****************************************************************
 * add a record unless it would overrun the array
**/
void MyArray::Add(Record rec) {
  if(length_ < 10)
  {
    array_[length_] = rec;
    ++length_;
  }
} // void Add(Record rec)

/****************************************************************
 * return the beginning iterator value
**/
MyArray::MyIterator MyArray::begin() {
  MyArray::MyIterator from(array_);
  return from;
} // MyIterator begin()

/****************************************************************
 * return the ending iterator value
**/
MyArray::MyIterator MyArray::end() {
  MyArray::MyIterator until(array_+length_);
  return until;
} // MyIterator end()

/****************************************************************
 * usual tostring
**/
string MyArray::ToString() {
  string s = "";

  for(int i = 0; i < length_; ++i) s += array_[i].ToString() + "\n";

  return s;
} // string toString()
