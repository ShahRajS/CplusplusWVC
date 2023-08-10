#include <iostream>
#include <iomanip>
#include "BaseAccount.hpp"
#include "CheckingAccount.hpp"
#include "SavingsAccount.hpp"
using namespace std;

//Send email to counselor about meeting tomorrow 

int main()
{
    cout << "Raj Shah\t\tCIST004A\n";
    cout << std::fixed;
    cout << std::setprecision(2);

    BaseAccount base{ 100.04 };
    SavingsAccount savings{ 49.34, 3 };
    CheckingAccount checking{ 80.66, 2 };

    cout << "\nThe balance in your base account is: " << base.getBalance();
    cout << "\nThe balance in your savings account is: " << savings.getBalance();
    cout << "\nThe balance in your checking account is: " << checking.getBalance(); 

    cout << "\n\n--Testing Withdrawls--\n";
    cout << "Withdrawing $25.00 from Base Account.";
    base.withdraw(25.0);
    cout << "\nWithdrawing $50.00 from Savings Account.";
    savings.withdraw(50.0);
    cout << "\nWithdrawing $40.00 from Checking Account.";
    checking.withdraw(40.0);

    cout << "\n\nThe balance in your base account is: " << base.getBalance();
    cout << "\nThe balance in your savings account is: " << savings.getBalance();
    cout << "\nThe balance in your checking account is: " << checking.getBalance();

    cout << "\n\n--Testing Deposits--\n";
    cout << "Withdrawing $25.00 from Base Account.";
    base.deposit(25.0);
    cout << "\nWithdrawing $50.00 from Savings Account.";
    savings.deposit(50.0);
    cout << "\nWithdrawing $40.00 from Checking Account.";
    checking.deposit(40.0);

    cout << "\n\nThe balance in your base account is: " << base.getBalance();
    cout << "\nThe balance in your savings account is: " << savings.getBalance();
    cout << "\nThe balance in your checking account is: " << checking.getBalance();

    cout << "\n\n--Bank Account Interest Test--\n";
    cout << "Adding $" << savings.computeInterest() << " interest to savings account.";
    savings.deposit(savings.computeInterest());
    cout << "\nThe balance in your savings account is: " << savings.getBalance();

    return 0;
}