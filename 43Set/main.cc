#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for testing set functions.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

/****************************************************************
 * Main program for testing sets.
**/
int main(int argc, char *argv[]) {
  string time_call_output = "";
  string in_filename = "";
  string out_filename = "";
  string log_filename = "";
//  ifstream in_stream;
  ofstream out_stream;

  Scanner in_scanner;
  SetTester set_tester;

  ///////////////////////////////////////////////////////////////
  // Boilerplate for opening files
  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  in_filename = (string) argv[1];
  out_filename = (string) argv[2];
  log_filename = (string) argv[3];

  Utils::FileOpen(out_stream, out_filename);
  Utils::LogFileOpen(log_filename);

  time_call_output = Utils::TimeCall("beginning");
  Utils::log_stream << time_call_output;
  Utils::log_stream << kTag << "Beginning execution" << endl;
  Utils::log_stream.flush();

  Utils::log_stream << kTag << "infile  '" << in_filename << "'" << endl;
  Utils::log_stream << kTag << "outfile '" << out_filename << "'" << endl;
  Utils::log_stream << kTag << "logfile '" << log_filename << "'" << endl;
  Utils::log_stream.flush();

  ///////////////////////////////////////////////////////////////
  // The actual work part of the main program
  in_scanner.OpenFile(in_filename);

  set_tester.TestConstructors(in_scanner, out_stream);
  set_tester.TestFunctions(in_scanner, out_stream);

  ///////////////////////////////////////////////////////////////
  // Boilerplate for closing up
  Utils::log_stream << kTag << "Ending execution" << endl;
  time_call_output = Utils::TimeCall("ending");
  Utils::log_stream << time_call_output;
  Utils::log_stream.flush();

  Utils::FileClose(out_stream);
  Utils::FileClose(Utils::log_stream);

  return 0;
}
