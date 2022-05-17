// Selection_sort.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Selection sort

#include <iostream>
using namespace std;

//user-defined functions
void Swap(int* x, int* y);
void ShowPass(int arr[], int size);
void selectionSort(int arr[], int size);

//main function
int main()
{
    cout << "Selection sort" << endl;
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
    selectionSort(arr, n);
    cout << "-------------------------------" << endl;
    cout << "Sorted array : ";
    ShowPass(arr, n);
    return 0;
}

//function to swap the elements
void Swap(int* x, int* y) {
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

//function to show the pass
void ShowPass(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
}

//function for selection sorting
void selectionSort(int arr[], int size) {
    int i, j, min;
    for (i = 0; i < size; i++) {
        min = i;
        for (j = i + 1; j < size; j++) {
            if (arr[min] > arr[j]) {
                min = j;
            }
        }
        if (min != i) {
            Swap(&arr[min], &arr[i]);
            cout << i + 1 << " pass :";
            ShowPass(arr, size);
            cout << endl;
        }
        else {
            break;
        }
    }
}
