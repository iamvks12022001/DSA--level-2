#include <iostream>
#include <vector>
using namespace std;
// vector is inbuilt dynamic array
int main() {
	//vector<int> * vp = new vector<int>(); ( dynamically allocated vector)
	vector<int> v; //we have to use template as well (staticale vector)


//size inc lineraly i.e from 1->->3->4....
//capacity inc 2 time each time after capacity==size
//capacity bydefult start from 0 (when vector is not initilize with any value)
//and after adding 1 st element capacity become 1 and after that it become twice when
// we try to add element after capacity ==size

	for (int i = 0; i < 100; i++) {
		cout << "cap:" << v.capacity() << endl;
		cout << "size:" << v.size() << endl;
		v.push_back(i + 1);
	}

	v.push_back(10);
	v.push_back(20);
	v.push_back(30);

	v[1] = 100; //we can updated the value but not add the value

	// dont use [] for inserting elements
	//v[3] = 1002;
	//v[4] = 1234;

	v.push_back(23);
	v.push_back(234);
   //v.insert(v.begin(),90);  insert in front
    
	v.pop_back(); // to delete last element
 //   v.erase(v.begin()); // to delete front element

	/*
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << endl;
	}


	cout << v[0] << endl;
	cout << v[1] << endl;
	cout << v[2] << endl;
	cout << v[3] << endl;
	cout << v[4] << endl;
	cout << v[5] << endl;
	cout << v[6] << endl;

	cout << "Size: " << v.size() << endl;

	cout << v.at(2) << endl;
	cout << v.at(6) << endl;
	*/

 // note v.at(index) is safer than v[index] bcz if index is out of range than .at() wala error dega but v[] wala nhi
}
