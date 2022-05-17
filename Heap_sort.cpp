// Heap_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Implementation of Heap Sort

#include <iostream>
using namespace std;

// user defined functions
void HeapSort(int arr[], int size);
void Heapify(int arr[],int size,int i);
void ShowPass(int arr[], int size);
void Swap(int* x, int* y);

// Global variable
int comp = 0;

// main function
int main()
{
    cout << "Heap sort" << endl;
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
    HeapSort(arr, n);
    cout << "-------------------------------" << endl;
    cout << "Sorted array : ";
    ShowPass(arr, n);
    cout << "\n Number of comparisions : " << comp;
    
}

// function for Heap Sort
void HeapSort(int arr[], int size) {

    // Build heap (rearrange array)
    for (int i = (size / 2) - 1; i >= 0; i--) {
        Heapify(arr, size, i);
    }
    // extract element from heap
    for (int i = size - 1; i > 0; i--) {
        // moving current root to end
        Swap(&arr[0], &arr[i]);
        // calling heapify function for reduced heap
        Heapify(arr, i, 0);
    }
}

// function : To Heapify the array
void Heapify(int arr[], int size, int i) {
    int large = i; // intially largest as root
    int left = 2 * i + 1; // left child of root i
    int right = 2 * i + 2; // right child of root i

    // if left child is larger than root
    if (left<size && arr[left]>arr[large]) {
        large = left;
    }

    // if right child is larger than root
    if (right<size && arr[right]>arr[large]) {
        large = right;
    }

    // if large is not root
    if (large != i) {
        Swap(&arr[i], &arr[large]);

        // recursively call the heapify function
        Heapify(arr, size, large);
    }
    comp++;
}

// function to show the elements of array
void ShowPass(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// function for swapping 
void Swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}