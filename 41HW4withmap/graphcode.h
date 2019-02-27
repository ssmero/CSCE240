/****************************************************************
 * Homework 4 header file for the application class.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

#ifndef GRAPHCODE_H
#define GRAPHCODE_H

#include <iostream>
#include <vector>
#include <map>
using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

#include "node.h"
// #include "myrandom.h"

class GraphCode {
public:
 GraphCode();
 virtual ~GraphCode();

 void CreateGraph(Scanner& inStream);
 void DescendFrom(ofstream& out_stream, string blanks, Node node);
 void DoSearch(ofstream& out_stream);
 void ReadGraph(Scanner& in_stream);
 string ToString() const;

private:
 vector<int> path_;
 map<int, Node> the_graph_;

 string ToStringVector(string label, string blanks,
                       const vector<int>& children) const;
};

#endif
