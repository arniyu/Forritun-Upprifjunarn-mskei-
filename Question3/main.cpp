#include <iostream>

using namespace std;

const int MAXSIZE = 8;
const int MINSIZE = 1;

int Prompt()
{
    int number;
    cout << "Input table size: ";
    cin >> number;
    return number;
}

bool ValidateNumber(int number)
{
    if(!(number <= MAXSIZE && number >= MINSIZE))
    {
        cout << "Invalid size!" << endl;
        return false;
    }
    return true;
}

void TopLine(int number)
{
    for(int i = 1; i <= number; i++)
    {
        cout << '\t' << i;
    }
    cout << endl;

    cout << "   " << '\t';
    for(int i = 1; i <= 8*number; i++)
    {
        cout << "-";
    }
    cout << endl;
}

void Table(int number)
{
    for(int i = 1; i <= number; i++)
    {
        cout << i << " |" << '\t';
        for(int j = 1; j <= number; j++)
        {
            cout << i*j << '\t';
        }
        cout << endl;
    }
}

int main()
{
    int number = Prompt();
    if(ValidateNumber(number) == false)
    {
        return 0;
    }
    TopLine(number);
    Table(number);



    return 0;
}
