// Binary_search_Recursive.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Binary Search -Recursive
/*Name: Mansi joshi
* Roll no: 2019/102
* Course: BSc Physical Science
* Subject : Analysis of Algorithm
*/ 

/* Time Complexity :
* Best case : O(1)
* Worst case : O(logn)
* Average case : O(logn)
*/

#include <iostream>;
using namespace std;

// user defined functions
int Binary_search(int arr[], int f, int l, int e);
void Get_Sorted(int arr[], int size);

// main function
int main()
{
	int n;
	cout << "Enter the size of array :";
	cin >> n;
	int* arr = new int[n];
	// taking input of elements
	for (int i = 0; i < n; i++) {
		cout << "Enter the element " << i + 1 << " : ";
		cin >> arr[i];
	}
	Get_Sorted(arr, n);
	cout << "Given Array" << endl;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	int ele;
	cout << "\nEnter the element to be search : ";
	cin >> ele;
	int index = Binary_search(arr, 0, n - 1, ele);
	if (index == -1) {
		cout << "Element not found !!!";
	}
	else {
		cout << "Element found at index " << index;
	}
	return 0;
}

// function to sort the elements if not sorted
void Get_Sorted(int arr[], int size) {
	int i, j, key;
	for (i = 1; i < size; i++) {
		key = arr[i];
		j = i - 1;
		while ((j >= 0) && (arr[j] > key)) {
			arr[j + 1] = arr[j]; //shift towards right
			j -= 1;
		}
		arr[j + 1] = key;
	}
}

// function to perform binary search
int Binary_search(int arr[], int f, int l, int e) {
	int mid = (f + l) / 2;
	if (arr[mid] == e) {
		return mid + 1;
	}
	if (f > l) {
		return -1;
	}
	if (arr[mid] > e) {
		return Binary_search(arr, f, mid - 1, e);
	}
	if (arr[mid] < e) {
		return Binary_search(arr, mid + 1, l, e);
	}
}

