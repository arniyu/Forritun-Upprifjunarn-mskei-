#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <iostream>
#include <string>
using namespace std;

class BankAccount
{


    public:
        BankAccount();
        ~BankAccount();

        void readData();
        void update();
        bool withdraw(double amount);
        double getNumber();

        friend ostream& operator << (ostream& os, const BankAccount& ba);

    private:
        string name;
        int number;
        double balance;
        double intrest;

        double convertInterest(double intrests);
};

#endif // BANKACCOUNT_H
