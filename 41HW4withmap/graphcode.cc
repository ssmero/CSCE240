#include "graphcode.h"

static const string kTag = "GRAPHCODE: ";

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Homework 4 'GraphCode' application class.
 *
 * This has
 *     a function to read in a graph,
 *     an outer recursive function for depth first traversal 
 *     an inner recursive function for depth first traversal 
 *
 * The outer function sets up the recursion. The inner function does the
 * traversal of unvisited nodes until it hits a node with no children. At that
 * point it prints out that it has found a "leaf". 
 *
 * There is a bit of a kluge in this in that we keep the nodes of the graph
 * in a 'vector' with the node sequence number equal to the subscript in the
 * 'vector'. To remove the requirement of synchronizing subscript and node
 * number one should use a 'map' of 'Node' instances.
 *
 * There is also a legacy function to create a graph using random numbers to
 * decide whether to connect any pair of arcs. We are not using this function.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

/******************************************************************************
 * Constructor
**/
GraphCode::GraphCode() {
}

/******************************************************************************
 * Destructor
**/
GraphCode::~GraphCode() {
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'DescendFrom'.
 *
 * This is the recursive function that is the heart of the traversal.
 *
 * We descend from a parent node passed in as a parameter.
 * if there are no children,
 *     we are at a leaf, so we print the path to this leaf and return
 * else
 *     for each child node
 *         if we have already visited this node, punt and continue
 *         else 
 *             mark it as visited (and save the marked node!) 
 *             push the node onto the 'path' variable
 *             descend recursively from the node
 *             pop the initial path from the 'path' variable
 *
 * Parameters:
 *   out_stream - the output stream to which to write the LEAF results
 *   blanks - the leading blank spaces so as to indent the tracing information
 *   parent_node - the node from which to descend
 *   path - the vector of the path so far
**/
void GraphCode::DescendFrom(ofstream& out_stream, string blanks,
                            Node parent_node)
{
#ifdef EBUG
#endif
  cout << blanks << kTag
       << this->ToStringVector("enter DescendFrom\n", blanks,
                               path_) << endl;

//  path_ += Utils::Format(parentNode.getNodeNumber(), 4);

  vector<int> the_child_numbers = parent_node.GetChildNumbers();
  cout << this->ToStringVector("children ", blanks, the_child_numbers);

  if (0 == the_child_numbers.size())
  {
//    path_.push_back("LEAF");
    cout << this->ToStringVector("PATH TO LEAF ", blanks, path_) << endl;
    out_stream << this->ToStringVector("PATH TO LEAF ", blanks, path_) << endl;
//    path_.pop_back();
    return;
  }
  else {
    for (UINT child_number = 0;
              child_number < the_child_numbers.size(); ++child_number) {
      Node child_node = the_graph_.at(the_child_numbers.at(child_number));
      if (child_node.HasBeenVisited())
      {
        cout << "\n" << blanks << "NODE already visited "
             << child_node.ToString() << endl; 
        continue;
//        path_ += "\n" + blanks + "From " + child_node.ToString() + " CYCLE";
//        cout << blanks << "Output " << path_ << endl;
//        cout << blanks << kTag << "leave DescendFrom\n"; 
      }
      else
      {
        cout << "\n" << blanks << "NODE not yet visited "
             << child_node.ToString() << endl; 
        child_node.SetVisited(true);
        the_graph_[child_node.GetNodeNumber()] = child_node;

        path_.push_back(child_node.GetNodeNumber());
        this->DescendFrom(out_stream, "  " + blanks, child_node);
        path_.pop_back();

      } // if (childNode.hasBeenVisited())
    } // for (UINT child_number = 0;
  } // if (0 == the_child_numbers.size())

#ifdef EBUG
#endif
  cout << blanks << kTag << "leave DescendFrom\n"; 

} // GraphCode::DescendFrom()

/******************************************************************************
 * Function 'DoSearch'.
 *
 * To simplify matters, we output to 'out_stream' rather than try to return a
 * value from the recursive function if in fact we find leaves in the graph.
 *
 * Parameter:
 *   out_stream -- the output stream to which to write the eventual result
**/
void GraphCode::DoSearch(ofstream& out_stream)
{
#ifdef EBUG
  cout << kTag << "enter DoSearch\n"; 
#endif

  // loop through all the nodes
  // if the node has been visited then skip it and go on
  // else
  //   mark it as visited (and save the marked node!) 
  //
  //   push the initial path onto the 'path' variable
  //   descend recursively from the node
  //   pop the initial path from the 'path' variable
  //
  map<int, Node>::iterator iter;
  for (iter = the_graph_.begin(); iter != the_graph_.end(); ++iter) {
    Node this_node = (iter->second);
    if (this_node.HasBeenVisited()) {
      cout << "\nNODE " << (iter->second).GetNodeNumber() << " already visited "
           << this_node.ToString() << endl; 
    }
    else {
      cout << "\nNODE " << (iter->second).GetNodeNumber() << " not yet visited "
           << this_node.ToString() << endl; 
      this_node.SetVisited(true);
      this->the_graph_[this_node.GetNodeNumber()] = this_node;
      cout << "DESCEND" << endl;

      path_.push_back(this_node.GetNodeNumber());
      this->DescendFrom(out_stream, "  ", this_node);
      path_.pop_back();

    } // if (thisNode.HasBeenVisited())
  } // for (UINT sub = 0; sub < the_graph_.size(); ++sub)

#ifdef EBUG
  cout << kTag << "leave DoSearch\n"; 
#endif

} // void GraphCode::DoSearch()

/******************************************************************************
 * Function 'readGraph'.
 * We read data from the input stream and create a graph.
 *
 * The only thing tricky about this is to make sure we have all the nodes
 * accounted for in the 'vector' since we use the subscript also as the node
 * number. That's the reason for reading in the beginning and ending node
 * numbers and creating an initial dummy 'vector'.
 *
 * Parameter:
 *     in_stream - the 'Scanner' from which to read
**/
void GraphCode::ReadGraph(Scanner& in_stream)
{
  ScanLine scanline;

#ifdef EBUG
  cout << kTag << "enter ReadGraph\n"; 
#endif

  int first_node, last_node;
  first_node = in_stream.NextInt();
  last_node = in_stream.NextInt();
  assert (0 == first_node);
  // note that we read inclusive through the 'lastNode' value
  for(int i = 0; i <= last_node; ++i) {
    Node node = Node(i);
    the_graph_[i] = node;
  }

  // read line by line, one line for each node
  // use each line to create a 'ScanLine'
  // then parse each 'scanLine' instance to get the child node numbers
  // and add each child node number to the children for the node in question
  while (in_stream.HasNext()) {
    string the_line = in_stream.NextLine();

    scanline.OpenString(the_line);
    int parent_node_num = scanline.NextInt();
    Node node = the_graph_.at(parent_node_num);
    while( scanline.HasNext())
    {
      int the_child = scanline.NextInt();

      node.AddChildNumber(the_child);
    }
    the_graph_.at(parent_node_num) = node;
  }

#ifdef EBUG
  cout << kTag << "leave ReadGraph " << endl;
#endif
} // void GraphCode::ReadGraph(Scanner& in_stream)

/******************************************************************************
 * Function 'ToString'.
 * This is the usual 'ToString'.
 *
 * Returns:
 *   a formatted 'string' version of the 'map' of nodes
**/
string GraphCode::ToString() const
{
  string s = "";
#ifdef EBUG
  cout << kTag << "enter ToString\n"; 
#endif

  if (0 == the_graph_.size()) {
    s += "There are no nodes\n";
  }
  else {
    map<int, Node>::const_iterator iter;
    for(iter = the_graph_.begin(); iter != the_graph_.end(); ++iter) {
      s += "Node " + (iter->second).ToString();
      s += "\n";
    }
    s += "\n";
  }

#ifdef EBUG
  cout << kTag << "leave ToString\n"; 
#endif
  return s;
} // string GraphCode::ToString() const

/******************************************************************************
 * Function 'ToStringVector'.
 * This is a 'ToString' for a 'vector' of node numbers.
 *
 * Returns:
 *   a formatted 'string' version of the 'vector' of the numbers
**/
string GraphCode::ToStringVector(string label, string blanks,
                                 const vector<int>& numbers) const {
  string s = blanks + label + "\n";
#ifdef EBUG
  cout << kTag << "enter ToStringVector\n"; 
#endif

  if (0 == numbers.size())
  {
    s += blanks;
    s += "There are no entries\n";
  }
  else
  {
    vector<int>::const_iterator iter;
    for(iter = numbers.begin(); iter != numbers.end(); ++iter)
    {
      s += blanks;
      s += Utils::Format(*iter, 4);
    }
    s += "\n";
  }

#ifdef EBUG
  cout << kTag << "leave ToStringVector\n"; 
#endif
  return s;
} // string GraphCode::ToStringVector() const

