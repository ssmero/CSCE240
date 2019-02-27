#include "Set.h"

/****************************************************************
 * Class for handling a mathematical set.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 15 July 2015
 *
**/

static const string SETTAG = "Set: ";

/****************************************************************
 * Constructor.
**/
template<typename T> Set<T>::Set()
{
#ifdef EBUGSET
  Utils::logStream << SETTAG << "enter default constructor " << endl;
  Utils::logStream.flush();
#endif

#ifdef EBUGSET
  Utils::logStream << SETTAG << "leave default constructor " << endl;
  Utils::logStream.flush();
#endif
}

/****************************************************************
 * Constructor of a singleton set.
 *
 * Parameters:
 *   e - the 'T' element to be used to construct the set
**/
template<typename T> Set<T>::Set(T e)
{
#ifdef EBUGSET
  Utils::logStream << SETTAG << "enter singleton constructor " << e << endl;
  Utils::logStream.flush();
#endif

  this->theElements.insert(e);

#ifdef EBUGSET
  Utils::logStream << SETTAG << "leave singleton constructor" << endl;
  Utils::logStream.flush();
#endif
}

/****************************************************************
 * Constructor of a set from a 'vector' of 'T' values.
 *
 * Note that if the vector is empty, then things still work ok
 * because we are iterating over the elements. Nothing we do in
 * this function requires the 'vector' to have any values.
 *
 * Parameters:
 *   v - the 'vector' to use as elements for the set
**/
template<typename T> Set<T>::Set(vector<T> v)
{
#ifdef EBUGSET
  Utils::logStream << SETTAG << "enter set from vector constructor" << endl;
  Utils::logStream.flush();
#endif

  this->addToSet(v);

#ifdef EBUGSET
  Utils::logStream << SETTAG << "leave set from vector constructor" << endl;
  Utils::logStream.flush();
#endif
}

/****************************************************************
 * Constructor of this set from another set.
 *
 * Parameters:
 *   theSet - the set to be copied from into a new set
**/
template<typename T> Set<T>::Set(const Set<T>& theSet)
{
#ifdef EBUGSET
  Utils::logStream << SETTAG << "enter set from set constructor" << endl;
  Utils::logStream << SETTAG << theSet.toString() << endl;
  Utils::logStream.flush();
#endif

  // NOTE THAT HERE IS WHERE WE COULD USE AN ITERATOR OVER A SET
  // BECAUSE THAT WAY WE COULD AVOID HAVING TO GET THE 'vector' AND
  // THEN USING THAT 'vector' OF ELEMENTS TO ADD TO THE NEW SET.
  // IF WE COULD JUST ITERATE OVER THE INPUT SET PARAMETER, WE COULD
  // AVOID THE INTERMEDIATE STEP USING THE 'vector'.
  // ON THE OTHER HAND, HAVING THE ABILITY TO GET THE 'vector' ALLOWS
  // THIS CODE TO BE REALLY SIMPLE.
  vector<T> vec = theSet.getElements();
  this->addToSet(vec);

#ifdef EBUGSET
  Utils::logStream << SETTAG << "leave set from set constructor" << endl;
  Utils::logStream.flush();
#endif
}

/****************************************************************
 * Destructor.
**/
template<typename T> Set<T>::~Set()
{
}

/****************************************************************
 * Accessors and mutators.
**/
/****************************************************************
 *
**/
/****************************************************************
 * General functions.
**/

/****************************************************************
 * Function to add an element to an existing set.
 *
 * Parameters:
 *   e - the elt to be added to the set (if not already there)
 * Returns:
 *   true or false according as the element was added or not
**/
template<typename T> bool Set<T>::addToSet(const T e)
{
  int oldSize = this->theElements.size();
  this->theElements.insert(e);

  // we want 'true' if old size is not current size, because
  // that means the elt was actually added
  return (oldSize != this->theElements.size());
}

/****************************************************************
 * Function to add a 'vector' of 'T' elements to an existing set.
 *
 * Parameters:
 *   v - the 'vector' of 'T' to be added to the set (if not
 *       already there)
 * Returns:
 *   true or false according as elements were added or not
**/
template<typename T> bool Set<T>::addToSet(vector<T> v)
{
  int oldSize = this->theElements.size();

  typename vector<T>::iterator iter;
  for(iter = v.begin(); iter != v.end(); ++iter)
  {
    this->addToSet(*iter);
  }

  return (oldSize != this->theElements.size());
}

/****************************************************************
 * Function to return the cardinality of a set.
 *
 * Returns:
 *   the cardinality of the set
**/
template<typename T> int Set<T>::card() const
{
  return this->theElements.size();
}

/****************************************************************
 * Function to test if an element is contained in a set.
 *
 * Parameters:
 *   e - the elt to be tested for membership
 * Returns:
 *   the answer to the question of containment
**/
template<typename T> bool Set<T>::containsElement(const T e) const
{
  return (this->theElements.count(e) > 0);
}

/****************************************************************
 * Function to test if 'this' set contains 'that' set.
 *
 * NOTE THAT HERE IS WHERE WE COULD USE AN ITERATOR OVER A SET
 * BECAUSE THAT WAY WE COULD AVOID HAVING TO GET THE 'vector' AND
 * THEN USING THAT 'vector' OF ELEMENTS TO ADD TO THE NEW SET.
 * IF WE COULD JUST ITERATE OVER THE INPUT SET PARAMETER, WE COULD
 * AVOID THE INTERMEDIATE STEP USING THE 'vector'.
 *
 * Parameters:
 *   that - the set to be tested for containment
 * Returns:
 *   the answer to the question of containment
**/
template<typename T> bool Set<T>::containsSet(const Set<T>& that) const
{
  bool returnValue = true;
  vector<T> v = that.getElements();

  typename vector<T>::iterator iter;
  for(iter = v.begin(); iter != v.end(); ++iter)
  {
    if(!this->containsElement( *iter ))
    {
      returnValue = false;
      break;
    }
  }

  return returnValue;
}

/****************************************************************
 * Function to test if a set equals another set.
 *
 * Parameters:
 *   that - the set to be tested for equality
 * Returns:
 *   the answer to the question of equality
**/
template<typename T> bool Set<T>::equals(const Set<T>& that) const
{
  return (this->containsSet(that)) && (that.containsSet(*this));
}

/****************************************************************
 * Function to get a 'vector' version of the elements of a set.
 *
 * Returns:
 *   a 'vector' version of the elements of the set
**/
template<typename T> vector<T> Set<T>::getElements() const
{
  vector<T> theVec;
  typename set<T>::iterator iter;

  for(iter = this->theElements.begin();
      iter != this->theElements.end(); ++iter)
  {
    theVec.push_back( (*iter) );
  }

  return theVec;
}

/****************************************************************
 * Function to test if a set is contained in another set.
 *
 * NOTE that this is the easy direction for testing, because we
 * know how to get to the elements of 'this', and we have a
 * simple function for testing if an element is in another set.
 *
 * Parameters:
 *   that - the set to be tested for containing
 * Returns:
 *   the answer to the question of containing
**/
template<typename T> bool Set<T>::isContainedIn(const Set<T>& that) const
{
  bool returnValue = true;

  typename set<T>::iterator iter;
  for(iter = this->theElements.begin(); iter != this->theElements.end(); ++iter)
  {
    if(!that.containsElement( *iter ))
    {
      returnValue = false;
      break;
    }
  }

  return returnValue;
}

/****************************************************************
 * Function to test if a set is empty.
 *
 * Returns:
 *   the answer to the question of emptiness
**/
template<typename T> bool Set<T>::isEmpty() const
{
  return (0 == this->card());
}

/****************************************************************
 * Function to remove an element from a set.
 * THIS DOES NOTHING IF THE ELEMENT IS NOT IN THE SET.
 *
 * Parameters:
 *   e - the elt to be removed
 * Returns:
 *   the element removed
**/
template<typename T> bool Set<T>::removeFromSet(T e)
{
  return (this->theElements.erase(e) > 0);
}

/***************************************************************
 * Function to perform set difference of two sets.
 *
 * We iterate over the elements of 'this'. If the element is NOT
 * in 'that', then we add it to a 'Set' we are building up and
 * that is eventually returned.
 *
 * NOTE that this is not the same as the "symmetric" difference.
 *
 * Parameters:
 *   that - the set to be differenced with 'this'
 * Returns:
 *   the new set that is the difference of 'this' and 'that'
**/
template<typename T> Set<T> Set<T>::setDifference(const Set<T>& that) const
{
  Set<T> newSet;

  typename set<T>::iterator iter;
  for(iter = this->theElements.begin(); iter != this->theElements.end(); ++iter)
  {
    int e = *iter;
    if(!that.containsElement(e))
    {
      newSet.addToSet(e);
    }
  }

  return newSet;
}

/****************************************************************
 * Function to perform set intersection.
 *
 * Parameters:
 *   that - the set to be intersected with 'this'
 * Returns:
 *   the new set that is the intersection of 'this' and 'that'
**/
template<typename T> Set<T> Set<T>::setIntersection(const Set<T>& that) const
{
  Set<T> newSet;

  typename set<T>::iterator iter;
  for(iter = this->theElements.begin();
      iter != this->theElements.end(); ++iter)
  {
    if(that.containsElement( *iter ))
    {
      newSet.addToSet(*iter);
    }
  }

  return newSet;
}

/****************************************************************
 * Function to perform symmetric set difference of two sets.
 *
 * The symmetric difference of A and B is
 *   (A - B) union (B - A)
 *
 * Parameters:
 *   that - the set to be differenced with 'this'
 * Returns:
 *   the new set that is the symmetric difference of 'this' and 'that'
**/
template<typename T> Set<T> Set<T>::setSymmetricDifference(const Set<T>& that) const
{
  Set<T> aDiffB = this->setDifference(that);
  Set<T> bDiffA = that.setDifference( (*this) );
  Set<T> symDiff1 = aDiffB.setUnion(bDiffA);

  Set<T> theUnion = this->setUnion(that);
  Set<T> theIntersection = that.setIntersection(that);
  Set<T> symDiff2 = theUnion.setDifference(theIntersection);

  if(!symDiff1.equals(symDiff2))
  {
    Utils::logStream << SETTAG << "ERROR sym diff" << endl;
    Utils::logStream << SETTAG << "one " << symDiff1.toString() << endl;
    Utils::logStream << SETTAG << "two " << symDiff2.toString() << endl;
    Utils::logStream.flush();
  }

  return symDiff1;
}

/****************************************************************
 * Function to perform set union.
 *
 * Parameters:
 *   that - the set to be union-ed with 'this'
 * Returns:
 *   the new set that is the union of 'this' and 'that'
**/
template<typename T> Set<T> Set<T>::setUnion(const Set<T>& that) const
{
  Set<T> newSet = that;

  for(typename set<T>::iterator iter = this->theElements.begin();
                         iter != this->theElements.end(); ++iter)
  {
    newSet.addToSet(*iter);
  }

  return newSet;
}

/****************************************************************
 * Usual 'toString'. This returns a formatted version of the
 * 'vector' that stores the elements of the set.
 *
 * CAVEAT: this only works for templated values for which there is
 * a function in the list of 'Utils' 'Format' functions.
 *
 * Returns:
 *   the usual 'toString'
**/
template<typename T> string Set<T>::toString() const
{
  string s = " {";

  typename set<T>::const_iterator iter;
  for(iter = this->theElements.begin();
      iter != this->theElements.end(); ++iter)
  {
    s += Utils::Format( *iter ) + " ";
  }
  s += "}";

  return s;
} // string toString()

