/****************************************************************
 * Main program for testing set functions.
 *
 * Author/copyright:  Duncan Buell. All rights reserved.
 * Date: 24 July 2013
 *
**/

#include "Main.h"

static const string TAG = "Main: ";

/****************************************************************
 * Main program for testing sets.
**/
int main(int argc, char *argv[])
{
  string timeCallOutput = "";
  string outFileName = "";
  string logFileName = "";
  ofstream outStream;

  Scanner inScanner;
  Set<int> setInt;
  Set<string> setString;

  ///////////////////////////////////////////////////////////////
  // Boilerplate for opening files
  Utils::CheckArgs(2, argc, argv, "outfilename logfilename");
  outFileName = (string) argv[1];
  logFileName = (string) argv[2];

  Utils::FileOpen(outStream, outFileName);
  Utils::LogFileOpen(logFileName);

  timeCallOutput = Utils::timecall("beginning");
  Utils::logStream << timeCallOutput;
  Utils::logStream << TAG << "Beginning execution" << endl;
  Utils::logStream.flush();

  Utils::logStream << TAG << "outfile '" << outFileName << "'" << endl;
  Utils::logStream << TAG << "logfile '" << logFileName << "'" << endl;
  Utils::logStream.flush();

  ///////////////////////////////////////////////////////////////
  // The actual work part of the main program

  setInt.addToSet(4);
  setInt.addToSet(7);
  setInt.addToSet(10);

  setString.addToSet("this");
  setString.addToSet("that");
  setString.addToSet("theother");
  setString.addToSet("that");

  outStream << TAG << "output INTEGER X" << setInt.toString() << "X" << endl;
  outStream.flush();

  outStream << TAG << "output STRING X" << setString.toString() << "X" << endl;
  outStream.flush();

  Set<double> setDouble;
  outStream << TAG << "output DOUBLE X" << setDouble.toString() << "X" << endl;
  outStream << TAG << "output DOUBLE card X" << setDouble.card() << "X" << endl;
  outStream.flush();

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
