#ifndef SWAP_HPP
#define SWAP_HPP

/****************************************************************
 * Swap function for a pair of 'T' objects.  This function swaps
 * the first and the second parameters, which are passed in by
 * reference and thus are swapped in the calling program when
 * this function finishes.
**/
template<class T> void TemplateElementSwap(T& first, T& second) {
  T temp;
  temp = first;
  first = second;
  second = temp;
}

#endif /*SWAP_HPP*/

