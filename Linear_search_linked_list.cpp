// Linear_search_linked_list.cpp : This file contains the 'main' function. Program execution begins and ends there.
// To search an element using linear search in a linked list

#include <iostream>
using namespace std;

// user defined functions
void insert_node(int ele);
void display();
void search(int ele);

// class declaration for node
class node {

public:
    int data;
    node* next;

    // constructor of class node
    node(int ele) {
        data = ele;
        next = NULL;
    }

};

// gloabal variable
node* start;

// main-function
int main()
{
    // variable declaration
    int num, i, ele, search_ele;
    
    cout << "Number of elements wanted to insert in linked list : ";
    cin >> num;
    cout << "\nEnter the numbers \n";
    for (i = 0; i < num; i++) {
        cin >> ele;
        insert_node(ele); // calling function to insert node
    }
    cout << "The Elements in the linked list  : \n";
    display(); // calling function to display linked list
    cout << "\nEnter the number to find in linked list : ";
    cin >> search_ele;
    search(search_ele); // calling function to search the element 
    return 0;
}

// function to insert an element into new node
void insert_node(int ele) {
    node* temp;
    temp = start;
    node* newnode = new node(ele); // creating a new node
    if (start == NULL) {
        start = newnode; // if it is first node
    }
    else {
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newnode; // store the temp address into last node address part
    }
}

// function to display the linked list
void display() {
    if (start == NULL) {
        cout << "\nList is empty" << endl;
    }
    else {
        node* temp = start;
        while (temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
}

// function to search an element using linear search techcinque
void search(int ele) {
    if (start == NULL) {
        cout << "\n list is empty";
    }
    else {
        node* temp = start;
        int pos = 1; // keep check at position
        int flag = 0; // for getting status
        while (temp != NULL) {
            if (temp->data == ele) {
                cout << "\nElement found at " << pos << " position";
                flag = 1;
                break;
            }
            else {
                temp = temp->next; // moves to next list
                pos += 1; // increment the position value
            }
        }
        if (temp == NULL && flag == 0) {
            cout << "\nElement not found";
        }
    }
}
