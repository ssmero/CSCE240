#include "main.h"

/******************************************************************************
 *3456789 123456789 123456789 123456789 123456789 123456789 123456789 123456789
 * Homework 4 main program.
 *
 * This program reads a number of nodes and a fraction of connectivity and
 * creates and analyses the graph with that number of nodes and that
 * connectivity.
 *
 * Author: Duncan A. Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

int main(int argc, char *argv[]) {
  string in_filename = "";
  string out_filename = "";
  string log_filename = "";
  ofstream out_stream;

  Scanner in_stream;

  GraphCode graph_code;

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
//  graphCode.createGraph(inStream);
  graph_code.ReadGraph(in_stream);
  in_stream.Close();

  out_stream << "RAW GRAPH\n" << graph_code.ToString() << endl;
  out_stream.flush();

  out_stream << "SEARCH\n";
  graph_code.DoSearch(out_stream);
  out_stream.flush();

  Utils::FileClose(out_stream);

  Utils::log_stream << "Ending execution\n";
  Utils::log_stream.flush();

  Utils::FileClose(Utils::log_stream);

  return 0;
}
