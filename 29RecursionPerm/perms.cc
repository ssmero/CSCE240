#include "perms.h"

static const string kTag = "PERMS: ";

/****************************************************************
 * Class for doing permutations.
 * This class is essentially just a wrapper for the 'GenPerms'
 * and 'DoPerms' functions that set up the generation of perms
 * recursively compute them, building up a string of them to
 * be returned. 
 *
 * We read in the tokens to be permuted and put them in a 
 * vector. Then we call the recursive function.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

/****************************************************************
 * Constructor.
**/
Perms::Perms() {
}

/****************************************************************
 * Destructor.
**/
Perms::~Perms() {
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
 * Function to generate permutations.
 * This uses the internally defined list of chars to be assigned.
 *
 * Parameter:
 *   in_stream - the 'Scanner' from which to read the tokens
 *
 * Returns:
 *   a 'vector<string>' of the permutations
**/
vector<string> Perms::GenPerms(Scanner& in_stream) {
  vector<string> all_perms;
  vector<string> this_perm;

  ScanLine scanline;

  // read the tokens
  string inputline = in_stream.NextLine();
  scanline.OpenString(inputline);
  while(scanline.HasMoreData())
  {
    string s = scanline.Next();
    to_be_assigned_.push_back(s);
  }

  // find the permutations
  DoPerms(all_perms, this_perm, to_be_assigned_);

  return all_perms;
}

/****************************************************************
 * Function to do perms recursively.
 *
 * Parameters:
 *   all_perms - 'vector<string>' of all the permutations so far
 *   this_perm - 'vector<string>' of the current permutation
 *   not_yet_used - 'vector<string>' of the chars still to be used
**/
void Perms::DoPerms(vector<string>& all_perms, vector<string>& this_perm,
                    const vector<string>& not_yet_used) {
  // if we have hit bottom and used all tokens, we have a new
  // permutation, we add that to the vector, and return
  if(0 == not_yet_used.size()) {
    all_perms.push_back(ToStringVector(this_perm));
    return;
  }

  // generate the permutation:
  // for each element in the not yet used vector
  //     pull off that element 's'
  //     create a new 'vector' of the remaining tokens
  //     push 's' onto the permutation
  //     call recursively
  //     pop 's' off the permutation
  //
  // We are going to use subscripts here because the 'i != j'
  // part seems more readable here using subscripts than it would
  // with iterators testing equality of string data.
  for(UINT i = 0; i < not_yet_used.size(); ++i) {
    string s = not_yet_used.at(i);
    vector<string> remainder;
    for(UINT j = 0; j < not_yet_used.size(); ++j) {
      if(i != j) remainder.push_back(not_yet_used.at(j));
    }

    this_perm.push_back(s);
    DoPerms(all_perms, this_perm, remainder);
    this_perm.pop_back();

  }
}

/****************************************************************
 * Function to 'ToString' a vector
 * We don't have a 'toString' for the whole class because it
 * would be hard to do something meaningful for a recursively
 * defined object. The class is really just a package for the
 * recursive function. But in order to return the entire
 * package of permutations, we need to be able to build up
 * a string of the perms to be returned. 
 *
 * Parameters:
 * vec - the 'vector<string>' to be 'ToString'-ed
 * 
 * Returns:
 * the 'ToString' version of the input 'vector'
 * 
**/
string Perms::ToStringVector(const vector<string>& vec) {
  string s = " (";

  for(vector<string>::const_iterator iter = vec.begin();
                                     iter != vec.end(); ++iter) {
    s += Utils::Format((*iter), 6);
  }
  s += ")";

  return s;
} // string ToString()

