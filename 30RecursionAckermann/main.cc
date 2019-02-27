#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for testing Ackermann.
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

  vector<string> the_perms;

  Ackermann ackermann;

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
  while(in_stream.HasNext()) {
    LONG m = in_stream.NextLONG();
    LONG n = in_stream.NextLONG();
    int level = 0;
    LONG ack_value = ackermann.DoAckermann(level, m, n);

    cout << endl << "m,n are " << Utils::Format(m, 5)
                 << Utils::Format(n, 5) << " and A(m, n) is "
                 << Utils::Format(ack_value, 15) << endl;
    Utils::log_stream << endl << endl;
  }



  ///////////////////////////////////////////////////////////////
  // now dump the results
  for(vector<string>::iterator iter = the_perms.begin();
                               iter != the_perms.end(); ++iter) {
    out_stream << (*iter) << endl;
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
