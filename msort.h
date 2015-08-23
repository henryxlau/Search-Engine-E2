#ifndef MSORT_H
#define MSORT_H

//Necessary includes
#include <vector>

using namespace std;

template <class T, class Comparator>
class mSort {
	public:
		mSort();
		~mSort();
	  	void mergeSort (vector<T> * myArray, Comparator comp);
	  	vector<T> * merge (vector<T> * arrayPiece, Comparator comp);


	private:
		void swap(vector<T> * arr, int pos1, int pos2);
		int midpoint(vector<T> * source);
		vector<T> * lHalf(vector<T> * source);
		vector<T> * rHalf(vector<T> * source);
		vector<T> * combine(vector<T> * vector1, vector<T> * vector2, Comparator comp);


	protected:


};

template <class T, class Comparator>
mSort<T, Comparator>::mSort() {

}

template <class T, class Comparator>
mSort<T, Comparator>::~mSort() {
	
}

template <class T, class Comparator>
void mSort<T, Comparator>::mergeSort(vector<T> * myArray, Comparator comp) {
	vector<T> * newArray = merge(myArray, comp);
	for(int i = 0; i < newArray->size(); i++) {
		myArray->at(i) = newArray->at(i);
	}
}

template <class T, class Comparator>
vector<T> * mSort<T, Comparator>::merge(vector<T> * arrayPiece, Comparator comp) {

	if(arrayPiece->size() == 2) {
		if(!comp(arrayPiece->at(0),arrayPiece->at(1))) {
			swap(arrayPiece, 0, 1);
		}
		return arrayPiece;
	} else if(arrayPiece->size() == 1) {
		return arrayPiece;
	} else {
		return combine(merge(lHalf(arrayPiece), comp), merge(rHalf(arrayPiece), comp), comp);
	}
}

template <class T, class Comparator>
vector<T> * mSort<T, Comparator>::combine(vector<T> * vector1, vector<T> * vector2, Comparator comp) {



	vector<T> * returnVector = new vector<T>();
	int size1 = vector1->size();
	int size2 = vector2->size();

	int index1 = 0;
	int index2 = 0;

	while(index1 != size1 && index2 != size2) {
		if(comp(vector1->at(index1), vector2->at(index2))) {
			returnVector->insert(returnVector->end(), vector1->at(index1));
			index1++;
		} else {
			returnVector->insert(returnVector->end(), vector2->at(index2));
			index2++;
		}
	}

	while(index1 != size1) {
		returnVector->insert(returnVector->end(), vector1->at(index1));
		index1++;
	}

	while(index2 != size2) {
		returnVector->insert(returnVector->end(), vector2->at(index2));
		index2++;
	}


	delete vector1;
	delete vector2;
	return returnVector;
}

template <class T, class Comparator>
vector<T> * mSort<T, Comparator>::lHalf(vector<T> * source) {
	std::vector<T> * leftHalf = new vector<T>();
	for(int i = 0; i < midpoint(source); i++) {
		leftHalf->insert(leftHalf->end(), source->at(i));
	}

	return leftHalf;
}

template <class T, class Comparator>
vector<T> * mSort<T, Comparator>::rHalf(vector<T> * source) {
	std::vector<T> * rightHalf = new vector<T>();
	for(int i = midpoint(source); i < source->size(); i++) {
		rightHalf->insert(rightHalf->end(), source->at(i));
	}

	return rightHalf;
}

template <class T, class Comparator>
int mSort<T, Comparator>::midpoint(vector<T> * source) {
	return source->size()/2;
}

template <class T, class Comparator>
void mSort<T, Comparator>::swap(vector<T> * arr, int pos1, int pos2) {
	T temp = arr->at(pos1);
	arr->at(pos1) = arr->at(pos2);
	arr->at(pos2) = temp;
}



#endif