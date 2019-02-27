#include "mypair.h"

/****************************************************************
 * Implementation for 'MyPair' templated class
**/

/****************************************************************
 * Default constructor.
**/
template<class T> MyPair<T>::MyPair() {
}

/****************************************************************
 * Constructor with arguments passed in.
 * Parameters:
 *   m: a 'T' object to be assigned to the first of the pair elts
 *   n: a 'T' object to be assigned to the second of the pair elts
 * Output: none
**/
template<class T> MyPair<T>::MyPair(T in_first, T in_second)
{
  first_ = in_first;
  second_ = in_second;
}

/****************************************************************
 * Accessor for the first element.
 *
 * Return:
 *   the 'T' value of the first elt of the pair.
**/
template<class T> T MyPair<T>::GetFirst() {
  return first_;
}
/****************************************************************
 * Mutator for the first element.
 *
 * Parameters:
 *   what: the 'T' object to be assigned to the first elt.
**/
template<class T> void MyPair<T>::SetFirst(T what) {
  first_ = what;
}

/****************************************************************
 * Accessor for the second element.
 *
 * Return:
 *   the 'T' value of the second elt of the pair.
**/
template<class T> T MyPair<T>::GetSecond() {
  return second_;
}
/****************************************************************
 * Mutator for the second element.
 *
 * Parameters:
 *   what: the 'T' object to be assigned to the second elt.
**/
template<class T> void MyPair<T>::SetSecond(T what) {
  second_ = what;
}

/****************************************************************
 * Equals function for the 'T' objects in a 'MyPair'.
 *
 * Parameters:
 *   rhs: We test the 'this' instance of 'MyPair' against the
 *           'rhs' instance of 'MyPair'.
 *
 * Return:
 *   the answer to the 'equals' question
**/
template<class T> bool MyPair<T>::Equals(const MyPair<T>& rhs) {
  return this->TestEquals(first_, rhs.first_);
}

/****************************************************************
 * TestEquals function for integer values.
 * This uses the inherent natural ordering of primitive types.
 *
 * Return:
 *   the answer to the 'equals' question
**/
template<class T> bool MyPair<T>::TestEquals(int a, int b) {
  if (a == b) {
    return true;
  } else {
    return false;
  }
}

/****************************************************************
 * TestEquals function for string values.
 * This uses the inherent natural ordering of 'string' data.
 *
 * Return:
 *   the answer to the 'equals' question
**/
template<class T> bool MyPair<T>::TestEquals(string a, string b) {
  if (a == b) {
    return true;
  } else {
    return false;
  }
}

/****************************************************************
 * TestEquals function for 'Record' values.
 *
 * Return:
 *   the answer to the 'equals' question
**/
template<class T> bool MyPair<T>::TestEquals(Record a, Record b) {
  return a.Equals(b);
}

/****************************************************************
 * Swap function for the 'T' objects in a pair.  This function
 * swaps the first and the second objects, and then it returns
 * the new pair.
 *
 * Return:
 *   the 'MyPair' after swapping the 'first' and 'second' elements.
**/
template<class T> void MyPair<T>::Swap() {
  T temp;
  temp = first_;
  first_ = second_;
  second_ = temp;
}

/****************************************************************
 * The 'ToString' function for a 'MyPair' of 'T' objects.  This
 * function puts parentheses around and a comma between the output
 * of the two 'T' objects, and a 'string' value for each object
 * in the canonical place before and after the comma. 
 * 
 * This function assumes that a 'T' object has an overloaded
 * output operator.
**/
template<class T> string MyPair<T>::ToString() {
  stringstream oss;
  string out_string;

  oss << "(" << first_ << "," << second_ << ")";
  out_string = oss.str();

  return out_string;
}

