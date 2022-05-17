// Quick_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Implement Quick Sort
/*
* Your Full Name: Mansi Joshi
* College Roll Number/ Year of Admission: 102/2019
*/

#include <iostream>
using namespace std;

//user-defined functions
void QuickSort(int arr[], int low, int high);
void ShowPass(int arr[], int n);
int partition(int arr[], int low, int high);
void Swap(int* x, int* y);

// main - function
int main()
{
    cout << "Quick sort" << endl;
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
    QuickSort(arr,0,n-1); // 0 is the starting index and n-1 is end index
    cout << "-------------------------------" << endl;
    cout << "Sorted array : ";
    ShowPass(arr, n);
    return 0;
}

// function for printing the array elements
void ShowPass(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

// function to perform quick sort
void QuickSort(int arr[], int low,int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi - 1); //before pi
        QuickSort(arr, pi + 1, high); //after pi
    }
}

// function for partition
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; // pivot - element to be placed at right position
    int i = low - 1; // index of smaller element and indicates the right position of pivot 
    for (int j = low; j <= high - 1; j++) {
        // if current element is smaller than the pivot 
        if (arr[j] < pivot) {
            i++; // increment the index of smaller element 
            Swap(&arr[i], &arr[j]);
        }
    }
    Swap(&arr[i + 1], &arr[high]);
    return(i + 1);
}

// function for swapping 
void Swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
