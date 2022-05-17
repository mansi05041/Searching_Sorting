//LinearSearch.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Linear Search 


/*Time Complexity
* Best case : O(1)
* Worst case: O(n)
* Average case: O(n)
*/

#include <iostream>
using namespace std;

// main function
int main()
{
	int n, ele, i;
	cout << "Enter the size of array : ";
	cin >> n;
	int* arr = new int[n];
	//taking input of elements of array
	for (i = 0; i < n; i++) {
		cout << "Enter the element " << i + 1 << " : ";
		cin >> arr[i];
	}
	cout << "Enter the element to be search : ";
	cin >> ele;

	// loop for finding the element in array
	for (i = 0; i < n; i++) {
		if (arr[i] == ele) {
			cout << "Element found in array at position " << i + 1;
			break;
		}
	}
	if (i == n) {
		cout << "Element is not found";
	}
	return 0;
}

