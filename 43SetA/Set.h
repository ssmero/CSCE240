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

class Set
{
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
  Set(); // default
  Set(int n); // create a set from a single integer
  Set(string s); // create a set by parsing a string for integers
  Set(vector<int> v); // create a set from a vector of integers
  Set(const Set& theSet); // create a set from another set
  virtual ~Set();

/****************************************************************
 * General functions.
**/
  bool addToSet(const int e);
  bool addToSet(vector<int> v);
  int card() const;
  bool containsElement(const int e) const;
  bool containsSet(const Set& that) const;
  bool equals(const Set& that) const;
  vector<int> getElements() const;
  bool isContainedIn(const Set& that) const;
  bool isEmpty() const;
  bool removeFromSet(const int e);
  string toString() const;

  Set setDifference(const Set& that) const;
  Set setIntersection(const Set& that) const;
  Set setSymmetricDifference(const Set& that) const;
  Set setUnion(const Set& that) const;

  friend const Set operator +(const Set& set1, const Set& set2); // union
  friend const Set operator &(const Set& set1, const Set& set2); // intersection
  friend const Set operator -(const Set& set1, const Set& set2); // sym diff
  friend const bool operator ==(const Set& set1, const Set& set2);
  friend ostream& operator <<(ostream& outputStream, const Set& theSet);

private:
  set<int> theElements;

/****************************************************************
 * General private functions.
**/
};

#endif // SET_H
