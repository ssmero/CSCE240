#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for testing recursion.
 *
 * This is still a bit of a kluge. We insist on an input file
 * but we don't actually use it for this example.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 12 May 2016
**/

/****************************************************************
 * Main program for testing recursion.
**/
int main(int argc, char *argv[]) {
  string time_call_output = "";
  string in_filename = "";
  string out_filename = "";
  string log_filename = "";
  Scanner in_stream;
  ofstream out_stream;

  Factorial factorial;

  ///////////////////////////////////////////////////////////////
  // check arguments and create the filenames
  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  in_filename = static_cast<string>(argv[1]);
  out_filename = static_cast<string>(argv[2]);
  log_filename = static_cast<string>(argv[3]);

  ///////////////////////////////////////////////////////////////
  // open output file and log file
  Utils::FileOpen(out_stream, out_filename);
  Utils::LogFileOpen(log_filename);

  ///////////////////////////////////////////////////////////////
  // announce our presence and start the timer
  time_call_output = Utils::TimeCall("beginning");
  Utils::log_stream << time_call_output;
  Utils::log_stream << kTag << "Beginning execution" << endl;
  Utils::log_stream.flush();

  Utils::log_stream << kTag << "infile  '" << in_filename << "'" << endl;
  Utils::log_stream << kTag << "outfile '" << out_filename << "'" << endl;
  Utils::log_stream << kTag << "logfile '" << log_filename << "'" << endl;
  Utils::log_stream.flush();

  ///////////////////////////////////////////////////////////////
  // open input file
  in_stream.OpenFile(in_filename);

  ///////////////////////////////////////////////////////////////
  // do the actual computation
  while(in_stream.HasNext())
  {
    LONG n = in_stream.NextLONG();
    int level = 0;
    cout << "n is " << Utils::Format(n, 10) << " and Factorial(n) is "
         << Utils::Format(factorial.DoFactorial(level, n), 15) << endl;
    Utils::log_stream << endl << endl;
  }

  ///////////////////////////////////////////////////////////////
  // clean up and go home
  Utils::log_stream << kTag << "Ending execution" << endl;
  time_call_output = Utils::TimeCall("ending");
  Utils::log_stream << time_call_output;
  Utils::log_stream.flush();
  Utils::FileClose(Utils::log_stream);

  Utils::FileClose(out_stream);

  return 0;
}
