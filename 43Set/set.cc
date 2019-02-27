#include "set.h"

static const string kTag = "SET: ";

/****************************************************************
 * Class for handling a mathematical set.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

/****************************************************************
 * Constructor.
**/
Set::Set() {
#ifdef EBUGSET
  Utils::log_stream << kTag << "enter default constructor " << endl;
  Utils::log_stream.flush();
#endif

#ifdef EBUGSET
  Utils::log_stream << kTag << "leave default constructor " << endl;
  Utils::log_stream.flush();
#endif
}

/****************************************************************
 * Constructor of a singleton set.
 *
 * Parameters:
 *   e - the 'int' element to be used to construct the set
**/
Set::Set(int e) {
#ifdef EBUGSET
  Utils::log_stream << kTag << "enter singleton constructor " << e << endl;
  Utils::log_stream.flush();
#endif

  this->AddToSet(e);

#ifdef EBUGSET
  Utils::log_stream << kTag << "leave singleton constructor" << endl;
  Utils::log_stream.flush();
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
Set::Set(const string s) {
#ifdef EBUGSET
  Utils::log_stream << kTag << "enter string constructor " << s << endl;
  Utils::log_stream.flush();
#endif

  ScanLine scanline;
  scanline.OpenString(s);

#ifdef EBUGSET
  Utils::log_stream << kTag << "read '" << s << "'" << endl;
  Utils::log_stream.flush();
#endif

  // if we were given an empty line, let's say so because that might
  // well be an error
  if(0 == s.size()) {
#ifdef EBUGSET
    Utils::log_stream << kTag << "empty line" << endl;
    Utils::log_stream.flush();
#endif
    return;
  }

  // while we have more stuff in the line, pick off the next 'int'
  // and insert that into the structure that holds the elements
  while(scanline.HasMoreData()) {
    // note that this line is the one that causes the program to
    // crash if the next token isn't an 'int' value
    int value = scanline.NextInt();
#ifdef EBUGSET
    Utils::log_stream << kTag << "scanning line and inserting "
                      << value << endl;
    Utils::log_stream.flush();
#endif
    this->AddToSet(value);
  }

#ifdef EBUGSET
  Utils::log_stream << kTag << "leave string constructor" << endl;
  Utils::log_stream.flush();
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
Set::Set(vector<int> v) {
#ifdef EBUGSET
  Utils::log_stream << kTag << "enter set from vector constructor"
                    << endl;
  Utils::log_stream.flush();
#endif

  this->AddToSet(v);

#ifdef EBUGSET
  Utils::log_stream << kTag << "leave set from vector constructor"
                    << endl;
  Utils::log_stream.flush();
#endif
}

/****************************************************************
 * Constructor of this set from another set.
 *
 * Parameters:
 *   theSet - the set to be copied from into a new set
**/
Set::Set(const Set& the_set) {
#ifdef EBUGSET
  Utils::log_stream << kTag << "enter set from set constructor"
                    << endl;
  Utils::log_stream << kTag << the_set.ToString() << endl;
  Utils::log_stream.flush();
#endif

  // NOTE THAT HERE IS WHERE WE COULD USE AN ITERATOR OVER A SET
  // BECAUSE THAT WAY WE COULD AVOID HAVING TO GET THE 'vector' AND
  // THEN USING THAT 'vector' OF ELEMENTS TO ADD TO THE NEW SET.
  // IF WE COULD JUST ITERATE OVER THE INPUT SET PARAMETER, WE COULD
  // AVOID THE INTERMEDIATE STEP USING THE 'vector'.
  // ON THE OTHER HAND, HAVING THE ABILITY TO GET THE 'vector' ALLOWS
  // THIS CODE TO BE REALLY SIMPLE.
  vector<int> vec = the_set.GetElements();
  this->AddToSet(vec);

#ifdef EBUGSET
  Utils::log_stream << kTag << "leave set from set constructor"
                    << endl;
  Utils::log_stream.flush();
#endif
}

/****************************************************************
 * Destructor.
**/
Set::~Set() {
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
bool Set::AddToSet(const int e) {
  int old_size = the_elements_.size();
  the_elements_.insert(e);

  // we want 'true' if old size is not current size, because
  // that means the elt was actually added
  return (old_size != the_elements_.size());
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
bool Set::AddToSet(vector<int> v) {
  int old_size = the_elements_.size();

  vector<int>::iterator iter;
  for(iter = v.begin(); iter != v.end(); ++iter) {
    this->AddToSet(*iter);
  }

  return (old_size != the_elements_.size());
}

/****************************************************************
 * Function to return the cardinality of a set.
 *
 * Returns:
 *   the cardinality of the set
**/
int Set::Card() const {
  return the_elements_.size();
}

/****************************************************************
 * Function to test if an element is contained in a set.
 *
 * Parameters:
 *   e - the elt to be tested for membership
 * Returns:
 *   the answer to the question of containment
**/
bool Set::ContainsElement(const int e) const {
  return (the_elements_.count(e) > 0);
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
bool Set::ContainsSet(const Set& that) const {
  bool return_value = true;
  vector<int> v = that.GetElements();

  vector<int>::iterator iter;
  for(iter = v.begin(); iter != v.end(); ++iter)
  {
    if(!this->ContainsElement( (*iter) ))
    {
      return_value = false;
      break;
    }
  } // for(iter = v.begin(); iter != v.end(); ++iter)

  return return_value;
}

/****************************************************************
 * Function to test if a set equals another set.
 *
 * Parameters:
 *   that - the set to be tested for equality
 * Returns:
 *   the answer to the question of equality
**/
bool Set::Equals(const Set& that) const {
  return (this->ContainsSet(that)) && (that.ContainsSet(*this));
}

/****************************************************************
 * Function to get a 'vector' version of the elements of a set.
 *
 * Returns:
 *   a 'vector' version of the elements of the set
**/
vector<int> Set::GetElements() const {
  vector<int> the_vec;
  set<int>::iterator iter;

  for(iter = the_elements_.begin();
      iter != the_elements_.end(); ++iter) {
    the_vec.push_back( (*iter) );
  }

  return the_vec;
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
bool Set::IsContainedIn(const Set& that) const {
  bool return_value = true;

  set<int>::iterator iter;
  for(iter = the_elements_.begin(); iter != the_elements_.end(); ++iter)
  {
    if(!that.ContainsElement( *iter )) {
      return_value = false;
      break;
    }
  }

  return return_value;
}

/****************************************************************
 * Function to test if a set is empty.
 *
 * Returns:
 *   the answer to the question of emptiness
**/
bool Set::IsEmpty() const {
  return (0 == Card());
}

/****************************************************************
 * Function to remove an element from a set.
 *
 * Parameters:
 *   e - the elt to be removed
 * Returns:
 *   boolean according as the element was there and was removed
**/
bool Set::RemoveFromSet(int e) {
  int old_size = the_elements_.size();
  the_elements_.erase(e);

  // we want 'true' if old size is not current size, because
  // that means the elt was actually added
  return (old_size != the_elements_.size());
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
Set Set::SetDifference(const Set& that) const {
  Set new_set;

  set<int>::iterator iter;
  for(iter = the_elements_.begin();
      iter != the_elements_.end(); ++iter) {
    int e = *iter;
    if(!that.ContainsElement(e)) {
      new_set.AddToSet(e);
    }
  }

  return new_set;
}

/****************************************************************
 * Function to perform set intersection.
 *
 * Parameters:
 *   that - the set to be intersected with 'this'
 * Returns:
 *   the new set that is the intersection of 'this' and 'that'
**/
Set Set::SetIntersection(const Set& that) const {
  Set new_set;

  set<int>::iterator iter;
  for(iter = the_elements_.begin();
      iter != the_elements_.end(); ++iter) {
    if(that.ContainsElement( *iter )) {
      new_set.AddToSet(*iter);
    }
  }

  return new_set;
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
Set Set::SetSymmetricDifference(const Set& that) const {
  Set a_diff_b = this->SetDifference(that);
  Set b_diff_a = that.SetDifference( (*this) );
  Set sym_diff1 = a_diff_b.SetUnion(b_diff_a);

  Set the_union = this->SetUnion(that);
  Set the_intersection = that.SetIntersection(that);
  Set sym_diff2 = the_union.SetDifference(the_intersection);

  if(!sym_diff1.Equals(sym_diff2))
  {
    Utils::log_stream << kTag << "ERROR sym diff" << endl;
    Utils::log_stream << kTag << "one " << sym_diff1.ToString() << endl;
    Utils::log_stream << kTag << "two " << sym_diff2.ToString() << endl;
    Utils::log_stream.flush();
  }

  return sym_diff1;
}

/****************************************************************
 * Function to perform set union.
 *
 * Parameters:
 *   that - the set to be union-ed with 'this'
 * Returns:
 *   the new set that is the union of 'this' and 'that'
**/
Set Set::SetUnion(const Set& that) const {
  Set new_set = that;

  for(set<int>::iterator iter = the_elements_.begin();
                         iter != the_elements_.end(); ++iter) {
    new_set.AddToSet(*iter);
  }

  return new_set;
} // Set Set::SetUnion(const Set& that)

/****************************************************************
 * Usual 'ToString'. This returns a formatted version of the
 * 'vector' that stores the elements of the set. 
 *
 * Returns:
 *   the usual 'ToString'
**/
string Set::ToString() const {
  string s = " {";

  set<int>::const_iterator iter;
  for(iter = the_elements_.begin();
     iter != the_elements_.end(); ++iter) {
    s += Utils::Format( (*iter), 6);
  }
  s += "}";
//  s += "\n";

  return s;
} // string ToString()

