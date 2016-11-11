#include <iostream>

using namespace std;

string Prompt()
{
    string str;
    char letter;
    cout << "Enter up to 10 letters followed by a period: ";
    for(int i = 0; i < 10; i++)
    {
        cin >> letter;
        if(letter == '.')
        {
            return str;
        }
        str += letter;
    }
    return str;
}

string ReverseString(string str)
{
    string ans;
    for(int i = str.length() -1; i >= 0; i--)
    {
        ans += str[i];
    }
    return ans;
}

int main()
{
    string str = Prompt();
    cout << ReverseString(str) << endl;
    return 0;
}
