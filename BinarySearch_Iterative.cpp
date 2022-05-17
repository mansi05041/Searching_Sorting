// BinarySearch_Iterative.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Binary Search : Iterative

#include <iostream>;
using namespace std;
int Binary_search(int arr[], int f, int l, int e);
void Get_Sorted(int arr[], int size);
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
    int first = 0;
    Get_Sorted(arr, n);
    cout << "Given Array" << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    int ele;
    cout << "\nEnter the element to be search : ";
    cin >> ele;
    int index = Binary_search(arr, first, n-1, ele);
    if (index == -1) {
        cout << "Element is not found";
    }
    else {
        cout << "Element is found at " << index << " position";
    }
    return 0;
}
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
int Binary_search(int arr[], int f, int l, int e) {
    int mid = 0;
    do {
        int mid = (f + l) / 2;
        //case 1: middle element = search
        if (arr[mid] == e) {
            return mid + 1;
        }
        //case 2: middle element > search
        else if (arr[mid] > e) {
            l = mid - 1;
        }
        //case 3: middle element < search
        else {
            f = mid + 1;
        }
    } while (arr[mid] != e || f <= l);
    if (f > l) {
        cout << "Element not found";
    }
}
