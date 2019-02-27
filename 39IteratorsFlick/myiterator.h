/****************************************************************
 * Example iterator program from cplusplus.com, modified to use
 * a private array in a separate class.
 *
 * Author/copyright:  Duncan Buell, Brian Flick.
 *                    All rights reserved.
 * Used with permission and modified by: Jane Random Hacker
 * Date: 13 May 2016
**/

#include "../../Utilities/utils.h"

#include "record.h"

/****************************************************************
 *
**/
class MyIterator : public std::iterator<std::input_iterator_tag, int> {
  private:
    Record* rec_ptr;

  public:
    MyIterator() : rec_ptr(NULL) {}

    MyIterator(Record* x) : rec_ptr(x) {}

    MyIterator(const MyIterator& my_iter) : rec_ptr(my_iter.rec_ptr) {}

    MyIterator operator++() {++rec_ptr; return *this;}

    MyIterator operator++(int ignore_me) {MyIterator tmp(*this);
                                         operator++(); return tmp;}

    bool operator==(const MyIterator& rhs) {return rec_ptr == rhs.rec_ptr;}

    bool operator!=(const MyIterator& rhs) {return rec_ptr != rhs.rec_ptr;}

    Record operator*() {return *rec_ptr;}
};
