#ifndef PAIR_H_
#define PAIR_H_

#include <cstdlib>
// #include <iostream>
#include <sstream>
#include <string>

#include "../../Utilities/utils.h"

#include "record.h"

using namespace std;

template<class T> class MyPair {
public:
 T first_;
 T second_;

 MyPair();
 MyPair(T in_first, T in_second);

 T GetFirst();
 T GetSecond();
 void SetFirst(T what);
 void SetSecond(T what);

 bool Equals(const MyPair& rhs);

 void Swap();
 string ToString();

private:
 bool TestEquals(int left, int right);
 bool TestEquals(string left, string right);
 bool TestEquals(Record left, Record right);

};

#endif /*PAIR_H_*/
