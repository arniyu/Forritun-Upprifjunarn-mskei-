#include <iostream>
#include "BankAccount.h"

using namespace std;

int main()
{
    BankAccount account;
    account.readData();
    cout << account;
    account.update();
    cout << account;
    if (account.withdraw(32.5)) {
        cout << "Amount withdrawn for account " << account.getNumber() << endl;
    }
    else {
        cout << "Unable to withdraw from account " << account.getNumber() << endl;
    }
    cout << endl << account;
    return 0;
}


