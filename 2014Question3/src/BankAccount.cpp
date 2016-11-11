#include "BankAccount.h"

BankAccount::BankAccount()
{
    //ctor
}

BankAccount::~BankAccount()
{
    //dtor
}

void BankAccount::readData()
{
    cin >> name;
    cin >> number;
    cin >> balance;
    cin >> intrest;
}

void BankAccount::update()
{
    double ci = convertInterest(intrest);
    balance = ci * balance;
}

bool BankAccount::withdraw(double amount)
{
    if(amount <= balance)
    {
        balance = balance - amount;
        return true;
    }
    return false;
}

double BankAccount::getNumber()
{
    return number;
}

double BankAccount::convertInterest(double intrests)
{
    return (intrests / 100) + 1;
}

ostream& operator << (ostream& os, const BankAccount& ba)
{
    os << "Customer name: " << ba.name << endl;
    os << "Customer number: " << ba.number << endl;
    os << "Balance: " << ba.balance << endl;
    os << "Interest rate: " << ba.intrest << endl;
    return os;
}
