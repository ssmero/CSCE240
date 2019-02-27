#include "countvotes.h"

static const string kTag = "COUNTVOTES: ";

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Code to count votes.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 9 July 2016
**/

/******************************************************************************
 * Constructor
**/
CountVotes::CountVotes() {
}

/******************************************************************************
 * Destructor
**/
CountVotes::~CountVotes() {
}

/******************************************************************************
 * Accessors and Mutators
**/

/******************************************************************************
 * General functions.
**/

/******************************************************************************
 * Function 'ReadAndCount'.
 * Parameter:
 *     in_stream - the 'Scanner' from which to read
**/
void CountVotes::ReadAndCount(Scanner& in_stream)
{
  ScanLine scanline;

#ifdef EBUG
  cout << kTag << "enter ReadAndCount\n"; 
#endif

  while (in_stream.HasNext()) {
    string the_line = in_stream.NextLine();
    string the_ivo = the_line.substr(0, 7);
    std::size_t found = the_ivo.find_first_not_of("012345789");
    if (found != std::string::npos) continue;
    if (the_line.at(7) != ' ') continue;

    cout << the_line << endl;

    string candidate = the_line.substr(20, 40);
    string contest = the_line.substr(60);
    contest.at(contest.size()-1) = ' ';
    cout << "X" << candidate << "X" << endl;
    cout << "X" << contest << "X" << endl;

    the_votes_[candidate] += 1;
    cout << the_votes_[candidate] << endl << endl;
  }

#ifdef EBUG
  cout << kTag << "leave ReadAndCount " << endl;
#endif
} // void CountVotes::ReadAndCount(Scanner& in_stream)

/******************************************************************************
 * Function 'ToString'.
 * This is the usual 'ToString'.
 *
 * Returns:
 *   a formatted 'string' version of the 'map' of nodes
**/
string CountVotes::ToString() const
{
  string s = "";
#ifdef EBUG
  cout << kTag << "enter ToString\n"; 
#endif

  if (0 == the_votes_.size()) {
    s += "There are no votes\n";
  }
  else {
    map<string, int>::const_iterator iter;
    for(iter = the_votes_.begin(); iter != the_votes_.end(); ++iter) {
      s += "Count, Candidate: ";
      s += Utils::Format(iter->first, 30);
      s += Utils::Format(iter->second, 6);
      s += "\n";
    }
    s += "\n";
  }

#ifdef EBUG
  cout << kTag << "leave ToString\n"; 
#endif
  return s;
} // string CountVotes::ToString() const

