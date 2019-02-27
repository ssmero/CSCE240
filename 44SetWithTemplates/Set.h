/****************************************************************
 * Header for the 'Set' class
 *
 * Author/copyright:  Duncan Buell
 * Date: 11 May 2013
 *
**/

#ifndef SET_H
#define SET_H

#include <vector>
#include <set>

using namespace std;

#include "../../Utilities/Utils.h"
#include "../../Utilities/Scanner.h"
#include "../../Utilities/ScanLine.h"

template<class T> class Set
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  Set(); // default
  Set(T n); // create a set from a single element
//  Set(string s); // create a set by parsing a string for element
  Set(vector<T> v); // create a set from a vector of element
  Set(const Set& theSet); // create a set from another set
  virtual ~Set();

/****************************************************************
 * General functions.
**/
  bool addToSet(const T e);
  bool addToSet(vector<T> v);
  int card() const;
  bool containsElement(const T e) const;
  bool containsSet(const Set& that) const;
  bool equals(const Set& that) const;
  vector<T> getElements() const;
  bool isContainedIn(const Set& that) const;
  bool isEmpty() const;
  bool removeFromSet(const T e);
  string toString() const;

  Set setDifference(const Set& that) const;
  Set setIntersection(const Set& that) const;
  Set setSymmetricDifference(const Set& that) const;
  Set setUnion(const Set& that) const;

//  friend const Set<T> operator +(const Set<T>& set1, const Set<T>& set2); // union
//  friend const Set operator &(const Set& set1, const Set& set2); // intersection
//  friend const Set operator -(const Set& set1, const Set& set2); // sym diff
//  friend const bool operator ==(const Set& set1, const Set& set2);
//  friend ostream& operator <<(ostream& outputStream, const Set& theSet);

private:
  set<T> theElements;

/****************************************************************
 * General private functions.
**/
};

#endif // SET_H
