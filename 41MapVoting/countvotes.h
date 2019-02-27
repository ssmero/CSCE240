/****************************************************************
 * Header for the vote counting code.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 9 July 2016
**/

#ifndef COUNTVOTES_H
#define COUNTVOTES_H

#include <iostream>
#include <map>
using namespace std;

#include "../../Utilities/utils.h"
#include "../../Utilities/scanner.h"
#include "../../Utilities/scanline.h"

class CountVotes {
public:
 CountVotes();
 virtual ~CountVotes();

// void CreateGraph(Scanner& inStream);
// void DescendFrom(ofstream& out_stream, string blanks, Node node);
// void DoSearch(ofstream& out_stream);
 void ReadAndCount(Scanner& in_stream);
 string ToString() const;

private:
 map<string, int> the_votes_;
};

#endif
