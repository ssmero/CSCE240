#include "node.h"

static const string kTag = "NODE: ";
static const int kDummyNumber = -99;

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Class 'Node' for a single node in a graph.
 *
 * This class is essentially just a wrapper for:
 *   a node sequence number
 *   a 'bool' variable called 'visited' to indicate whether the node has been
 *       visited or not
 *   a 'vector' of 'int' values that are the node numbers of the nodes to
 *       which this node has an outgoing arc (we will call these "children"
 *       as if this was a node in a tree)
 *
 * Author: Duncan A. Buell
 * Date last modified: 13 July 2015
**/

/******************************************************************************
 * Constructor
**/
Node::Node() {
  node_number_ = kDummyNumber;
  visited_ = false;
}

/******************************************************************************
 * Constructor -- we use this for the leaf nodes
**/
Node::Node(int number) {
  node_number_ = number;
  visited_ = false;
}

/******************************************************************************
 * Destructor
**/
Node::~Node() {
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * Accessor 'GetChildNumbers'.
 *
 * Returns:
 *   the 'vector<int>' of the 'childNumbers'
**/
vector<int> Node::GetChildNumbers() const {
  return child_numbers_;
}

/******************************************************************************
 * Accessor 'GetNodeNumber'.
 *
 * Returns:
 *   the node number of this node
**/
int Node::GetNodeNumber() const {
  return node_number_;
}

/******************************************************************************
 * Accessor 'HasBeenVisited'.
 * We changed the function name so it can be called as if in the text of
 * a question.
 *
 * Returns:
 *   the 'visited' value of this node
**/
bool Node::HasBeenVisited() const {
  return visited_;
}

/******************************************************************************
 * Mutator 'SetVisited'.
 *
 * Parameter:
 *   what - the value to which to set 'visited'
**/
void Node::SetVisited(bool what) {
  visited_ = what;
}

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'AddChildNumber'.
 * This adds a child node number to the 'vector' of child subs.
**/
void Node::AddChildNumber(int which) {
  child_numbers_.push_back(which);
}

/******************************************************************************
 * Function 'ToString'.
 * This returns the data, formatted, from the class.
**/
string Node::ToString() const {
  string s = "(";

  s += Utils::Format(node_number_, 4) + ": ";
  if (visited_) {
    s += " T ";
  }
  else {
    s += " F ";
  }
  for (UINT i = 0; i < child_numbers_.size(); ++i) {
    s += Utils::Format(child_numbers_.at(i), 4);
  }
  s += " XXX)";

  return s;
}
