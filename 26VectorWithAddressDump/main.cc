#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for examples with vectors.
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
  VectorStuff v_stuff;

  ///////////////////////////////////////////////////////////////
  // check arguments and create the filenames
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

  ///////////////////////////////////////////////////////////////
  // open the input file
  in_file.OpenFile(in_filename);

  // read the data and dump it
  v_stuff.CreateVector(in_file);
  out_stream << kTag << "VECTOR\n" << v_stuff.ToString() << endl;
  out_stream.flush();

  ///////////////////////////////////////////////////////////////
  // clean up and go home
  Utils::log_stream << kTag << "Ending execution" << endl;
  time_call_output = Utils::TimeCall("ending");
  Utils::log_stream << time_call_output;
  Utils::log_stream.flush();

  Utils::FileClose(out_stream);
  Utils::FileClose(Utils::log_stream);

  return 0;
}
