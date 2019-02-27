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

    if (the_line.size() < 5) continue; // might as well -- this will trim some lines

    string ivo_number = the_line.substr(0, 7);
    std::size_t found = ivo_number.find_first_not_of("0123456789");
    if (found != std::string::npos) continue;

    string test_candidate = the_line.substr(20,40);
    cout << "CAND X" << test_candidate << "X" << endl;
    string test_contest = the_line.substr(60);
    test_contest.at(test_contest.size()-1) = ' ';
    cout << "CONT X" << test_contest << "X" << endl;

/*
    string test_run_date = the_line.substr(0,8);
//    cout << "ZORK X" << test_run_date << "X" << endl;
    if ("RUN DATE" == test_run_date) continue;

    string test_votr_text = the_line.substr(0,5);
    if ("VOTR." == test_votr_text) continue;

    if ('\xd' == the_line.at(0)) continue;

    if (the_line.size() < 60) continue;

    cout << the_line << endl;
    string test_candidate = the_line.substr(20,40);
    cout << "CAND X" << test_candidate << "X" << endl;
    string test_contest = the_line.substr(60);
    test_contest.at(test_contest.size()-1) = ' ';
    cout << "CONT X" << test_contest << "X" << endl;
*/
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

