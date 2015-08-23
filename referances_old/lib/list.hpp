#include <cstddef>
#include <iostream>
#include <stdexcept>

template <class T>
List<T>::List() {
	head = NULL;	//This will let insert() know when the list is empty
}

template <class T>
List<T>::~List () {
	if(head == NULL) {
					//Don't delete if head was empty to begin with
	}
	else {
		//This block iterates through the list, deleting each Item<T> and moving the head to its next field
		//This keeps going until head is null (empty list)
		Item<T>* nextToDelete;

		do {
			nextToDelete = head->next;
			delete head;
			head = nextToDelete;
		}
		while (head != NULL);
	}
}

template <class T>
int List<T>::size () const {
	//Keeps running through the for loop until it runs out of next fields to move to.
	//Increments retval each.
	int retval = 0;
	for(Item<T>* ptr = head; ptr != NULL; ptr = ptr->next) {
//		std::cerr << "ptr-next: "<< ptr->next << std::endl;
		retval++;
	}
	return retval;
}

template <class T>
void List<T>::insert (int position, const T & val) {
	//Throw an exception if bad value is given for position
	if(position > size()) {
		throw std::runtime_error(std::string("Indicated position is beyond size of list"));
	}

	//If head is NULL, create the first item of the list
	if(head == NULL) {
		head = new Item<T>;
		head->prev = NULL;
		head->next = NULL;
		head->value = val;
	} else {
		//Otherwise, move ptr until we reach the end of the list
		Item<T>* ptr = head;
		Item<T>* ptrPrev = NULL;
		for(int i = 0; i < position; i++) {
			ptrPrev = ptr;
			ptr = ptr->next;
		}
		//Generate new Item (allocate memory)
		//Set its next and prev, as well as the next and prev of the adjacent nodes
		//that addition is being inserted between.
		Item<T>* addition = new Item<T>;
		addition->value = val;
		addition->next = ptr;
		if(ptrPrev != NULL) { //Make sure we aren't accessing a null pointer
			ptrPrev->next = addition;
		}
		if(ptr != NULL) { //Make sure we aren't accessing a null pointer
			addition->prev = ptr->prev;
			ptr->prev = addition;
		}
		while(head->prev != NULL) {
			head = head->prev;
		}
	}
}




template <class T>
void List<T>::remove (int position) {
	//Throw an exception if bad value given for exception
	if(position >= size()) {
		throw std::runtime_error(std::string("Indicated position is beyond size of list"));
	}
	//Move ptr until we've reached the target position
	Item<T>* ptr = head;
	for(int i = 0; i < position; i++) {
		ptr = ptr->next;
	}

	//Update the next and prev values of adjacent nodes
	if(ptr->prev != NULL) { //Make sure we aren't accessing a null pointer
		ptr->prev->next = ptr->next;
	}
	if(ptr->next != NULL) { //Make sure we aren't accessing a null pointer
		ptr->next->prev = ptr->prev;
	}

	//Special steps taken for when the targeted node is the head of the list.
	if(ptr == head) {
		head = ptr->next;
		delete ptr;
	} else {
		delete ptr;
	}
}

template <class T>
void List<T>::set (int position, const T & val) {
	//Throw an exception if bad value given for exception
	if(position >= size()) {
		throw std::runtime_error(std::string("Indicated position is beyond size of list"));
	}

	//Move ptr until target position is reached
	Item<T>* ptr = head;
	for(int i = 0; i < position; i++) {
		ptr = ptr->next;
	}

	//Update value
	ptr->value = val;
}

template <class T>
T& List<T>::get (int position) const {
	//Throw an exception if bad value given for exception
	if(position >= size()) {
		throw std::runtime_error(std::string("Indicated position is beyond size of list"));
	}

	//Move ptr until position
	Item<T>* ptr = head;
	for(int i = 0; i < position; i++) {
		ptr = ptr->next;
	}

	//return ptr's value
	return ptr->value;
}

template <class T>
List<T>::List (const List<T> & other) {
	*this = other;
}

template <class T>
List<T>& List<T>::operator= (const List<T> & other) {
	if(this->head != NULL) {
		this->~List<T>();
	}
	int otherSize = other.size();
	for(int i = 0; i < otherSize; i++) {
		this->insert(this->size(), other.get(i));
	}
	return *this;
}