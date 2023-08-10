#pragma once
#include "BaseAccount.hpp"
class CheckingAccount : public BaseAccount {
private:
	double checkingFee;
public:
	CheckingAccount(double initialBalance, double checkingFee);
	void deposit(double amount);
	bool withdraw(double amount);
};

