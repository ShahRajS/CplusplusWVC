#include "SavingsAccount.hpp"
#include "BaseAccount.hpp"

SavingsAccount::SavingsAccount(double initialBalance, double initialRate) : BaseAccount(initialBalance) {
	SavingsAccount::interestRate = initialRate;
};

double SavingsAccount::computeInterest() {
	return getBalance() * (interestRate / 100.0);
}