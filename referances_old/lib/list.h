#ifndef LIST_H
#define LIST_H

// necessary includes can go here

template <class T>
struct Item
{
  T value;
  Item<T> *prev, *next;
};

template <class T>
class List
{
  public:
    List ();   // constructor

    ~List ();  // destructor

    int size () const;  // returns the number of elements in the list

    void insert (int position, const T & val);
      /* Inserts val into the list before the given position,
         shifting all later items one position to the right.
         Inserting before 0 makes it the new first element.
         Inserting before size() makes it the new last element.
         Your function should throw an exception if position is
         outside the legal range. */

    void remove (int position);
      /* Removes the item from the given position, shifting all
         later items one position to the left.
         Your function should throw an exception if position is
         outside the legal range. */

    void set (int position, const T & val);
      /* Overwrites the given positiolsn with the given value.
         Does not affect any other positions.  
         Your function should throw an exception if position is
         outside the legal range. */

    T& get (int position) const;
      /* Returns the item at the given position.
         Your function should throw an exception if position is
         outside the legal range. */

    List (const List<T> & other);
       // A copy constructor which performs a deep copy.

    List<T> & operator= (const List<T> & other);
      // An assignment operators.

    private:
      Item<T> *head;

      /* You may add further private data fields or helper methods if 
         you choose. You should not alter the public signature. */
};

#include "list.hpp"

#endif