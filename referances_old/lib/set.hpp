
template <class T>
Set<T>::Set() {
	iter = 0;
}

template <class T>
Set<T> Set<T>::setIntersection (const Set<T> & other) const {
	Set<T>* intersection = new Set<T>();
	int setSize = set<T>::size();
	typename set<T>::iterator it = set<T>::begin();
	for(int i = 0; i < setSize; i++) {
		T item = *it;
		++it;
		if(other.contains(item)) {
			std::cerr << "Commonality found" << std::endl;
			intersection->insert(intersection->end(), item);
		}
	}
	return *intersection;
}

template <class T>
Set<T> Set<T>::setUnion (const Set<T> & other) const {
	Set<T>* theUnion = new Set<T>(other);
	int setSize = set<T>::size();
	typename set<T>::iterator it = set<T>::begin();
	for(int i = 0; i < setSize; i++) {
		T item = *it;
		++it;
		if(!other.contains(item)) {
			theUnion->insert(theUnion->end(),item);
		}
	}
	return *theUnion;
}

// template <class T>
// T* Set<T>::first () {
// 	if(!set<T>::isEmpty()) {
// 		return set<T>::begin();
// 	} else {
// 		return NULL;
// 	}
// }

// template <class T>
// T* Set<T>::next () {
// 	if(iter < set<T>::size()) {
// 		typename set<T>::iterator it = set<T>::begin();
// 		for(int i = 0; i < iter; i++) {
// 			++it;
// 		}
// 		T* retVal = &(*it);
// 		return retVal;
// 	} else {
// 		return NULL;
// 	}
// }

template <class T>
bool Set<T>::contains(T element) const {
	return !(set<T>::find(element) == set<T>::end());
}