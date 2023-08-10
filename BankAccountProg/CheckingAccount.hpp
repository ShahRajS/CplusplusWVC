#pragma once
#include "BaseAccount.hpp"
class CheckingAccount : public BaseAccount {
private:
	double checkingFee;
public:
	CheckingAccount(double initialBalance, double checkingFee) : BaseAccount(initialBalance) {};
};

