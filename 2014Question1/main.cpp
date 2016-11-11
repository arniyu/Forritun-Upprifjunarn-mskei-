#include <iostream>

using namespace std;

int GetValue()
{
    int number;
    cout << "Input value: " << endl;
    cin >> number;
    return number;
}

int MinValue(int num1, int num2)
{
    if(num1 > num2)
    {
        return num2;
    }
    else
    {
        return num1;
    }
}

int main()
{

    int num1 = GetValue();
    int num2 = GetValue();
    int ans = MinValue(num1, num2);

    cout << "Min value is: " << ans << endl;

    return 0;
}
