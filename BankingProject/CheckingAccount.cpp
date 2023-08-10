#include "CheckingAccount.hpp"
#include <iostream>
#include "BaseAccount.hpp"


CheckingAccount::CheckingAccount(double initialBalance, double checkingFee) : BaseAccount(initialBalance) {
	CheckingAccount::checkingFee = checkingFee;
}

void CheckingAccount::deposit(double amount) {
	BaseAccount::deposit(amount - checkingFee);
	std::cout << "\n$" << checkingFee << " checking account transaction fee charged";
}

bool CheckingAccount::withdraw(double amount) {
	if (BaseAccount::withdraw(amount)) {
		BaseAccount::withdraw(checkingFee);
		std::cout << "\n$" << checkingFee << " checking account transaction fee charged";
		return true;
	}
	return false;
}