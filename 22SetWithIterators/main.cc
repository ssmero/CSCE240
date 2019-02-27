#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for demonstrating iterating over a set.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 11 May 2016
**/

int main(int argc, char *argv[]) {
  string time_call_output = "";
  string in_filename = "";
  string out_filename = "";
  string log_filename = "";
  ofstream out_stream;

  Scanner in_file;
  MySet the_set;

  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  in_filename = static_cast<string>(argv[1]);
  out_filename = static_cast<string>(argv[2]);
  log_filename = static_cast<string>(argv[3]);

  Utils::FileOpen(out_stream, out_filename);
  Utils::LogFileOpen(log_filename);

  time_call_output = Utils::TimeCall("beginning");
  Utils::log_stream << time_call_output;
  Utils::log_stream << kTag << "Beginning execution" << endl;
  Utils::log_stream.flush();

  Utils::log_stream << kTag << "infile  '" << in_filename << "'" << endl;
  Utils::log_stream << kTag << "outfile '" << out_filename << "'" << endl;
  Utils::log_stream << kTag << "logfile '" << log_filename << "'" << endl;

  in_file.OpenFile(in_filename);

  // create the set and then just print it out
  the_set.CreateSet(in_file);
  out_stream << kTag << "THE SET\n" << the_set.ToString() << endl;
  out_stream.flush();

  Utils::log_stream << kTag << "Ending execution" << endl;
  time_call_output = Utils::TimeCall("ending");
  Utils::log_stream << time_call_output;
  Utils::log_stream.flush();

  Utils::FileClose(out_stream);
  Utils::FileClose(Utils::log_stream);

  return 0;
}
