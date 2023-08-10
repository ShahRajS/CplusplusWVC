#pragma once
#include "BaseAccount.hpp"
class SavingsAccount : public BaseAccount {
private:
	double interestRate;
public:
	SavingsAccount(double initialBalance, double initialRate);
	double computeInterest();
};

