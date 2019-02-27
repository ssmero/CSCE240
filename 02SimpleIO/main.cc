/****************************************************************
 * Second version 'hello world' program, with input and output.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
 *
**/

#include <iostream>
using namespace std;

int main(int argc, char *argv[]) {
  string name_string = "dummystring";

  cout << "What is your name? ";
  cin >> name_string;
  cout << "Hello, " << name_string << "!" << endl;

  return 0;
}
