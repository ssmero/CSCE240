/****************************************************************
 * Header file for the grocery receipt program with a separate
 * class for doing the computation.
 *
 * Author/copyright:  Duncan Buell
 * Used with permission and modified by: Jane Random Hacker
 * Date: 8 May 2016
**/

#ifndef DOTHEWORK_H
#define DOTHEWORK_H

#include <iostream>
using namespace std;

class DoTheWork {
public:
 DoTheWork();
 virtual ~DoTheWork();

 void ProcessInput();

private:

 int number_of_transactions_; // number of lines of input

 double running_total_cost_; // running total sum of purchases

};

#endif
