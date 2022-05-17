// Merge_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// implemetation of merge sort and report number of comparisons
// name : mansi joshi
// roll no : 2019/102
// Analysis of Algorithm

// Algorithm for Merge Sort
/*It is a divide and conquer algorithm
* It divides input array into two halves, 
  then another halves itself divides into halves recursively.
* Then merges two sorted array until we get resulted array.
* In function mergeSort we find middle element and then call mergesort recursively for another two halves
* Then we call merge function to merge the sorted array.
*/

// Time complexity 
/* In best case : O(n*logn)
*  In average case : O(n*logn)
*  In Worst case : O(n*logn)
*/

// control movement in program
// main --> mergeSort --> merge --> main
 
// Program implementation for merge sort
#include <iostream>
using namespace std;

// global variables 
int comp = 0; // count the number of comparisions

// user-defined functions
void ShowPass(int arr[], int size);
void merge(int arr[], int  l, int m, int r);
void mergeSort(int arr[], int l, int r);

// main function
int main()
{
	cout << "Merge sort" << endl;
	int n;
	cout << "Enter the size of array :";
	cin >> n;
	int* arr = new int[n];
	// taking input of elements
	for (int i = 0; i < n; i++) {
		cout << "Enter the element " << i + 1 << " : ";
		cin >> arr[i];
	}

	cout << "Unsorted array: ";
	ShowPass(arr, n);
	cout << endl << "-------------------------------" << endl;
	mergeSort(arr, 0, n - 1); // 0 is the starting index and n-1 is end index
	cout << "-------------------------------" << endl;
	cout << "Sorted array : ";
	ShowPass(arr, n);
	cout << "\n Number of comparisions : " << comp;
	return 0;
}

// function for printing the array elements
void ShowPass(int arr[], int size) {
	int i;
	for (i = 0; i < size; i++) {
		cout << arr[i] << " ";
	}
}

// function recursively calls to break the array into halves
// calls merge function for resulted sorted array
// l is for left index and r is right index of the sub-array of arr to be sorted 
void mergeSort(int arr[], int l, int r)
{
	if (l >= r)
		return; // Returns recursively

	int mid = l + (r - l) / 2;
	mergeSort(arr, l, mid);
	mergeSort(arr, mid + 1, r);
	merge(arr, l, mid, r);
}

// function for merging the arrays recursively to get the resulted sorted array
// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void merge(int arr[], int l, int m, int r)
{
	int n1 = m - l + 1; // index of first sub array (left)
	int n2 = r - m; // index of second sub array (right)

	// Create temp arrays
	int* leftArr = new int[n1];
	int* rightArr = new int[n2];

	// Copy data to temp arrays leftArray[] and rightArray[]
	for (int i = 0; i < n1; i++)
		leftArr[i] = arr[l + i];
	for (int j = 0; j < n2; j++)
		rightArr[j] = arr[m + 1 + j];

	int j = 0; // Initial index of first sub-array ( denote with j )
	int	k = 0; // Initial index of second sub-array ( denote with k )
	int merge_index = l; // Initial index of merged array , that is left ( denote with merge_index )

	// Merge the temp arrays back into array[left..right]
	while (j < n1 && k < n2) {
		if (leftArr[j] <= rightArr[k]) {
			arr[merge_index] = leftArr[j];
			j++;
		}
		else {
			arr[merge_index] = rightArr[k];
			k++;
		}
		merge_index++;
		comp++;
	}

	// Copy the remaining elements of leftArr[], if there are any
	while (j < n1) {
		arr[merge_index] = leftArr[j];
		j++;
		merge_index++;
	}

	// Copy the remaining elements of rightArr[], if there are any
	while (k < n2) {
		arr[merge_index] = rightArr[k];
		k++;
		merge_index++;
	}
}
