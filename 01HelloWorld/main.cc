/*********************************************************************
 * This is a basic "hello, world" program.
 *
 * Comments work in C++ almost exactly as they do in Java.
 * Either the "slash-star, star-slash" works, or else the
 * "slash slash" work for commenting code.
 *
 * This program can be compiled from the command line with
 * 'g++ main.cc'
 *
 * If you compile in this way, the output of the compile
 * will be a file called 'a.out'.  Instead of clicking on
 * the 'yadayada.exe' file as in Microsoft, enter 'a.out'
 * from the command line and the file will be executed if the
 * permissions are set to say that this is an executable file. 
 *
 * Instead of 'import' as in Java, it's '#include' in C++
 * Things in angle brackets refer to "system" includes. 
 * Things in (double) quotation marks refer to local files.
 * (We will get to the local files later.)
 *
 * YOU SHOULD ALWAYS INCLUDE THE 'namespace' LINE UNTIL VERY
 * LATE IN THIS COURSE.
 *
 * 'cout' is the default output stream, viz. 'stdout'.
 * Things to sent to this output stream are separated by '<<'.
 * The 'endl' means send the 'newline'/'carriage return'.
 * If you use multiple 'cout' calls with no 'endl' then the
 * output will all be concatenated as one line.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
 *
**/

// the next two lines provide for input from 'cin'
// and output to 'cout'
#include <iostream>
using namespace std;

// ignore the arguments for now; we will get to those later
int main(int argc, char *argv[]) {

// output will all be on one "line".
  cout << "Hello, world" << endl;

  // main programs in c++ always return an int
  // returning zero means all went well
  return 0;
}
