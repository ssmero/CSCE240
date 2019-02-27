#include "main.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Main program for vote counting.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 9 July 2016
**/

int main(int argc, char *argv[]) {
  string in_filename = "";
  string out_filename = "";
  string log_filename = "";
  ofstream out_stream;

  Scanner in_stream;

  CountVotes count_votes;

  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  in_filename = static_cast<string>(argv[1]); // DO NOT USE OLD CAST!
  out_filename = static_cast<string>(argv[2]);
  log_filename = static_cast<string>(argv[3]);

  Utils::LogFileOpen(log_filename);

  Utils::log_stream << "Beginning execution\n";
  Utils::log_stream.flush();

  Utils::FileOpen(out_stream, out_filename);

  Utils::log_stream << "infile  '" << in_filename << "'\n";
  Utils::log_stream << "outfile '" << out_filename << "'\n";
  Utils::log_stream << "logfile '" << log_filename << "'\n";

  in_stream.OpenFile(in_filename);
  count_votes.ReadAndCount(in_stream);
  in_stream.Close();

  out_stream << "VOTE COUNTS\n" << count_votes.ToString() << endl;
  out_stream.flush();

  Utils::FileClose(out_stream);

  Utils::log_stream << "Ending execution\n";
  Utils::log_stream.flush();

  Utils::FileClose(Utils::log_stream);

  return 0;
}
