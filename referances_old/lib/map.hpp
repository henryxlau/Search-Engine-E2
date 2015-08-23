template <class keyType, class valueType>
Map<keyType, valueType>::Map() {
	//This constructor just sets up a List
	internalStorage = List< MapItem<keyType, valueType> >();
}


template <class keyType, class valueType>
Map<keyType, valueType>::~Map() {
	int size = internalStorage.size();
	for(int i = 0; i < size; i++) {
	//	delete &(internalStorage.get(0)); //steps through internalStorage deleting every MapItem inside it
		internalStorage.remove(0);
	}
	//Calls destructor for internalStorage to free up Item<T>s 
	internalStorage.~List();
}

template <class keyType, class valueType>
int Map<keyType, valueType>::size () const {
	//Simply returns internalStorage's size (it calls List.size())
	return internalStorage.size();
}


template <class keyType, class valueType>
void Map<keyType, valueType>::add (const keyType & key, const valueType & value) {
	//Creates an addition to be added, passed by object but this is ok because it is copied
	MapItem<keyType, valueType> addition;
	try {
		get(key); //We use try here, hoping that the key is unassociated (which would raise an exception)
	}
	catch (const std::runtime_error &e) {
		//If said exception is raised, then key was not
		//found and thus we are free to create an item associated with that key
		addition.value = value;
		addition.key = key;
		//Try to add it, setting up handling for the standard errors thrown by list.insert()
		try {
			internalStorage.insert(internalStorage.size(), addition);
		}
		catch (const std::runtime_error& e) {
			std::cerr << e.what();
		}
		return;		//This return statement prevents control from reaching the throw() at the end of the function
	}
	//If the first try statement did not raise an exception, then get(key) returned a value,
	//meaning that the key was already in use. This would cause control to arrive here, causing
	//an exception to be thrown.
	throw(std::runtime_error(std::string("Key already has an association.")));
}

template <class keyType, class valueType>
void Map<keyType, valueType>::remove (const keyType & key) {
	//Run through list, searching for MapItem with matching key, remove when found.
	for(int i = 0; i < internalStorage.size(); i++) {
		MapItem <keyType, valueType> item = internalStorage.get(i);
		if (item.key == key) {
			internalStorage.remove(i);
			return; //This return statement prevents control from reaching the throw() statement at the end of the function
		}
	}
	//Throw this because the key was never matched with an item
	throw(std::runtime_error(std::string("Nothing to remove that is associated with provided key.")));
}

template <class keyType, class valueType>
valueType& Map<keyType, valueType>::get (const keyType & key) const {
	//Run through loop looking for matching key, retrieve value and return
	for(int i = 0; i < internalStorage.size(); i++) {
		MapItem<keyType, valueType>* itemPtr = &(internalStorage.get(i));
		if (itemPtr->key == key) {
			return itemPtr->value;
		}
	}
	//Throw exception if control ran through for loop without finding an associated key
	throw (std::runtime_error(std::string("Value not found that is associated with that key")));
}
