/****************************************************************
 * Main program for testing set functions.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 24 July 2013
 *
**/

#include "Main.h"

static const char TAG[] = "Main: ";

/****************************************************************
 * Main program for testing sets.
**/
int main(int argc, char *argv[])
{
  string timeCallOutput = "";
  string inFileName = "";
  string outFileName = "";
  string logFileName = "";
  ifstream inStream;
  ofstream outStream;

  Scanner inScanner;
  SetTester setTester;

  ///////////////////////////////////////////////////////////////
  // Boilerplate for opening files
  Utils::CheckArgs(3, argc, argv, "infilename outfilename logfilename");
  inFileName = (string) argv[1];
  outFileName = (string) argv[2];
  logFileName = (string) argv[3];

  Utils::FileOpen(outStream, outFileName);
  Utils::LogFileOpen(logFileName);

  timeCallOutput = Utils::timecall("beginning");
  Utils::logStream << timeCallOutput;
  Utils::logStream << TAG << "Beginning execution" << endl;
  Utils::logStream.flush();

  Utils::logStream << TAG << "infile  '" << inFileName << "'" << endl;
  Utils::logStream << TAG << "outfile '" << outFileName << "'" << endl;
  Utils::logStream << TAG << "logfile '" << logFileName << "'" << endl;
  Utils::logStream.flush();

  ///////////////////////////////////////////////////////////////
  // The actual work part of the main program
  inScanner.openFile(inFileName);

  setTester.testConstructors(inScanner, outStream);
  setTester.testFunctions(inScanner, outStream);

  ///////////////////////////////////////////////////////////////
  // Boilerplate for closing up
  Utils::logStream << TAG << "Ending execution" << endl;
  timeCallOutput = Utils::timecall("ending");
  Utils::logStream << timeCallOutput;
  Utils::logStream.flush();

  Utils::FileClose(outStream);
  Utils::FileClose(Utils::logStream);

  return 0;
}
