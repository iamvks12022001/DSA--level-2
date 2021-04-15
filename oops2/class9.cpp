#include<bits/stdc++.h>
using namespace std;


class DynamicArray {
	int *data;
	int nextIndex;
	int capacity;			// total size

	public :

	DynamicArray() {
		data = new int[5]; //intializing the array size and index;
		nextIndex = 0;
		capacity = 5;
	}
// to do deep copy in copy constructor
	DynamicArray(DynamicArray const &d) {
		//this -> data = d.data;		// Shallow copy
		
		// Deep copy for data so that data point to newly created  array
		this -> data = new int[d.capacity];
		for(int i = 0; i < d.nextIndex; i++) {
			this -> data[i] = d.data[i];
		}
		this -> nextIndex = d.nextIndex;
		this -> capacity = d.capacity;
	}

// to do deep copy in copy assignment operator by overloading = operator
	void operator=(DynamicArray const &d) {
		this -> data = new int[d.capacity];
		for(int i = 0; i < d.nextIndex; i++) {
			this -> data[i] = d.data[i];
		}
		this -> nextIndex = d.nextIndex;
		this -> capacity = d.capacity;
	}


	void add(int element) {
		if(nextIndex == capacity) {
			int *newData = new int[2 * capacity];
			for(int i = 0; i < capacity; i++) {
				newData[i] = data[i];
			}
			delete [] data;
			data = newData;
			capacity *= 2;
		}
		data[nextIndex] = element;
		nextIndex++;
	}

	int get(int i) const {  //get function can be make constant function
		if(i < nextIndex) {
			return data[i];
		}
		else {
			return -1;
		}
	}

	void add(int i, int element) { //adding element from [0 to nextindex]
			if(i < nextIndex) {
				data[i] = element;
			}
			else if(i == nextIndex) {
				add(element);
			}
			else {
				return;
			}
	}

	void print() const { // print function can be make constant function
		for(int i = 0; i < nextIndex; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}


};



int main() {
	DynamicArray d1;

	d1.add(10);
	d1.add(20);
	d1.add(30);
	d1.add(40);
	d1.add(50);
	d1.add(60);

	d1.print();

	DynamicArray d2(d1);		// Copy constructor
                                //copy constructor always make shallow copy that is not make new array
                                //so whenever we change in d1 it also make chnages in d2 as well
                                 //so we have to make our own copy constructor so that we do deep copy not shallow copy(as in default copy construtor)

	DynamicArray d3; //this is copy assignment operator who also do shallow copy alaways

	d3 = d1;

	d1.add(0, 100);

	d2.print();
	d3.print();
}

