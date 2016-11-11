#include <iostream>
using namespace std;
/*
This program asks the user to type N integers into an dynamically allocated array.
The program then sorts the array using the Bubble Sort algorithm.
The program writes the sorted array to the screen.
*/

typedef int* IntPtr;

int getNumber();
void populate(IntPtr arr, int len);
void bubbleSort(IntPtr arr, int len);
void swap(int& num1, int& num2);
void displayArray(IntPtr arr, int len);

int main()
{
    int mySize = getNumber();
    IntPtr myArray = new int[mySize];
    populate(myArray, mySize);
    bubbleSort(myArray, mySize);
    displayArray(myArray, mySize);
}

int getNumber()
{
    int number;
    cout << "Array size: ";
    cin >> number;
    return number;
}

void populate(IntPtr arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        int number;
        cin >> number;
        arr[i] = number;
    }
}

void swap(int& num1, int& num2)
{
    int tmp = num1;
    num1 = num2;
    num2 = tmp;
}

void bubbleSort(IntPtr arr, int len) {
    bool swapped;
    do
    {
        swapped = false;
        for (int i = 1; i < len; i++) {
            if (arr[i-1] > arr[i]) {
                swap(arr[i-1], arr[i]);
                swapped = true;
            }
        }
    } while (swapped);
}

void displayArray(IntPtr arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        cout << arr[i] << endl;
    }
}
