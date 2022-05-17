// Bubble_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Bubble Sort

#include <iostream>
using namespace std;

//user - defined functions
void Swap(int *x, int *y);
void ShowPass(int arr[], int size);
void bubbleSort(int arr[], int size);

//main function
int main()
{
    cout << "Bubble sort" << endl;
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
    bubbleSort(arr, n);
    cout << "-------------------------------" << endl;
    cout << "Sorted array : ";
    ShowPass(arr, n);
}

// function for swapping 
void Swap(int *x, int *y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

// function for printing the array elements
void ShowPass(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

// function to perform Bubble sort
void bubbleSort(int arr[], int size) {
    int i, j;
    bool isSwap; // to check the swapping 
    for (i = 0; i < size; i++) {
        isSwap = false;
        for (j =0 ; j < size-i-1; j++) {
            if (arr[j] > arr[j + 1]) {  
                Swap(&arr[j], &arr[j + 1]);
                isSwap = true;
            }
        }
        if (isSwap == false) {
            break;
        }
        cout << i + 1 << " pass : " << endl;
        ShowPass(arr, size);
        cout << endl;
    }
}