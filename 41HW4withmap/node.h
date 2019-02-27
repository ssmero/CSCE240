/****************************************************************
 * Header file for a node in a graph.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <vector>
using namespace std;

#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class Node {
public:
 Node();
 Node(int nodeNumber);
 virtual ~Node();

 void AddChildNumber(int which);
 vector<int> GetChildNumbers() const;
 int GetNodeNumber() const;
 bool HasBeenVisited() const;
 void SetVisited(bool what);

 string ToString() const;

private:
 bool visited_;

// const int kDummyNumber = -99;
 int node_number_;

 vector<int> child_numbers_;
};

#endif
