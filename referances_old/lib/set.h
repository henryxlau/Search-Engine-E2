#ifndef SET_H
#define SET_H
#include <set>
#include <iostream>
using namespace std;

template <class T>
class Set : public std::set<T> {
  public: 
    Set ();

    Set<T> setIntersection (const Set<T> & other) const;
      /* Returns the intersection of the current set with other.
         That is, returns the set of all items that are both in this
         and in other. */

    Set<T> setUnion (const Set<T> & other) const;
      /* Returns the union of the current set with other.
         That is, returns the set of all items that are in this set
         or in other (or both).
         The resulting set should not contain duplicates. */

      /* The next two functions together implement a suboptimal version
         of what is called an "iterator".
         Together, they should give you a way to loop through all elements
         of the set. The function "first" starts the loop, and the function
         "next" moves on to the next element.
         You will want to keep the state of the loop inside a private variable.
         We will learn the correct way to implement iterators soon, at 
         which point you will replace this.
         For now, we want to keep it simple. */

    // T* first ();
    //   /* Returns the pointer to some element of the set, 
    //      which you may consider the "first" element.
    //      Should return NULL if the set is empty. */

    // T* next ();
    //   /* Returns the pointer to an element of the set different from all 
    //      the ones that "first" and "next" have returned so far. 
    //      Should return NULL if there are no more element. */

    bool contains(T element) const;
      /* Returns bool value of true or false based on whether element is in the set. */

  private:
    int iter;
    // other private variables you think you need.
};

#include "set.hpp"

#endif