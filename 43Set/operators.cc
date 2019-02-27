#include "set.h"

/****************************************************************
 * Overloaded '+' operator, not a 'Set' member function, to be
 * interpreted as set union.
 *
 * Parameters:
 *   set1: the first set of the two to be unioned
 *   set2: the second set of the two to be unioned
 *
 * Returns:
 *   the set union
**/
const Set operator +(const Set& set1, const Set& set2) {
  return set1.SetUnion(set2);
}

/****************************************************************
 * Overloaded BINARY '&' operator, not a 'Set' member function,
 * to be interpreted as set intersection.
 *
 * Parameters:
 *   set1: the first set of the two to be intersected
 *   set2: the second set of the two to be intersected
 *
 * Returns:
 *   the set intersection
**/
const Set operator &(const Set& set1, const Set& set2) {
  return set1.SetIntersection(set2);
}

/****************************************************************
 * Overloaded BINARY '-' operator, not a 'Set' member function,
 * to be interpreted as symmetric set difference.
 *
 * Parameters:
 *   set1: the first set of the two to be differenced
 *   set2: the second set of the two to be differenced
 *
 * Returns:
 *   the symmetric set difference
**/
const Set operator -(const Set& set1, const Set& set2) {
  return set1.SetDifference(set2);
}

/****************************************************************
 * Overloaded '==' operator, not a 'Set' member function, to be
 * interpreted as the usual test of equality of sets.
 *
 * Parameters:
 *   set1: the first set of the two to be unioned
 *   set2: the second set of the two to be unioned
 *
 * Returns:
 *   the 'bool' answer to the question of set equality
**/
const bool operator ==(const Set& set1, const Set& set2) {
    return (set1.Equals(set2));
}

/****************************************************************
 * Overloaded '<<' operator, not a 'Set' member function, that
 * calls the 'toString' to output the set in a formatted way.
 *
 * Parameters:
 *   set1: the first set of the two to be unioned
 *   set2: the second set of the two to be unioned
 *
 * Returns:
 *   the 'ostream' with the formatted string form of the set
**/
ostream& operator <<(ostream& out_stream, const Set& the_set) {
  out_stream << the_set.ToString();

  return out_stream;
}
