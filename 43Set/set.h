/****************************************************************
 * Header for the 'Set' class
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

#ifndef SET_H
#define SET_H

#include <vector>
#include <set>

using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class Set {
public:
/****************************************************************
 * Constructors and destructors for the class. 
**/
 Set(); // default
 Set(int n); // create a set from a single integer
 Set(string s); // create a set by parsing a string for integers
 Set(vector<int> v); // create a set from a vector of integers
 Set(const Set& the_set); // create a set from another set
 virtual ~Set();

/****************************************************************
 * General functions.
**/
 bool AddToSet(const int e);
 bool AddToSet(vector<int> v);
 int Card() const;
 bool ContainsElement(const int e) const;
 bool ContainsSet(const Set& that) const;
 bool Equals(const Set& that) const;
 vector<int> GetElements() const;
 bool IsContainedIn(const Set& that) const;
 bool IsEmpty() const;
 bool RemoveFromSet(const int e);
 string ToString() const;

 Set SetDifference(const Set& that) const;
 Set SetIntersection(const Set& that) const;
 Set SetSymmetricDifference(const Set& that) const;
 Set SetUnion(const Set& that) const;

 friend const Set operator +(const Set& set1, const Set& set2); // union
 friend const Set operator &(const Set& set1, const Set& set2); // intersection
 friend const Set operator -(const Set& set1, const Set& set2); // sym diff
 friend const bool operator ==(const Set& set1, const Set& set2);
 friend ostream& operator <<(ostream& out_stream, const Set& the_set);

private:
 set<int> the_elements_;

/****************************************************************
 * General private functions.
**/
};

#endif // SET_H
