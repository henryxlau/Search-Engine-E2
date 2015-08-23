#ifndef SET_H
#define SET_H
#include <set>
#include <iostream>
#include <string>

template <class T>
class Set : public std::set<T>
{
public: 
	Set<T> setIntersection (const Set<T> & other) const;
	Set<T> setUnion (const Set<T> & other) const;
	void printSet();
};

template <class T>
Set<T> Set<T>::setIntersection (const Set<T> & other) const
{
	Set<T> tempList;
	Set<T> target = other;
	
	for (typename Set<T>::iterator temp = target.begin(); temp != target.end(); ++temp)
	{
		if (!(this->find(*temp) == this->end()))
		{
			tempList.insert(*temp);
		}
	}
	return tempList;
}
      /* Returns the intersection of the current set with other.
         That is, returns the set of all items that are both in this
         and in other. */

template <class T>
Set<T> Set<T>::setUnion (const Set<T> & other) const
{
	Set<T> tempList = *this;
	Set<T> target = other;
	
	for (typename Set<T>::iterator temp = target.begin(); temp != target.end(); ++temp)
	{
		if (this->find(*temp) == this->end())
		{
			tempList.insert(*temp);
		}
	}
	return tempList;
}

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

template <class T>
void Set<T>::printSet()
{
	int i = 0;
	for (typename Set<T>::iterator it = this->begin(); it != this->end(); ++it)
	{
		i++;
		std::cout << (*it) << std::endl;
	}
	std::cout << std::endl;
}

#endif //SET_H
