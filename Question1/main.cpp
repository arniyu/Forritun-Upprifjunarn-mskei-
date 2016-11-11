#include <iostream>

using namespace std;

const int SIZE = 6;

void readNumbers(int myArray[], int &number)
{

    for(int i = 0; i < SIZE; i++)
    {
        cin >> number;
        myArray[i] = number;
    }
}

int sumOfEven(int myArray[])
{
    int total = 0;
    for(int i = 0; i < SIZE; i++)
    {
        if(myArray[i] % 2 == 0)
        {
            total += myArray[i];
        }
    }
    return total;
}

int main()
{
    int number = 0;
    int myArray[SIZE];

    readNumbers(myArray, number);
    cout << sumOfEven(myArray) << endl;
    return 0;
}
