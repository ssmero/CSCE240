#include "main.h"

static const string kTag = "MAIN: ";

/****************************************************************
 * Main program for sorting a 'vector'.
 *
 * This particular file is the big version of boilerplate for
 * opening and closing files and calling up a function to do work. 
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 13 June 2015
 *
**/

int main(int argc, char *argv[]) {
  string in_filename = "dummy_infile";
  string out_filename = "dummy_outfile";
  string log_filename = "dummy_logfile";
  ofstream out_stream;

  Scanner in_scanner;
  ReadAndSort sorter;

  // these next lines allow you to specify file names for input and
  // output on the command line.
  // the 'usage' is the standard way that unix commands inform the
  // user that the command needs arguments. 
  // try issuing the 'mkdir' command, for example, without arguments.
  // DO NOT WORRY ABOUT UNDERSTANDING THE DETAILS OF THIS RIGHT NOW
  //
  // The first argument to the function is the number of user-supplied
  // command line arguments are expected. In this case, the three
  // file names.
  //
  // The second and third arguments are the parameters to the 'main'. 
  //
  // The fourth argument is the string 's' to be printed on error.
  // The function on error will print the concatenation
  //      "usage: " + argv[0] + s
  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  in_filename = static_cast<string>(argv[1]); // DO NOT USE OLD CAST!
  out_filename = static_cast<string>(argv[2]);
  log_filename = static_cast<string>(argv[3]);

  Utils::LogFileOpen(log_filename);
  Utils::FileOpen(out_stream, out_filename);

  Utils::log_stream << kTag << "Beginning execution\n";
  Utils::log_stream.flush();

  Utils::log_stream << kTag << "infile  '" << in_filename << "'\n";
  Utils::log_stream << kTag << "outfile '" << out_filename << "'\n";
  Utils::log_stream << kTag << "logfile '" << log_filename << "'\n";

  // NOTICE THAT ALL THE STUFF ABOVE THIS POINT IS JUST BOILERPLATE
  // THE REAL WORK STARTS HERE
  in_scanner.OpenFile(in_filename);
  sorter.ReadData(in_scanner);
  in_scanner.Close();

  out_stream << kTag << "BEFORE SORT\n" << sorter.ToString() << endl;
  out_stream.flush();

  sorter.SortData();
  out_stream << kTag << "AFTER SORT\n" << sorter.ToString() << endl;
  out_stream.flush();
  // THE REAL WORK ENDS HERE

  Utils::log_stream << kTag << "Ending execution\n";
  Utils::log_stream.flush();

  Utils::FileClose(out_stream);
  Utils::FileClose(Utils::log_stream);

  return 0;
}
