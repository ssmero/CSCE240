#include "Set.h"

/****************************************************************
 * Class for handling a mathematical set.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 14 November 2015
 *
**/

static const string TAG = "Set: ";

/****************************************************************
 * Constructor.
**/
Set::Set()
{
#ifdef EBUGSET
  Utils::logStream << TAG << "enter default constructor " << endl;
  Utils::logStream.flush();
#endif

#ifdef EBUGSET
  Utils::logStream << TAG << "leave default constructor " << endl;
  Utils::logStream.flush();
#endif
}

/****************************************************************
 * Constructor of a singleton set.
 *
 * Parameters:
 *   e - the 'int' element to be used to construct the set
**/
Set::Set(int e)
{
#ifdef EBUGSET
  Utils::logStream << TAG << "enter singleton constructor " << e << endl;
  Utils::logStream.flush();
#endif

  this->addToSet(e);

#ifdef EBUGSET
  Utils::logStream << TAG << "leave singleton constructor" << endl;
  Utils::logStream.flush();
#endif
}

/****************************************************************
 * Constructor of a set from one string of 'int' values. 
 *
 * CAVEAT: We have not bulletproofed this to deal with a string
 * as input that cannot be parsed as 'int' values. As of now, 
 * the function simply dies with the error that is caught by
 * the 'nextInt' function.
 *
 * Parameters:
 *   s - the string to be parsed for elements to add
**/
Set::Set(const string s) 
{
#ifdef EBUGSET
  Utils::logStream << TAG << "enter string constructor " << s << endl;
  Utils::logStream.flush();
#endif

  ScanLine scanLine;
  scanLine.openString(s);

#ifdef EBUGSET
  Utils::logStream << TAG << "read '" << s << "'" << endl;
  Utils::logStream.flush();
#endif

  // if we were given an empty line, let's say so because that might
  // well be an error
  if(0 == s.size())
  {
#ifdef EBUGSET
    Utils::logStream << TAG << "empty line" << endl;
    Utils::logStream.flush();
#endif
    return;
  }

  // while we have more stuff in the line, pick off the next 'int'
  // and insert that into the structure that holds the elements
  while(scanLine.hasMoreData())
  {
    // note that this line is the one that causes the program to
    // crash if the next token isn't an 'int' value
    int value = scanLine.nextInt();
#ifdef EBUGSET
    Utils::logStream << TAG << "scanning line and inserting " << value << endl;
    Utils::logStream.flush();
#endif
    this->addToSet(value);
  }

#ifdef EBUGSET
  Utils::logStream << TAG << "leave string constructor" << endl;
  Utils::logStream.flush();
#endif
}

/****************************************************************
 * Constructor of a set from a 'vector' of 'int' values.
 *
 * Note that if the vector is empty, then things still work ok
 * because we are iterating over the elements. Nothing we do in
 * this function requires the 'vector' to have any values.
 *
 * Parameters:
 *   v - the 'vector' to use as elements for the set
**/
Set::Set(vector<int> v)
{
#ifdef EBUGSET
  Utils::logStream << TAG << "enter set from vector constructor" << endl;
  Utils::logStream.flush();
#endif

  this->addToSet(v);

#ifdef EBUGSET
  Utils::logStream << TAG << "leave set from vector constructor" << endl;
  Utils::logStream.flush();
#endif
}

/****************************************************************
 * Constructor of this set from another set.
 *
 * Parameters:
 *   theSet - the set to be copied from into a new set
**/
Set::Set(const Set& theSet)
{
#ifdef EBUGSET
  Utils::logStream << TAG << "enter set from set constructor" << endl;
  Utils::logStream << TAG << theSet.toString() << endl;
  Utils::logStream.flush();
#endif

  // NOTE THAT HERE IS WHERE WE COULD USE AN ITERATOR OVER A SET
  // BECAUSE THAT WAY WE COULD AVOID HAVING TO GET THE 'vector' AND
  // THEN USING THAT 'vector' OF ELEMENTS TO ADD TO THE NEW SET.
  // IF WE COULD JUST ITERATE OVER THE INPUT SET PARAMETER, WE COULD
  // AVOID THE INTERMEDIATE STEP USING THE 'vector'.
  // ON THE OTHER HAND, HAVING THE ABILITY TO GET THE 'vector' ALLOWS
  // THIS CODE TO BE REALLY SIMPLE.
  vector<int> vec = theSet.getElements();
  this->addToSet(vec);

#ifdef EBUGSET
  Utils::logStream << TAG << "leave set from set constructor" << endl;
  Utils::logStream.flush();
#endif
}

/****************************************************************
 * Destructor.
**/
Set::~Set()
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
bool Set::addToSet(const int e)
{
  int oldSize = this->theElements.size();
  this->theElements.insert(e);

  // we want 'true' if old size is not current size, because
  // that means the elt was actually added
  return (oldSize != this->theElements.size());
}

/****************************************************************
 * Function to add a 'vector' of 'int' elements to an existing set.
 *
 * Parameters:
 *   v - the 'vector' of 'int' to be added to the set (if not
 *       already there)
 * Returns:
 *   true or false according as elements were added or not
**/
bool Set::addToSet(vector<int> v)
{
  int oldSize = this->theElements.size();

  vector<int>::iterator iter;
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
int Set::card() const
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
bool Set::containsElement(const int e) const
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
bool Set::containsSet(const Set& that) const
{
  bool returnValue = true;
  vector<int> v = that.getElements();

  vector<int>::iterator iter;
  for(iter = v.begin(); iter != v.end(); ++iter)
  {
    if(!this->containsElement( (*iter) ))
    {
      returnValue = false;
      break;
    }
  } // for(iter = v.begin(); iter != v.end(); ++iter)

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
bool Set::equals(const Set& that) const
{
  return (this->containsSet(that)) && (that.containsSet(*this));
}

/****************************************************************
 * Function to get a 'vector' version of the elements of a set.
 *
 * Returns:
 *   a 'vector' version of the elements of the set
**/
vector<int> Set::getElements() const
{
  vector<int> theVec;
  set<int>::iterator iter;

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
bool Set::isContainedIn(const Set& that) const
{
  bool returnValue = true;

  set<int>::iterator iter;
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
bool Set::isEmpty() const
{
  return (0 == this->card());
}

/****************************************************************
 * Function to remove an element from a set.
 *
 * Parameters:
 *   e - the elt to be removed
 * Returns:
 *   boolean according as the element was there and was removed
**/
bool Set::removeFromSet(int e)
{
  int oldSize = this->theElements.size();
  this->theElements.erase(e);

  // we want 'true' if old size is not current size, because
  // that means the elt was actually added
  return (oldSize != this->theElements.size());
}

/****************************************************************
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
Set Set::setDifference(const Set& that) const
{
  Set newSet;

  set<int>::iterator iter;
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
Set Set::setIntersection(const Set& that) const
{
  Set newSet;

  set<int>::iterator iter;
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
Set Set::setSymmetricDifference(const Set& that) const
{
  Set aDiffB = this->setDifference(that);
  Set bDiffA = that.setDifference( (*this) );
  Set symDiff1 = aDiffB.setUnion(bDiffA);

  Set theUnion = this->setUnion(that);
  Set theIntersection = that.setIntersection(that);
  Set symDiff2 = theUnion.setDifference(theIntersection);

  if(!symDiff1.equals(symDiff2))
  {
    Utils::logStream << TAG << "ERROR sym diff" << endl;
    Utils::logStream << TAG << "one " << symDiff1.toString() << endl;
    Utils::logStream << TAG << "two " << symDiff2.toString() << endl;
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
Set Set::setUnion(const Set& that) const
{
  Set newSet = that;

  for(set<int>::iterator iter = this->theElements.begin();
                         iter != this->theElements.end(); ++iter)
  {
    newSet.addToSet(*iter);
  }

  return newSet;
} // Set Set::setUnion(const Set& that)

/****************************************************************
 * Usual 'toString'. This returns a formatted version of the
 * 'vector' that stores the elements of the set. 
 *
 * Returns:
 *   the usual 'toString'
**/
string Set::toString() const
{
  string s = " {";

  set<int>::const_iterator iter;
  for(iter = this->theElements.begin();
     iter != this->theElements.end(); ++iter)
  {
    s += Utils::Format( (*iter), 6);
  }
  s += "}";
//  s += "\n";

  return s;
} // string toString()

