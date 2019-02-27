/****************************************************************
 * Header for 'MyPair' templated class.
**/

#ifndef MYPAIR_H_
#define MYPAIR_H_

#include <cstdlib>
// #include <iostream>
#include <sstream>
#include <string>

using namespace std;

template<class T> class MyPair {
public:
 T first_;
 T second_;

 MyPair();
 MyPair(T in_first, T in_second);

 T GetFirst();
 T GetSecond();
 void SetFirst(T what);
 void SetSecond(T what);

 void Swap();
 string ToString();

private:

};

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
 * Swap function for the 'T' objects in a pair.  This function
 * swaps the first and the second objects, and then it returns
 * the new pair.
 *
 * Return:
 *   the 'Pair' after swapping the 'first' and 'second' elements.
**/
template<class T> void MyPair<T>::Swap() {
  T temp;
  temp = first_;
  first_ = second_;
  second_ = temp;
}

/****************************************************************
 * The 'ToString' function for a 'Pair' of 'T' objects.  This
 * function puts parentheses around and a comma between the output
 * of the two 'T' objects, and a 'string' value for each object
 * in the canonical place before and after the comma. 
 * 
 * This function assumes that if a 'T' object is not in fact 
 * an 'int', then the object class has its own 'toString' function
 * that can be invoked.
**/
template<class T> string MyPair<T>::ToString() {
  stringstream oss;
  string out_string;

  oss << "(" << first_ << "," << second_ << ")";
  out_string = oss.str();

  return out_string;
}

#endif /*MYPAIR_H_*/

