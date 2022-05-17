// Insertion_Sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Insertion Sort Implementation & Report the number of Comparisons
// Name : mansi joshi
// Roll no : 2019/102
// Analysis of Algorithm ( practical )

// Algorithm of insertion sort
/* Spliting the array into sorted and unsorted array
 * Assume the first element is sorted and mark next element as key.
 * Compare current key with previous element , if key is smaller than previous element 
   then shift the previous element to key place. 
 * if sorted array index get out of the bound , then place key value at 0 th index
 * then key value updated and the process repeat the same.
*/

// Time complexity of insertion sort
/* Best case : O(n)
*  Average case : O(n^2)
*  Worst case : O(n^2)
*/

// control movement of program
// main --> insertionSort --> main

#include <iostream>
using namespace std;

// user-defined functions
void ShowPass(int arr[], int size);
void insertionSort(int arr[], int size);

// global variables
int comp = 0;

// main - function
int main()
{
    cout << "Insertion sort" << endl;
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
    insertionSort(arr, n);
    cout << "-------------------------------" << endl;
    cout << "Sorted array : ";
    ShowPass(arr, n);
    cout << "\nNumber of comparisons : " << comp;
}  

//function to show the pass
void ShowPass(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

//function for insertion sorting
void insertionSort(int arr[], int size) {
    int i, j, key;
    for (i = 1; i < size; i++) {
        key = arr[i];
        j = i - 1;
        while ((j >= 0) && (arr[j] > key)) {
            arr[j + 1] = arr[j]; //shift towards right
            j -= 1;
            comp += 1; // increment for checking comparision count
        }
        arr[j + 1] = key;
        cout << i << " pass : " << endl;
        ShowPass(arr, size);
        cout << endl;
    }
}